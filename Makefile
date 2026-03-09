# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:53:36 by sgadinga          #+#    #+#              #
#    Updated: 2026/03/10 01:16:01 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libtensr.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes -Iincludes/utils/ -Iincludes/core -I../libft/includes
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

TENSR_MODULES := $(addprefix tensr/, \
				 	$(addprefix dtype/, arr_i32.c arr_i64.c arr_f32.c arr_f64.c) \
				 	$(addprefix alloc/, tensr_alloc.c tensr_copy.c tensr_linspace.c tensr_broadcast.c tensr_reduced.c tensr_from_arr.c tensr_get.c tensr_set.c) \
					$(addprefix iterator/, iter_init.c iter_next.c iter_reset.c) \
					$(addprefix view/, tensr_view.c tensr_permute.c tensr_reshape.c tensr_transpose.c tensr_slice.c) \
					$(addprefix layout/, layout_alloc.c layout_copy.c layout_shape_eq.c layout_free.c) \
					$(addprefix tensor/, tensr_elementwise.c tensr_reduce.c tensr_reduce_strided.c tensr_free.c tensr_offset.c tensr_is_contiguous.c tensr_equal.c tensr_equal_eps.c tensr_cast.c ))

TENSR_MATH_MODULES := $(addprefix math/, \
						$(addprefix callbacks/, add_func.c sub_func.c mul_func.c div_func.c sum_reduce.c max_reduce.c min_reduce.c mean_reduce.c) \
  						$(addprefix elementwise/, tensr_abs.c tensr_add.c tensr_mul.c tensr_sub.c tensr_div.c tensr_neg.c tensr_sqrt.c tensr_clamp.c) \
						$(addprefix reductions/, tensr_sum.c tensr_max.c tensr_min.c tensr_mean.c) \
						$(addprefix linalg/, tensr_dot.c tensr_cross.c tensr_norm.c tensr_matmul.c tensr_normalize.c ))

TENSR_DEBUG_FNS := $(addprefix debug/, tensr_metadata.c tensr_print.c)

SRCS := $(addprefix $(SRC_DIR)/, $(TENSR_MODULES) $(TENSR_MATH_MODULES) $(TENSR_DEBUG_FNS))
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
