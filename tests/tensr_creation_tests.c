#include <test.h>

static void test_full_basic(void)
{
    t_tensr *t;

    t = tensr_full(5.0, 1, (size_t[]){4}, DT_F64);
    assert(t);
    assert(t->size == 4);
    assert(t->dtype == DT_F64);
    double *data = (double *)t->data;
    assert(data[0] == 5.0);
    assert(data[1] == 5.0);
    assert(data[2] == 5.0);
    assert(data[3] == 5.0);
    tensr_free(t);

    t = tensr_full(3, 2, (size_t[]){2, 3}, DT_I32);
    assert(t);
    assert(t->size == 6);
    int32_t *idata = (int32_t *)t->data;
    int i = 0;
    while (i < 6)
    {
        assert(idata[i] == 3);
        i++;
    }
    tensr_free(t);
}

static void test_full_scalar(void)
{
    t_tensr *t;

    t = tensr_scalar(7.5, DT_F64);
    assert(t);
    assert(t->size == 1);
    assert(((double *)t->data)[0] == 7.5);
    tensr_free(t);
}

static void test_linspace_basic(void)
{
    t_tensr *t;

    t = tensr_linspace(0.0, 3.0, 4, DT_F64);
    assert(t);
    double *data = (double *)t->data;
    assert(data[0] == 0.0);
    assert(data[1] == 1.0);
    assert(data[2] == 2.0);
    assert(data[3] == 3.0);
    tensr_free(t);
}

static void test_linspace_n_equals_one(void)
{
    t_tensr *t;

    t = tensr_linspace(5.0, 5.0, 1, DT_F64);
    assert(t);
    assert(((double *)t->data)[0] == 5.0);
    tensr_free(t);
}

static void test_linspace_n_equals_two(void)
{
    t_tensr *t;

    t = tensr_linspace(0.0, 1.0, 2, DT_F64);
    assert(t);
    double *data = (double *)t->data;
    assert(data[0] == 0.0);
    assert(data[1] == 1.0);
    tensr_free(t);
}

static void test_scalar(void)
{
    t_tensr *t;

    t = tensr_scalar(42, DT_I32);
    assert(t);
    assert(t->size == 1);
    assert(t->layout.ndim == 0);
    assert(((int32_t *)t->data)[0] == 42);
    tensr_free(t);

    t = tensr_scalar(3.14, DT_F64);
    assert(t);
    assert(((double *)t->data)[0] == 3.14);
    tensr_free(t);
}

static void test_from_data(void)
{
    double arr[] = {1.0, 2.0, 3.0, 4.0};
    t_tensr *t;

    t = tensr_from_data(arr, 1, (size_t[]){4}, DT_F64);
    assert(t);
    assert(t->size == 4);
    assert(((double *)t->data)[0] == 1.0);
    assert(((double *)t->data)[3] == 4.0);
}

void tensr_creation_tests(void)
{
    test_full_basic();
    test_full_scalar();
    test_linspace_basic();
    test_linspace_n_equals_one();
    test_linspace_n_equals_two();
    test_scalar();
    test_from_data();
}