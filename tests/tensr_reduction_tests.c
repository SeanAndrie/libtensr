/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduction_tests.c                           :::      ::::::::   */
/*                                                    :-:       :-:   :-:      */
/*   By: opencode <opencore@student.42abudhabi.ae>   ::::   :::::: ::::       */
/*                                                ..######::###::###::####..   */
/*   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              */
/*   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static void test_sum_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 1.0; data[1] = 2.0; data[2] = 3.0;
    data[3] = 4.0; data[4] = 5.0; data[5] = 6.0;

    result = tensr_sum(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    assert(result->layout.shape[0] == 3);
    data = (double *)result->data;
    assert(data[0] == 5.0);
    assert(data[1] == 7.0);
    assert(data[2] == 9.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_sum_all_axes(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0, 1};

    t = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 1.0; data[1] = 2.0; data[2] = 3.0;
    data[3] = 4.0; data[4] = 5.0; data[5] = 6.0;

    result = tensr_sum(t, 2, axes);
    assert(result);
    assert(result->layout.ndim == 0);
    assert(((double *)result->data)[0] == 21.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_mean_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 1.0; data[1] = 2.0; data[2] = 3.0;
    data[3] = 5.0; data[4] = 6.0; data[5] = 7.0;

    result = tensr_mean(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    data = (double *)result->data;
    assert(data[0] == 3.0);
    assert(data[1] == 4.0);
    assert(data[2] == 5.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_min_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 5.0; data[1] = 1.0;
    data[2] = 3.0; data[3] = 7.0;
    data[4] = 2.0; data[5] = 9.0;

    result = tensr_min(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    data = (double *)result->data;
    assert(data[0] == 2.0);
    assert(data[1] == 1.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_max_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 5.0; data[1] = 1.0;
    data[2] = 3.0; data[3] = 7.0;
    data[4] = 2.0; data[5] = 9.0;

    result = tensr_max(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    data = (double *)result->data;
    assert(data[0] == 5.0);
    assert(data[1] == 9.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_argmax_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 5.0; data[1] = 1.0;
    data[2] = 3.0; data[3] = 7.0;
    data[4] = 2.0; data[5] = 9.0;

    result = tensr_argmax(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    int64_t *r = (int64_t *)result->data;
    assert(r[0] == 0);
    assert(r[1] == 2);

    tensr_free(t);
    tensr_free(result);
}

static void test_argmin_basic(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    double *data = (double *)t->data;
    data[0] = 5.0; data[1] = 1.0;
    data[2] = 3.0; data[3] = 7.0;
    data[4] = 2.0; data[5] = 9.0;

    result = tensr_argmin(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 1);
    int64_t *r = (int64_t *)result->data;
    assert(r[0] == 2);

    tensr_free(t);
    tensr_free(result);
}

static void test_sum_vector(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    ((double *)t->data)[0] = 1.0;
    ((double *)t->data)[1] = 2.0;
    ((double *)t->data)[2] = 3.0;
    ((double *)t->data)[3] = 4.0;
    ((double *)t->data)[4] = 5.0;

    result = tensr_sum(t, 1, axes);
    assert(result);
    assert(result->layout.ndim == 0);
    assert(((double *)result->data)[0] == 15.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_sum_int_dtype(void)
{
    t_tensr *t;
    t_tensr *result;
    size_t axes[] = {0};

    t = tensr_alloc(1, (size_t[]){4}, DT_I32);
    ((int32_t *)t->data)[0] = 1;
    ((int32_t *)t->data)[1] = 2;
    ((int32_t *)t->data)[2] = 3;
    ((int32_t *)t->data)[3] = 4;

    result = tensr_sum(t, 1, axes);
    assert(result);
    assert(((int32_t *)result->data)[0] == 10);

    tensr_free(t);
    tensr_free(result);
}

void tensr_reduction_tests(void)
{
    test_sum_basic();
    test_sum_all_axes();
    test_mean_basic();
    test_min_basic();
    test_max_basic();
    test_argmax_basic();
    test_argmin_basic();
    test_sum_vector();
    test_sum_int_dtype();
}