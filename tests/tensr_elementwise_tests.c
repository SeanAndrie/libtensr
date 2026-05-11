#include <test.h>

static void test_add_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)b->data)[0] = 10.0; ((double *)b->data)[1] = 20.0; ((double *)b->data)[2] = 30.0;

    result = tensr_add(a, b, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 11.0);
    assert(r[1] == 22.0);
    assert(r[2] == 33.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_sub_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 10.0; ((double *)a->data)[1] = 20.0; ((double *)a->data)[2] = 30.0;
    ((double *)b->data)[0] = 1.0; ((double *)b->data)[1] = 5.0; ((double *)b->data)[2] = 10.0;

    result = tensr_sub(a, b, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 9.0);
    assert(r[1] == 15.0);
    assert(r[2] == 20.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_mul_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 2.0; ((double *)a->data)[1] = 3.0; ((double *)a->data)[2] = 4.0;
    ((double *)b->data)[0] = 5.0; ((double *)b->data)[1] = 6.0; ((double *)b->data)[2] = 7.0;

    result = tensr_mul(a, b, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 10.0);
    assert(r[1] == 18.0);
    assert(r[2] == 28.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_div_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 10.0; ((double *)a->data)[1] = 20.0; ((double *)a->data)[2] = 30.0;
    ((double *)b->data)[0] = 2.0; ((double *)b->data)[1] = 4.0; ((double *)b->data)[2] = 5.0;

    result = tensr_div(a, b, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 5.0);
    assert(r[1] == 5.0);
    assert(r[2] == 6.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_abs_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    ((double *)t->data)[0] = -5.0;
    ((double *)t->data)[1] = -2.5;
    ((double *)t->data)[2] = 0.0;
    ((double *)t->data)[3] = 3.5;
    ((double *)t->data)[4] = 10.0;

    result = tensr_abs(t, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 5.0);
    assert(r[1] == 2.5);
    assert(r[2] == 0.0);
    assert(r[3] == 3.5);
    assert(r[4] == 10.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_neg_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){4}, DT_F64);
    ((double *)t->data)[0] = 1.0;
    ((double *)t->data)[1] = -2.0;
    ((double *)t->data)[2] = 3.5;
    ((double *)t->data)[3] = -4.0;

    result = tensr_neg(t, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == -1.0);
    assert(r[1] == 2.0);
    assert(r[2] == -3.5);
    assert(r[3] == 4.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_sqrt_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){4}, DT_F64);
    ((double *)t->data)[0] = 0.0;
    ((double *)t->data)[1] = 1.0;
    ((double *)t->data)[2] = 4.0;
    ((double *)t->data)[3] = 9.0;

    result = tensr_sqrt(t, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 0.0);
    assert(r[1] == 1.0);
    assert(r[2] == 2.0);
    assert(r[3] == 3.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_clamp_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){6}, DT_F64);
    ((double *)t->data)[0] = -5.0;
    ((double *)t->data)[1] = 0.0;
    ((double *)t->data)[2] = 5.0;
    ((double *)t->data)[3] = 10.0;
    ((double *)t->data)[4] = 15.0;
    ((double *)t->data)[5] = 20.0;

    result = tensr_clamp(t, 2.0, 12.0, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 2.0);
    assert(r[1] == 2.0);
    assert(r[2] == 5.0);
    assert(r[3] == 10.0);
    assert(r[4] == 12.0);
    assert(r[5] == 12.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_scale_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)t->data)[0] = 1.0;
    ((double *)t->data)[1] = 2.0;
    ((double *)t->data)[2] = 3.0;

    result = tensr_scale(t, 3.0, NULL);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == 3.0);
    assert(r[1] == 6.0);
    assert(r[2] == 9.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_elementwise_int_dtype(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_I32);
    b = tensr_alloc(1, (size_t[]){3}, DT_I32);
    ((int32_t *)a->data)[0] = 10; ((int32_t *)a->data)[1] = 20; ((int32_t *)a->data)[2] = 30;
    ((int32_t *)b->data)[0] = 1; ((int32_t *)b->data)[1] = 2; ((int32_t *)b->data)[2] = 3;

    result = tensr_add(a, b, NULL);
    assert(result);
    int32_t *r = (int32_t *)result->data;
    assert(r[0] == 11);
    assert(r[1] == 22);
    assert(r[2] == 33);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

void tensr_elementwise_tests(void)
{
    test_add_basic();
    test_sub_basic();
    test_mul_basic();
    test_div_basic();
    test_abs_basic();
    test_neg_basic();
    test_sqrt_basic();
    test_clamp_basic();
    test_scale_basic();
    test_elementwise_int_dtype();
}