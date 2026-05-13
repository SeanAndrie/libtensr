#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <libft.h>
#include <assert.h>
#include <stdint.h>
#include <libtensr.h>
#include <stdbool.h>

void    tensr_alloc_tests(void);
void    tensr_copy_tests(void);
void    tensr_cast_tests(void);
void    tensr_creation_tests(void);
void    tensr_view_tests(void);
void    tensr_slice_tests(void);
void    tensr_element_access_tests(void);
void    tensr_elementwise_tests(void);
void    tensr_reduction_tests(void);
void    tensr_linalg_tests(void);
void    tensr_complex_tests(void);
void    tensr_iterator_tests(void);

#endif
