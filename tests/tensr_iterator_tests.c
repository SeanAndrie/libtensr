/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_iterator_tests.c                             :::      ::::::::   */
/*                                                    :-:       :-:   :-:      */
/*   By: opencode <opencore@student.42abudhabi.ae>   ::::   :::::: ::::       */
/*                                                ..######::###::###::####..   */
/*   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              */
/*   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

static void test_iter_basic(void)
{
    t_tensr *t;
    t_iter it;
    int count;

    t = tensr_alloc(1, (size_t[]){5}, DT_F64);
    assert(iter_init(&t->layout, &it));
    assert(it.total == 5);

    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 5);

    tensr_free(t);
}

static void test_iter_reset(void)
{
    t_tensr *t;
    t_iter it;
    int count;

    t = tensr_alloc(1, (size_t[]){3}, DT_F64);
    assert(iter_init(&t->layout, &it));

    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 3);

    iter_reset(&it);
    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 3);

    tensr_free(t);
}

static void test_iter_2d(void)
{
    t_tensr *t;
    t_iter it;
    int count;

    t = tensr_alloc(2, (size_t[]){3, 4}, DT_F64);
    assert(iter_init(&t->layout, &it));
    assert(it.total == 12);

    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 12);

    tensr_free(t);
}

static void test_iter_3d(void)
{
    t_tensr *t;
    t_iter it;
    int count;

    t = tensr_alloc(3, (size_t[]){2, 3, 4}, DT_F64);
    assert(iter_init(&t->layout, &it));
    assert(it.total == 24);

    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 24);

    tensr_free(t);
}

static void test_iter_scalar(void)
{
    t_tensr *t;
    t_iter it;
    int count;

    t = tensr_alloc(0, NULL, DT_F64);
    assert(iter_init(&t->layout, &it));
    assert(it.total == 1);

    count = 0;
    while (iter_next(&it))
        count++;
    assert(count == 1);

    tensr_free(t);
}

void tensr_iterator_tests(void)
{
    test_iter_basic();
    test_iter_reset();
    test_iter_2d();
    test_iter_3d();
    test_iter_scalar();
}