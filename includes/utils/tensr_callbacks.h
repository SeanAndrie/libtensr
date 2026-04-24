/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_callbacks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:30:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:48:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_CALLBACKS_H
# define TENSR_CALLBACKS_H

# include <libft.h>

typedef enum e_dtype	t_dtype;
typedef struct s_tensr	t_tensr;

/*
 ** Element-wise addition: out = a + b
 **
 ** @param a         Pointer to the first element.
 ** @param b         Pointer to the second element.
 ** @param out       Pointer to the output element.
 ** @param dtype     Data type of the elements.
 */
void					add_func(void *a, void *b, void *out, t_dtype dtype);

/*
 ** Element-wise subtraction: out = a - b
 **
 ** @param a         Pointer to the first element.
 ** @param b         Pointer to the second element.
 ** @param out       Pointer to the output element.
 ** @param dtype     Data type of the elements.
 */
void					sub_func(void *a, void *b, void *out, t_dtype dtype);

/*
 ** Element-wise multiplication: out = a * b
 **
 ** @param a         Pointer to the first element.
 ** @param b         Pointer to the second element.
 ** @param out       Pointer to the output element.
 ** @param dtype     Data type of the elements.
 */
void					mul_func(void *a, void *b, void *out, t_dtype dtype);

/*
 ** Element-wise division: out = a / b
 **
 ** @param a         Pointer to the numerator element.
 ** @param b         Pointer to the denominator element.
 ** @param out       Pointer to the output element.
 ** @param dtype     Data type of the elements.
 */
void					div_func(void *a, void *b, void *out, t_dtype dtype);

/*
 ** Initializes the accumulator for sum reduction.
 **
 ** @param acc       Pointer to the accumulator.
 ** @param dtype     Data type of the elements.
 */
void					sum_init(void *acc, t_dtype dtype);

/*
 ** Initializes the accumulator for max reduction.
 **
 ** @param acc       Pointer to the accumulator.
 ** @param dtype     Data type of the elements.
 */
void					max_init(void *acc, t_dtype dtype);

/*
 ** Initializes the accumulator for min reduction.
 **
 ** @param acc       Pointer to the accumulator.
 ** @param dtype     Data type of the elements.
 */
void					min_init(void *acc, t_dtype dtype);

/*
 ** Applies sum reduction: acc += value
 **
 ** @param acc       Pointer to the accumulator.
 ** @param value     Pointer to the value to add.
 ** @param dtype     Data type of the elements.
 */
void					sum_apply(void *acc, const void *value, t_dtype dtype);

/*
 ** Applies max reduction: acc = max(acc, value)
 **
 ** @param acc       Pointer to the accumulator.
 ** @param value     Pointer to the value to compare.
 ** @param dtype     Data type of the elements.
 */
void					max_apply(void *acc, const void *value, t_dtype dtype);

/*
 ** Applies min reduction: acc = min(acc, value)
 **
 ** @param acc       Pointer to the accumulator.
 ** @param value     Pointer to the value to compare.
 ** @param dtype     Data type of the elements.
 */
void					min_apply(void *acc, const void *value, t_dtype dtype);

/*
 ** Finalizes mean calculation: acc = acc / count
 **
 ** @param acc       Pointer to the accumulator.
 ** @param count     Number of elements summed.
 ** @param dtype     Data type of the elements.
 */
void					mean_finalize(void *acc, size_t count, t_dtype dtype);

t_bool					is_greater(const void *a, const void *b, t_dtype dtype);

#endif
