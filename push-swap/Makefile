#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:32:52 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/09/22 21:13:30 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
HEADER = include/push_swap.h

LIBFT = libft/libft.a

SRC_DIR = src
OBJ_DIR = obj
SRC_BONUS_DIR = src/bonus
OBJ_BONUS_DIR = obj/bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I.

SRCS = $(SRC_DIR)/err_handler.c $(SRC_DIR)/free_stack.c $(SRC_DIR)/input_parser.c \
	$(SRC_DIR)/main.c $(SRC_DIR)/pre_sort.c $(SRC_DIR)/quick_sort.c \
	$(SRC_DIR)/rotate_and_reverse.c $(SRC_DIR)/sortedness.c \
	$(SRC_DIR)/stack_min_max.c $(SRC_DIR)/stack_operations.c \
	$(SRC_DIR)/swaps_and_pushes.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
SRCS_BONUS =
OBJS_BONUS = 

TEST_DIR = TESTS
TEST_ARGS = 3 4 1 2 # 5000 7 2147483647 9 -3 388 -25 5 0 -2147483648

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Redundant ?
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(TEST_DIR):
	mkdir -p $(TEST_DIR)

bonus: .bonus

.bonus: $(NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME)
	touch .bonus

valgrind: $(NAME) $(TEST_DIR)
	valgrind --log-file=$(TEST_DIR)/valgrind_log --leak-check=full --show-leak-kinds=all -s \
	./$(NAME) $(TEST_ARGS) > $(TEST_DIR)/test_output.txt

clean:
	-rm -f $(OBJS) $(MAIN_OBJS) $(OBJS_BONUS) .bonus
	make -C libft clean

fclean: clean
	-rm -f $(NAME)
	make -C libft fclean
	-rm -fr $(OBJ_DIR)

re: fclean all

tclean:
	rm -f $(TEST_DIR)/valgrind_log
	rm -f $(TEST_DIR)/test_output.txt

.PHONY: all bonus clean fclean re run valgrind tclean