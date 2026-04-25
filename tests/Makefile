# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :::      ::::::::    #
#                                                     +:+ ++:      ++:       #
#    By: opencode <opencore@student.42abudhabi.ae>   ::::   ::::  :::        #
#                                                 ..###:   ###: :###:       #
#   Created: 2026/04/25 00:00:00 by opencode          #+#    #+#              #
#   Updated: 2026/04/25 00:00:00 by opencode         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME := test_runner
CC := cc
CFLAGS := -Wall -Werror -Wextra -I. -I../includes -I../includes/tensr -I../includes/utils -I../../libft/includes

LIBFT := ../../libft/libft.a
LIBTENSR := ../libtensr.a

SRC_DIR := .
OBJ_DIR := obj

TEST_FILES := runner.c \
              tensr_alloc_tests.c \
              tensr_copy_tests.c \
              tensr_cast_tests.c \
              tensr_creation_tests.c \
              tensr_view_tests.c \
              tensr_slice_tests.c \
              tensr_element_access_tests.c \
              tensr_elementwise_tests.c \
              tensr_reduction_tests.c \
              tensr_linalg_tests.c \
              tensr_complex_tests.c \
              tensr_iterator_tests.c

SRCS := $(addprefix $(SRC_DIR)/, $(TEST_FILES))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBTENSR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L.. -ltensr -L../../libft -lft -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C ../../libft

$(LIBTENSR):
	@$(MAKE) -s -C ..

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re run