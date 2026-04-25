/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_slice_tests.c                                :::      ::::::::   */
/*                                                    :-:       :-:   :-:      */
/*   By: opencode <opencore@student.42abudhabi.ae>   ::::   :::::: ::::       */
/*                                                ..######::###::###::####..   */
/*   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              */
/*   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static void test_slice_single_axis(void)
{
    t_tensr *t;
    t_tensr *sliced;
    t_slice s = {0, 1, 3, 1};

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 0.0; data[1] = 1.0; data[2] = 2.0; data[3] = 3.0; data[4] = 4.0;

    sliced = tensr_slice(t, 1, &s);
    assert(sliced);
    assert(sliced->size == 2);
    data = (double *)sliced->data;
    assert(data[0] == 1.0);
    assert(data[1] == 2.0);

    tensr_free(t);
    tensr_free(sliced);
}

static void test_slice_2d_tensor(void)
{
    t_tensr *t;
    t_tensr *sliced;
    t_slice s[2] = {{0, 0, 2, 1}, {1, 0, 3, 1}};
    size_t idx[2];

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    double *data = (double *)t->data;
    int i = 0;
    while (i < 12)
    {
        data[i] = (double)i;
        i++;
    }

    sliced = tensr_slice(t, 2, s);
    assert(sliced);
    assert(sliced->layout.ndim == 2);
    assert(sliced->layout.shape[0] == 2);
    assert(sliced->layout.shape[1] == 3);

    idx[0] = 0; idx[1] = 0;
    assert(*(double *)tensr_get(sliced, idx) == 0.0);
    idx[0] = 0; idx[1] = 1;
    assert(*(double *)tensr_get(sliced, idx) == 1.0);
    idx[0] = 0; idx[1] = 2;
    assert(*(double *)tensr_get(sliced, idx) == 2.0);
    idx[0] = 1; idx[1] = 0;
    assert(*(double *)tensr_get(sliced, idx) == 4.0);
    idx[0] = 1; idx[1] = 1;
    assert(*(double *)tensr_get(sliced, idx) == 5.0);
    idx[0] = 1; idx[1] = 2;
    assert(*(double *)tensr_get(sliced, idx) == 6.0);

    tensr_free(t);
    tensr_free(sliced);
}

static void test_slice_negative_step(void)
{
    t_tensr *t;
    t_tensr *sliced;
    t_slice s = {0, 4, 0, 0};

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 0.0; data[1] = 1.0; data[2] = 2.0; data[3] = 3.0; data[4] = 4.0;

    sliced = tensr_slice(t, 1, &s);
    assert(!sliced);

    tensr_free(t);
}

static void test_slice_full_range(void)
{
    t_tensr *t;
    t_tensr *sliced;
    t_slice s = {0, 0, 5, 1};

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    ((double *)t->data)[0] = 1.0;
    ((double *)t->data)[4] = 5.0;

    sliced = tensr_slice(t, 1, &s);
    assert(sliced);
    assert(sliced->size == 5);
    assert(((double *)sliced->data)[0] == 1.0);
    assert(((double *)sliced->data)[4] == 5.0);

    tensr_free(t);
    tensr_free(sliced);
}

void tensr_slice_tests(void)
{
    test_slice_single_axis();
    test_slice_2d_tensor();
    test_slice_negative_step();
    test_slice_full_range();
}