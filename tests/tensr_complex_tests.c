#include <test.h>

static void test_complex_scalar(void)
{
    t_tensr *t;

    t = tensr_complex(3.0 + 4.0 * I, DT_C64);
    assert(t);
    assert(t->dtype == DT_C64);
    assert(t->size == 1);
    float complex val = ((float complex *)t->data)[0];
    assert(creal(val) == 3.0);
    assert(cimag(val) == 4.0);
    tensr_free(t);

    t = tensr_complex(1.5 - 2.5 * I, DT_C128);
    assert(t);
    assert(t->dtype == DT_C128);
    double complex val128 = ((double complex *)t->data)[0];
    assert(creal(val128) == 1.5);
    assert(cimag(val128) == -2.5);
    tensr_free(t);
}

static void test_cfull_basic(void)
{
    t_tensr *t;

    t = tensr_cfull(2.0 + 3.0 * I, 1, (size_t[]){3}, DT_C64);
    assert(t);
    assert(t->size == 3);
    float complex *data = (float complex *)t->data;
    assert(creal(data[0]) == 2.0 && cimag(data[0]) == 3.0);
    assert(creal(data[1]) == 2.0 && cimag(data[1]) == 3.0);
    assert(creal(data[2]) == 2.0 && cimag(data[2]) == 3.0);
    tensr_free(t);
}

static void test_cfill_basic(void)
{
    t_tensr *t;
    t_bool result;

    t = tensr_alloc(1, (size_t[]){2}, DT_C128);
    result = tensr_cfill(t, 5.0 - 1.0 * I);
    assert(result);
    double complex *data = (double complex *)t->data;
    assert(creal(data[0]) == 5.0 && cimag(data[0]) == -1.0);
    assert(creal(data[1]) == 5.0 && cimag(data[1]) == -1.0);
    tensr_free(t);
}

static void test_clinspace_basic(void)
{
    t_tensr *t;

    t = tensr_clinspace(0.0 + 0.0 * I, 2.0 + 2.0 * I, 3, DT_C64);
    assert(t);
    float complex *data = (float complex *)t->data;
    assert(creal(data[0]) == 0.0 && cimag(data[0]) == 0.0);
    assert(creal(data[1]) == 1.0 && cimag(data[1]) == 1.0);
    assert(creal(data[2]) == 2.0 && cimag(data[2]) == 2.0);
    tensr_free(t);
}

static void test_cscale_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){2}, DT_C64);
    ((float complex *)t->data)[0] = 1.0 + 2.0 * I;
    ((float complex *)t->data)[1] = 3.0 + 4.0 * I;

    result = tensr_cscale(t, 2.0 + 0.0 * I, NULL);
    assert(result);
    float complex *r = (float complex *)result->data;
    assert(creal(r[0]) == 2.0 && cimag(r[0]) == 4.0);
    assert(creal(r[1]) == 6.0 && cimag(r[1]) == 8.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_conjugate_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){2}, DT_C64);
    ((float complex *)t->data)[0] = 3.0 + 4.0 * I;
    ((float complex *)t->data)[1] = 1.0 - 2.0 * I;

    result = tensr_conjugate(t, NULL);
    assert(result);
    float complex *r = (float complex *)result->data;
    assert(creal(r[0]) == 3.0 && cimag(r[0]) == -4.0);
    assert(creal(r[1]) == 1.0 && cimag(r[1]) == 2.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_cdot_basic(void)
{
    t_tensr *a;
    t_tensr *b;
    t_tensr *result;

    a = tensr_alloc(1, (size_t[]){2}, DT_C64);
    b = tensr_alloc(1, (size_t[]){2}, DT_C64);
    ((float complex *)a->data)[0] = 1.0 + 1.0 * I;
    ((float complex *)a->data)[1] = 2.0 + 2.0 * I;
    ((float complex *)b->data)[0] = 1.0 + 0.0 * I;
    ((float complex *)b->data)[1] = 0.0 + 1.0 * I;

    result = tensr_cdot(a, b);
    assert(result);
    assert(result->layout.ndim == 0);

    tensr_free(a);
    tensr_free(b);
    tensr_free(result);
}

static void test_creal_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){3}, DT_C64);
    ((float complex *)t->data)[0] = 1.0 + 2.0 * I;
    ((float complex *)t->data)[1] = 3.0 + 4.0 * I;
    ((float complex *)t->data)[2] = 5.0 + 6.0 * I;

    result = tensr_creal(t, NULL);
    assert(result);
    float *r = (float *)result->data;
    assert(r[0] == 1.0);
    assert(r[1] == 3.0);
    assert(r[2] == 5.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_cimag_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){3}, DT_C64);
    ((float complex *)t->data)[0] = 1.0 + 2.0 * I;
    ((float complex *)t->data)[1] = 3.0 + 4.0 * I;
    ((float complex *)t->data)[2] = 5.0 + 6.0 * I;

    result = tensr_cimag(t, NULL);
    assert(result);
    float *r = (float *)result->data;
    assert(r[0] == 2.0);
    assert(r[1] == 4.0);
    assert(r[2] == 6.0);

    tensr_free(t);
    tensr_free(result);
}

static void test_carg_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){2}, DT_C64);
    ((float complex *)t->data)[0] = 1.0 + 0.0 * I;
    ((float complex *)t->data)[1] = 0.0 + 1.0 * I;

    result = tensr_carg(t, NULL);
    assert(result);
    float *r = (float *)result->data;
    double epsilon = 1e-6;
    assert(r[0] > 0.0 - epsilon && r[0] < 0.0 + epsilon);
    assert(r[1] > 1.57079 - epsilon && r[1] < 1.5708 + epsilon);

    tensr_free(t);
    tensr_free(result);
}

static void test_cabs_basic(void)
{
    t_tensr *t;
    t_tensr *result;

    t = tensr_alloc(1, (size_t[]){2}, DT_C64);
    ((float complex *)t->data)[0] = 3.0 + 4.0 * I;
    ((float complex *)t->data)[1] = 5.0 + 12.0 * I;

    result = tensr_abs(t, NULL);
    assert(result);
    float *r = (float *)result->data;
    assert(r[0] == 5.0);
    assert(r[1] == 13.0);

    tensr_free(t);
    tensr_free(result);
}

void tensr_complex_tests(void)
{
    test_complex_scalar();
    test_cfull_basic();
    test_cfill_basic();
    test_clinspace_basic();
    test_cscale_basic();
    test_conjugate_basic();
    test_cdot_basic();
    test_creal_basic();
    test_cimag_basic();
    test_carg_basic();
    test_cabs_basic();
}