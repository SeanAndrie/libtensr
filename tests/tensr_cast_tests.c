/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cast_tests.c                                 :::      ::::::::   */
/*                                                    :-:       :-:   :-:      */
/*   By: opencode <opencore@student.42abudhabi.ae>   ::::   :::::: ::::       */
/*                                                ..######::###::###::####..   */
/*   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              */
/*   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static void test_cast_int_to_float(void)
{
    t_tensr *src;
    t_tensr *dst;

    src = tensr_alloc(1, (size_t[]){4}, DT_I32);
    ((int32_t *)src->data)[0] = 1;
    ((int32_t *)src->data)[1] = 2;
    ((int32_t *)src->data)[2] = 3;
    ((int32_t *)src->data)[3] = 4;

    dst = tensr_cast(src, DT_F64, NULL);
    assert(dst);
    assert(dst->dtype == DT_F64);
    assert(((double *)dst->data)[0] == 1.0);
    assert(((double *)dst->data)[1] == 2.0);
    assert(((double *)dst->data)[2] == 3.0);
    assert(((double *)dst->data)[3] == 4.0);

    tensr_free(src);
    tensr_free(dst);
}

static void test_cast_float_to_int(void)
{
    t_tensr *src;
    t_tensr *dst;

    src = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)src->data)[0] = 1.5;
    ((double *)src->data)[1] = 2.7;
    ((double *)src->data)[2] = 3.9;

    dst = tensr_cast(src, DT_I32, NULL);
    assert(dst);
    assert(dst->dtype == DT_I32);
    assert(((int32_t *)dst->data)[0] == 1);
    assert(((int32_t *)dst->data)[1] == 2);
    assert(((int32_t *)dst->data)[2] == 3);

    tensr_free(src);
    tensr_free(dst);
}

static void test_cast_with_output_param(void)
{
    t_tensr *src;
    t_tensr *dst;

    src = tensr_alloc(1, (size_t[]){2}, DT_I64);
    ((int64_t *)src->data)[0] = 100;
    ((int64_t *)src->data)[1] = 200;

    dst = tensr_alloc(1, (size_t[]){2}, DT_F32);
    dst = tensr_cast(src, DT_F32, dst);
    assert(dst);
    assert(((float *)dst->data)[0] == 100.0f);
    assert(((float *)dst->data)[1] == 200.0f);

    tensr_free(src);
    tensr_free(dst);
}

static void test_cast_same_dtype(void)
{
    t_tensr *src;
    t_tensr *dst;

    src = tensr_alloc(1, (size_t[]){3}, DT_F64);
    ((double *)src->data)[0] = 1.0;
    ((double *)src->data)[1] = 2.0;
    ((double *)src->data)[2] = 3.0;

    dst = tensr_cast(src, DT_F64, NULL);
    assert(dst);
    assert(((double *)dst->data)[0] == 1.0);
    assert(((double *)dst->data)[1] == 2.0);
    assert(((double *)dst->data)[2] == 3.0);

    tensr_free(src);
    tensr_free(dst);
}

static void test_cast_2d_tensor(void)
{
    t_tensr *src;
    t_tensr *dst;

    src = tensr_alloc(2, (size_t[]){2, 3}, DT_U8);
    ((uint8_t *)src->data)[0] = 10;
    ((uint8_t *)src->data)[3] = 20;
    ((uint8_t *)src->data)[5] = 30;

    dst = tensr_cast(src, DT_I32, NULL);
    assert(dst);
    assert(dst->layout.ndim == 2);
    assert(dst->layout.shape[0] == 2);
    assert(dst->layout.shape[1] == 3);
    assert(((int32_t *)dst->data)[0] == 10);
    assert(((int32_t *)dst->data)[3] == 20);
    assert(((int32_t *)dst->data)[5] == 30);

    tensr_free(src);
    tensr_free(dst);
}

void tensr_cast_tests(void)
{
    test_cast_int_to_float();
    test_cast_float_to_int();
    test_cast_with_output_param();
    test_cast_same_dtype();
    test_cast_2d_tensor();
}