    t = tensr_alloc(0, NULL, DT_I32);
    assert(t);
    assert(t->size == 1);
    assert(t->dtype == DT_I32);
    assert(t->layout.ndim == 0);
    tensr_free(t);

    t = tensr_alloc(1, (size_t[]){5}, DT_U8);
    assert(t);
    assert(t->size == 5);
    assert(t->dtype == DT_U8);
    assert(t->layout.ndim == 1);
    assert(t->layout.shape[0] == 5);
    tensr_free(t);

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F32);
    assert(t);
    assert(t->size == 12);
    assert(t->dtype == DT_F32);
    assert(t->layout.ndim == 2);
    assert(t->layout.shape[0] == 3);
    assert(t->layout.shape[1] == 4);
    tensr_free(t);

    t = tensr_alloc(3, (size_t[]){2, 3, 4}, DT_F64);
    assert(t);
    assert(t->size == 24);
    assert(t->dtype == DT_F64);
    assert(t->layout.ndim == 3);
    tensr_free(t);
}

static void test_alloc_all_dtypes(void)
{
    t_tensr *t;
    t_dtype dtypes[] = {DT_U8, DT_I32, DT_I64, DT_F32, DT_F64, DT_C64, DT_C128};
    size_t sizes[] = {1, 4, 8, 4, 8, 8, 16};
    int i;

    i = 0;
    while (i < 7)
    {
        t = tensr_alloc(1, (size_t[]){10}, dtypes[i]);
        assert(t);
        assert(t->dtype == dtypes[i]);
        assert(t->elemsize == sizes[i]);
        tensr_free(t);
        i++;
    }
}

static void test_alloc_strides_contiguous(void)
{
    t_tensr *t;

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    assert(t->layout.stride[0] == 4);
    assert(t->layout.stride[1] == 1);
    tensr_free(t);

    t = tensr_alloc(3, (size_t[]){2, 3, 4}, DT_F64);
    assert(t->layout.stride[0] == 12);
    assert(t->layout.stride[1] == 4);
    assert(t->layout.stride[2] == 1);
    tensr_free(t);
}

void tensr_alloc_tests(void)
{
    test_alloc_null_shape();
    test_alloc_various_dims();
    test_alloc_all_dtypes();
    test_alloc_strides_contiguous();
}
