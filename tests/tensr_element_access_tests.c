/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_element_access_tests.c                      :::      ::::::::   */
/*                                                    :-:       :-:   :-:      */
/*   By: opencode <opencore@student.42abudhabi.ae>   ::::   :::::: ::::       */
/*                                                ..######::###::###::####..   */
/*   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              */
/*   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static void test_get_set_basic(void)
{
    t_tensr *t;
    size_t idx[2];
    double val;

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);

    idx[0] = 0; idx[1] = 0;
    val = 1.0;
    assert(tensr_set(t, &val, idx));

    idx[0] = 2; idx[1] = 3;
    val = 99.0;
    assert(tensr_set(t, &val, idx));

    idx[0] = 0; idx[1] = 0;
    assert(*(double *)tensr_get(t, idx) == 1.0);

    idx[0] = 2; idx[1] = 3;
    assert(*(double *)tensr_get(t, idx) == 99.0);

    tensr_free(t);
}

static void test_get_set_scalar(void)
{
    t_tensr *t;
    double val = 42.5;
    size_t idx[1] = {0};

    t = tensr_alloc(0, NULL, DT_F64);
    assert(tensr_set(t, &val, idx));
    assert(*(double *)tensr_get(t, idx) == 42.5);
    tensr_free(t);
}

static void test_get_set_vector(void)
{
    t_tensr *t;
    size_t idx[1];
    double val;
    int i;

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    i = 0;
    while (i < 5)
    {
        idx[0] = i;
        val = (double)i * 2.0;
        tensr_set(t, &val, idx);
        i++;
    }
    i = 0;
    while (i < 5)
    {
        idx[0] = i;
        assert(*(double *)tensr_get(t, idx) == (double)i * 2.0);
        i++;
    }
    tensr_free(t);
}

static void test_offset_basic(void)
{
    t_tensr *t;
    t_layout *l;
    size_t indices[MAX_NDIM];

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    l = &t->layout;

    indices[0] = 0; indices[1] = 0;
    assert(tensr_offset(l, indices) == 0);

    indices[0] = 0; indices[1] = 1;
    assert(tensr_offset(l, indices) == 1);

    indices[0] = 1; indices[1] = 0;
    assert(tensr_offset(l, indices) == 4);

    indices[0] = 2; indices[1] = 3;
    assert(tensr_offset(l, indices) == 11);

    tensr_free(t);
}

static void test_offset_3d(void)
{
    t_tensr *t;
    t_layout *l;
    size_t indices[MAX_NDIM];

    t = tensr_alloc(3, (size_t[]){2, 3, 4}, DT_F64);
    l = &t->layout;

    indices[0] = 0; indices[1] = 0; indices[2] = 0;
    assert(tensr_offset(l, indices) == 0);

    indices[0] = 1; indices[1] = 0; indices[2] = 0;
    assert(tensr_offset(l, indices) == 12);

    indices[0] = 1; indices[1] = 2; indices[2] = 3;
    assert(tensr_offset(l, indices) == 23);

    tensr_free(t);
}

static void test_is_contiguous(void)
{
    t_tensr *t;

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    assert(tensr_is_contiguous(t) == true);
    tensr_free(t);

    t = tensr_transpose(tensr_alloc(2, (size_t[]){3, 4}, DT_F64));
    assert(tensr_is_contiguous(t) == false);
    tensr_free(t);

    t = tensr_alloc(1, (size_t[]){10}, DT_F64);
    assert(tensr_is_contiguous(t) == true);
    tensr_free(t);
}

static void test_view_offsets(void)
{
    t_tensr *t;
    t_tensr *trans;
    t_layout *l;
    size_t indices[MAX_NDIM];

    t = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    trans = tensr_transpose(t);
    l = &trans->layout;

    indices[0] = 0; indices[1] = 0;
    assert(tensr_offset(l, indices) == 0);

    indices[0] = 0; indices[1] = 1;
    assert(tensr_offset(l, indices) == 3);

    indices[0] = 1; indices[1] = 0;
    assert(tensr_offset(l, indices) == 1);

    indices[0] = 1; indices[1] = 1;
    assert(tensr_offset(l, indices) == 4);

    tensr_free(t);
    tensr_free(trans);
}

void tensr_element_access_tests(void)
{
    test_get_set_basic();
    test_get_set_scalar();
    test_get_set_vector();
    test_offset_basic();
    test_offset_3d();
    test_is_contiguous();
    test_view_offsets();
}