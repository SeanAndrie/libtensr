#include <test.h>

static void test_copy_shape_and_dtype(void)
{
    t_tensr *orig;
    t_tensr *copy;

    orig = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    copy = tensr_copy(orig);
    assert(copy);
    assert(copy->layout.ndim == orig->layout.ndim);
    assert(copy->layout.shape[0] == orig->layout.shape[0]);
    assert(copy->layout.shape[1] == orig->layout.shape[1]);
    assert(copy->dtype == orig->dtype);
    assert(copy->size == orig->size);
    tensr_free(orig);
    tensr_free(copy);
}

static void test_copy_data_independence(void)
{
    t_tensr *orig;
    t_tensr *copy;
    double *orig_data;
    double *copy_data;

    orig = tensr_alloc(1, (size_t[]){5}, DT_F64);
    orig_data = (double *)orig->data;
    orig_data[0] = 1.0;
    orig_data[2] = 3.0;
    orig_data[4] = 5.0;

    copy = tensr_copy(orig);
    assert(copy);
    copy_data = (double *)copy->data;
    assert(copy_data[0] == 1.0);
    assert(copy_data[2] == 3.0);
    assert(copy_data[4] == 5.0);

    copy_data[0] = 99.0;
    assert(orig_data[0] == 1.0);

    tensr_free(orig);
    tensr_free(copy);
}

static void test_copy_null_input(void)
{
    assert(!tensr_copy(NULL));
}

static void test_copy_scalar(void)
{
    t_tensr *orig;
    t_tensr *copy;

    orig = tensr_alloc(0, NULL, DT_I32);
    ((int32_t *)orig->data)[0] = 42;
    copy = tensr_copy(orig);
    assert(copy);
    assert(((int32_t *)copy->data)[0] == 42);
    tensr_free(orig);
    tensr_free(copy);
}

static void test_copy_all_dtypes(void)
{
    t_tensr *orig;
    t_tensr *copy;
    t_dtype dtypes[] = {DT_U8, DT_I32, DT_I64, DT_F32, DT_F64};

    int i = 0;
    while (i < 5)
    {
        orig = tensr_alloc(1, (size_t[]){3}, dtypes[i]);
        copy = tensr_copy(orig);
        assert(copy);
        assert(copy->dtype == dtypes[i]);
        tensr_free(orig);
        tensr_free(copy);
        i++;
    }
}

void tensr_copy_tests(void)
{
    test_copy_shape_and_dtype();
    test_copy_data_independence();
    test_copy_null_input();
    test_copy_scalar();
    test_copy_all_dtypes();
}