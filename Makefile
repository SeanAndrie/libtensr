# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:53:36 by sgadinga          #+#    #+#              #
#    Updated: 2026/04/02 14:40:07 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libtensr.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes -Iincludes/utils/ -Iincludes/tensr_core -Iincludes/tensr_rt -I../libft/includes -O3 -ffast-math
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

TENSR_RT_MODULES := $(addprefix tensr_rt/functional/elementwise/, vec3_add.c vec3_sub.c vec3_mul.c vec3_div.c vec3_neg.c vec3_abs.c) \
					$(addprefix tensr_rt/functional/linalg/, vec3_dot.c vec3_cross.c vec3_normalize.c vec3_scale.c vec3_magnitude.c vec3_magnitude_sq.c vec3_project.c vec3_lerp.c) \
					$(addprefix tensr_rt/inplace/elementwise/, vec3_add_ip.c vec3_sub_ip.c vec3_mul_ip.c vec3_div_ip.c vec3_neg_ip.c vec3_abs_ip.c) \
					$(addprefix tensr_rt/inplace/linalg/, vec3_normalize_ip.c vec3_scale_ip.c vec3_lerp_ip.c) \
					$(addprefix tensr_rt/generic/, vec3_to_tensr.c tensr_to_vec3.c vec3_equal_eps.c)

TENSR_MATH_MODULES := $(addprefix tensr_core/math/, \
						$(addprefix callbacks/, add_func.c sub_func.c mul_func.c div_func.c sum_reduce.c max_reduce.c min_reduce.c mean_reduce.c) \
  						$(addprefix elementwise/, tensr_abs.c tensr_add.c tensr_mul.c tensr_sub.c tensr_div.c tensr_neg.c tensr_sqrt.c tensr_clamp.c tensr_scale.c) \
 						$(addprefix reductions/, tensr_sum.c tensr_max.c tensr_min.c tensr_mean.c) \
 						$(addprefix linalg/, tensr_dot.c tensr_inner.c tensr_cross.c tensr_norm.c tensr_matmul.c tensr_normalize.c))

TENSR_MODULES := $(addprefix tensr_core/, \
					$(addprefix dtype/, arr_u8.c arr_i32.c arr_i64.c arr_f32.c arr_f64.c) \
					$(addprefix alloc/, tensr_alloc.c tensr_copy.c tensr_linspace.c tensr_broadcast.c tensr_reduced.c tensr_from_arr.c tensr_get.c tensr_set.c tensr_scalar.c tensr_full.c ) \
					$(addprefix iterator/, iter_init.c iter_next.c iter_reset.c) \
					$(addprefix view/, tensr_view.c tensr_permute.c tensr_reshape.c tensr_transpose.c tensr_slice.c) \
					$(addprefix layout/, layout_alloc.c layout_init.c layout_copy.c layout_equal.c layout_free.c) \
					$(addprefix tensor/, tensr_elementwise.c tensr_reduce.c tensr_reduce_strided.c tensr_free.c tensr_offset.c tensr_is_contiguous.c tensr_equal.c tensr_equal_eps.c tensr_cast.c tensr_fill.c tensr_expand_dims.c))

TENSR_DEBUG_FNS := $(addprefix debug/, tensr_metadata.c tensr_print.c)

SRCS := $(addprefix $(SRC_DIR)/, $(TENSR_MODULES) $(TENSR_MATH_MODULES) $(TENSR_RT_MODULES) $(TENSR_DEBUG_FNS))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
