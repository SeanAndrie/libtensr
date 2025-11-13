# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 01:13:04 by sgadinga          #+#    #+#              #
#    Updated: 2025/11/13 15:47:03 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libtensr.a
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iincludes -I../libft/includes
ARCHIVE := ar rcs

SRC_DIR := src
OBJ_DIR := obj

LINALG_MODULES := $(addprefix linalg/, elemwise_ops.c)
DEBUG_MODULES := $(addprefix debug/, tensr_info.c tensr_data.c)
TENSR_MODULES := $(addprefix tensr/, init.c index.c fill.c bcast.c)

SRCS := $(addprefix $(SRC_DIR)/, $(TENSR_MODULES) $(LINALG_MODULES) $(DEBUG_MODULES))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

.PHONY: all fclean clean re
