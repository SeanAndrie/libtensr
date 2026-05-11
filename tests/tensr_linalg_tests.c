#include <test.h>

static void test_dot_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)b->data)[0] = 4.0; ((double *)b->data)[1] = 5.0; ((double *)b->data)[2] = 6.0;

    result = tensr_dot(a, b);
    assert(result);
    assert(result->layout.ndim == 0);
    assert(((double *)result->data)[0] == 32.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_cross_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 0.0; ((double *)a->data)[2] = 0.0;
    ((double *)b->data)[0] = 0.0; ((double *)b->data)[1] = 1.0; ((double *)b->data)[2] = 0.0;

    result = tensr_cross(a, b);
    assert(result);
    assert(result->size == 3);
    double *r = (double *)result->data;
    assert(r[0] == 0.0);
    assert(r[1] == 0.0);
    assert(r[2] == 1.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_cross_orthogonal_vectors(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)b->data)[0] = 4.0; ((double *)b->data)[1] = 5.0; ((double *)b->data)[2] = 6.0;

    result = tensr_cross(a, b);
    assert(result);
    double *r = (double *)result->data;
    assert(r[0] == -3.0);
    assert(r[1] == 6.0);
    assert(r[2] == -3.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_matmul_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    b = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    double *data_a = (double *)a->data;
    double *data_b = (double *)b->data;
    data_a[0] = 1.0; data_a[1] = 2.0; data_a[2] = 3.0;
    data_a[3] = 4.0; data_a[4] = 5.0; data_a[5] = 6.0;
    data_b[0] = 1.0; data_b[1] = 0.0;
    data_b[2] = 0.0; data_b[3] = 1.0;
    data_b[4] = 1.0; data_b[5] = 1.0;

    result = tensr_matmul(a, b, NULL);
    assert(result);
    assert(result->layout.ndim == 2);
    assert(result->layout.shape[0] == 2);
    assert(result->layout.shape[1] == 2);
    double *r = (double *)result->data;
    assert(r[0] == 4.0);
    assert(r[1] == 5.0);
    assert(r[2] == 10.0);
    assert(r[3] == 11.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_norm_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)t->data)[0] = 3.0;
    ((double *)t->data)[1] = 4.0;
    ((double *)t->data)[2] = 0.0;

    result = tensr_norm(t, false, NULL);
    assert(result);
    assert(result->layout.ndim == 0);
    double norm = ((double *)result->data)[0];
    assert(norm == 5.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_normalize_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)t->data)[0] = 3.0;
    ((double *)t->data)[1] = 4.0;
    ((double *)t->data)[2] = 0.0;

    result = tensr_normalize(t, NULL);
    assert(result);
    double *r = (double *)result->data;
    double epsilon = 1e-10;
    assert(r[0] > 0.6 - epsilon && r[0] < 0.6 + epsilon);
    assert(r[1] > 0.8 - epsilon && r[1] < 0.8 + epsilon);
    assert(r[2] == 0.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_inner_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){3}, DT_F64);
    b = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)b->data)[0] = 4.0; ((double *)b->data)[1] = 5.0; ((double *)b->data)[2] = 6.0;

    result = tensr_inner(a, b, 1, (size_t[]){0});
    assert(result);
    assert(((double *)result->data)[0] == 32.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_matmul_identity(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 2}, DT_F64);
    b = tensr_alloc(2, (size_t[]){2, 2}, DT_F64);
    double *data_a = (double *)a->data;
    double *data_b = (double *)b->data;
    data_a[0] = 1.0; data_a[1] = 2.0;
    data_a[2] = 3.0; data_a[3] = 4.0;
    data_b[0] = 1.0; data_b[1] = 0.0;
    data_b[2] = 0.0; data_b[3] = 1.0;

    result = tensr_matmul(a, b, NULL);
    assert(result);
    assert(result->layout.shape[0] == 2);
    assert(result->layout.shape[1] == 2);
    double *r = (double *)result->data;
    assert(r[0] == 1.0);
    assert(r[1] == 2.0);
    assert(r[2] == 3.0);
    assert(r[3] == 4.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_matmul_with_out(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *out;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    b = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    out = tensr_alloc(2, (size_t[]){2, 2}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)a->data)[3] = 4.0; ((double *)a->data)[4] = 5.0; ((double *)a->data)[5] = 6.0;
    ((double *)b->data)[0] = 1.0; ((double *)b->data)[1] = 0.0;
    ((double *)b->data)[2] = 0.0; ((double *)b->data)[3] = 1.0;
    ((double *)b->data)[4] = 1.0; ((double *)b->data)[5] = 1.0;

    result = tensr_matmul(a, b, out);
    assert(result);
    assert(result == out);
    double *r = (double *)result->data;
    assert(r[0] == 4.0);
    assert(r[1] == 5.0);
    assert(r[2] == 10.0);
    assert(r[3] == 11.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(out);
}

static void test_matmul_out_alloc(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    b = tensr_alloc(2, (size_t[]){3, 2}, DT_F64);
    ((double *)a->data)[0] = 1.0; ((double *)a->data)[1] = 2.0; ((double *)a->data)[2] = 3.0;
    ((double *)a->data)[3] = 4.0; ((double *)a->data)[4] = 5.0; ((double *)a->data)[5] = 6.0;
    ((double *)b->data)[0] = 1.0; ((double *)b->data)[1] = 0.0;
    ((double *)b->data)[2] = 0.0; ((double *)b->data)[3] = 1.0;
    ((double *)b->data)[4] = 1.0; ((double *)b->data)[5] = 1.0;

    result = tensr_matmul(a, b, NULL);
    assert(result);
    assert(result->layout.ndim == 2);
    assert(result->layout.shape[0] == 2);
    assert(result->layout.shape[1] == 2);
    double *r = (double *)result->data;
    assert(r[0] == 4.0);
    assert(r[1] == 5.0);
    assert(r[2] == 10.0);
    assert(r[3] == 11.0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_matmul_incompatible_dims(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);
    b = tensr_alloc(2, (size_t[]){2, 2}, DT_F64);

    result = tensr_matmul(a, b, NULL);
    assert(!result);

    tensr_free(a);
    tensr_free(b);
}

static void test_matmul_null_inputs(void)
{
    t_tensr *a;
    t_tensr *result;

    a = tensr_alloc(2, (size_t[]){2, 3}, DT_F64);

    result = tensr_matmul(NULL, a, NULL);
    assert(!result);

    result = tensr_matmul(a, NULL, NULL);
    assert(!result);

    tensr_free(a);
}

void tensr_linalg_tests(void)
{
    test_dot_basic();
    test_cross_basic();
    test_cross_orthogonal_vectors();
    test_matmul_basic();
    test_norm_basic();
    test_normalize_basic();
    test_inner_basic();
    test_matmul_identity();
    test_matmul_with_out();
    test_matmul_out_alloc();
    test_matmul_incompatible_dims();
    test_matmul_null_inputs();
}