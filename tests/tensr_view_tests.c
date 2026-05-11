#include <test.h>

static void test_transpose_basic(void)
{
    t_tensr *orig;
    t_tensr *trans;
    double *orig_data;
    size_t idx[2];

    orig = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    orig_data = (double *)orig->data;
    orig_data[0] = 1.0; orig_data[1] = 2.0; orig_data[2] = 3.0;
    orig_data[3] = 4.0; orig_data[4] = 5.0; orig_data[5] = 6.0;

    trans = tensr_transpose(orig);
    assert(trans);
    assert(trans->layout.ndim == 2);
    assert(trans->layout.shape[0] == 3);
    assert(trans->layout.shape[1] == 2);

    idx[0] = 0; idx[1] = 0;
    assert(*(double *)tensr_get(trans, idx) == 1.0);
    idx[0] = 0; idx[1] = 1;
    assert(*(double *)tensr_get(trans, idx) == 4.0);
    idx[0] = 1; idx[1] = 0;
    assert(*(double *)tensr_get(trans, idx) == 2.0);
    idx[0] = 1; idx[1] = 1;
    assert(*(double *)tensr_get(trans, idx) == 5.0);
    idx[0] = 2; idx[1] = 0;
    assert(*(double *)tensr_get(trans, idx) == 3.0);
    idx[0] = 2; idx[1] = 1;
    assert(*(double *)tensr_get(trans, idx) == 6.0);

    tensr_free(orig);
    tensr_free(trans);
}

static void test_transpose_data_sharing(void)
{
    t_tensr *orig;
    t_tensr *trans;
    double *orig_data;
    size_t idx[2];

    orig = tensr_alloc(2, (size_t[]){2, 2}, DT_F64);
    orig_data = (double *)orig->data;
    orig_data[0] = 1.0;
    orig_data[3] = 99.0;

    trans = tensr_transpose(orig);
    orig_data[0] = 0.0;
    idx[0] = 0; idx[1] = 0;
    assert(*(double *)tensr_get(trans, idx) == 0.0);

    tensr_free(orig);
    tensr_free(trans);
}

static void test_reshape_basic(void)
{
    t_tensr *orig;
    t_tensr *reshaped;

    orig = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    ((double *)orig->data)[0] = 1.0;
    ((double *)orig->data)[5] = 6.0;

    reshaped = tensr_reshape(orig, 1, (size_t[]){6});
    assert(reshaped);
    assert(reshaped->layout.ndim == 1);
    assert(reshaped->size == 6);
    assert(((double *)reshaped->data)[0] == 1.0);
    assert(((double *)reshaped->data)[5] == 6.0);

    tensr_free(orig);
    tensr_free(reshaped);
}

static void test_reshape_same_size(void)
{
    t_tensr *orig;
    t_tensr *reshaped;

    orig = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);

    reshaped = tensr_reshape(orig, 2, (size_t[]){4, 3});
    assert(reshaped);
    assert(reshaped->layout.ndim == 2);
    assert(reshaped->size == 12);

    tensr_free(orig);
    tensr_free(reshaped);
}

static void test_expand_dims(void)
{
    t_tensr *t;
    t_bool result;

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    assert(t->layout.ndim == 1);

    result = tensr_expand_dims(t, 0);
    assert(result);
    assert(t->layout.ndim == 2);
    assert(t->layout.shape[0] == 1);
    assert(t->layout.shape[1] == 3);
    tensr_free(t);

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    result = tensr_expand_dims(t, 1);
    assert(result);
    assert(t->layout.ndim == 2);
    assert(t->layout.shape[0] == 3);
    assert(t->layout.shape[1] == 1);
    tensr_free(t);
}

static void test_permute_basic(void)
{
    t_tensr *t;
    t_tensr *permuted;
    size_t perm[] = {2, 1, 0};

    t = tensr_alloc(3, (size_t[]){2, 3, 4}, DT_F64);
    ((double *)t->data)[0] = 1.0;
    ((double *)t->data)[23] = 99.0;

    permuted = tensr_permute(t, perm);
    assert(permuted);
    assert(permuted->layout.ndim == 3);
    assert(permuted->layout.shape[0] == 4);
    assert(permuted->layout.shape[1] == 3);
    assert(permuted->layout.shape[2] == 2);
    assert(((double *)permuted->data)[0] == 1.0);
    assert(((double *)permuted->data)[23] == 99.0);

    tensr_free(t);
    tensr_free(permuted);
}

void tensr_view_tests(void)
{
    test_transpose_basic();
    test_transpose_data_sharing();
    test_reshape_basic();
    test_reshape_same_size();
    test_expand_dims();
    test_permute_basic();
}