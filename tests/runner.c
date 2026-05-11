#include <test.h>

void tensr_alloc_tests(void);
void tensr_copy_tests(void);
void tensr_cast_tests(void);
void tensr_creation_tests(void);
void tensr_view_tests(void);
void tensr_slice_tests(void);
void tensr_element_access_tests(void);
void tensr_elementwise_tests(void);
void tensr_reduction_tests(void);
void tensr_linalg_tests(void);
void tensr_complex_tests(void);
void tensr_iterator_tests(void);

int main(void)
{
    ft_printf("=== libtensr Test Suite ===\n\n");

    ft_printf("Running tensr_alloc_tests...\n");
    tensr_alloc_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_copy_tests...\n");
    tensr_copy_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_cast_tests...\n");
    tensr_cast_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_creation_tests...\n");
    tensr_creation_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_view_tests...\n");
    tensr_view_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_slice_tests...\n");
    tensr_slice_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_element_access_tests...\n");
    tensr_element_access_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_elementwise_tests...\n");
    tensr_elementwise_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_reduction_tests...\n");
    tensr_reduction_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_linalg_tests...\n");
    tensr_linalg_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_complex_tests...\n");
    tensr_complex_tests();
    ft_printf("  PASSED\n");

    ft_printf("Running tensr_iterator_tests...\n");
    tensr_iterator_tests();
    ft_printf("  PASSED\n");

    ft_printf("\n=== All tests passed! ===\n");
    return (0);
}