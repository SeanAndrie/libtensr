# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:53:36 by sgadinga          #+#    #+#              #
#    Updated: 2026/05/14 01:54:30 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libtensr.a
CC := cc
OPTIM_FLAGS := -O3 -ffast-math -funroll-loops -fno-signed-zeros -march=native
CFLAGS := -Wall -Werror -Wextra -Iincludes -Iincludes/tensr -Iincludes/utils -I../libft/includes -I../harena/includes
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

TENSR_CALLBACKS := $(addprefix callbacks/, \
					$(addprefix func/, add_func.c sub_func.c mul_func.c div_func.c is_greater.c is_less.c) \
					$(addprefix sum/, sum_init.c sum_apply.c) \
					$(addprefix max/, max_init.c max_apply.c) \
					$(addprefix mean/, mean_finalize.c) \
					$(addprefix min/, min_init.c min_apply.c))

TENSR_MATH_MODULES := $(addprefix math/, $(TENSR_CALLBACKS) \
                      $(addprefix elementwise/, tensr_elementwise.c tensr_abs.c tensr_add.c tensr_mul.c tensr_sub.c tensr_div.c tensr_neg.c tensr_sqrt.c tensr_clamp.c tensr_scale.c) \
                      $(addprefix reductions/, tensr_arg.c tensr_reduce_ctx.c tensr_reduce.c tensr_reduce_strided.c tensr_sum.c tensr_max.c tensr_min.c tensr_mean.c tensr_argmax.c tensr_argmin.c) \
                      $(addprefix linalg/, tensr_dot.c tensr_inner.c tensr_cross.c tensr_norm.c tensr_matmul.c tensr_normalize.c) \
					  $(addprefix complex/, tensr_complex.c tensr_cfill.c tensr_cfull.c tensr_clinspace.c tensr_cscale.c tensr_conjugate.c tensr_cdot.c tensr_creal.c tensr_cimag.c tensr_carg.c))

TENSR_MODULES := $(addprefix dtype/, arr_u8.c arr_i32.c arr_i64.c arr_f32.c arr_f64.c arr_c64.c arr_c128.c) \
					$(addprefix alloc/, tensr_alloc.c tensr_copy.c tensr_linspace.c tensr_broadcast.c tensr_reduced.c tensr_from_data.c tensr_from_arr.c tensr_get.c tensr_set.c tensr_scalar.c tensr_full.c) \
					$(addprefix iter/, iter_init.c iter_next.c iter_reset.c) \
					$(addprefix view/, tensr_view.c tensr_permute.c tensr_reshape.c tensr_transpose.c tensr_slice.c) \
					$(addprefix layout/, layout_alloc.c layout_init.c layout_copy.c layout_equal.c layout_reduced.c layout_free.c) \
					$(addprefix utils/, tensr_free.c tensr_offset.c tensr_is_contiguous.c tensr_equal.c tensr_equal_eps.c tensr_cast.c tensr_fill.c tensr_expand_dims.c) \
					$(addprefix context/, tensr_ctx_set.c tensr_ctx_destroy.c tensr_ctx_reset.c tensr_malloc.c) \
					$(addprefix debug/, tensr_info.c tensr_print.c print_complex.c)

SRCS := $(addprefix $(SRC_DIR)/, $(TENSR_MODULES) $(TENSR_MATH_MODULES))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C tests clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C tests fclean
	@rm -f $(NAME)

re: fclean all

test: all
	@$(MAKE) -C tests run

.PHONY: re fclean clean all test
