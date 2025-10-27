#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:32:52 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/10/27 20:39:24 by ncruz-ne         ###   ########.fr        #
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
	$(SRC_DIR)/swaps_and_pushes.c $(SRC_DIR)/ranker.c $(SRC_DIR)/ft_split_ps.c \
	$(SRC_DIR)/ft_atoi_ps.c $(SRC_DIR)/radix.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
SRCS_BONUS =
OBJS_BONUS = 

TEST_DIR = TESTS
TEST_ARGS = 1 3 2
# 32 34 5464 -2135344233
# 4 0 "1" 6 2 5 3
# 47641 9299 21173 5918 14069 23633 21426 20878 18485 16744 19102 43542 5543 21225 28907 22286 17046 25362 17889 12926
# "-"2 4 1 2 5000 7 2147483647 9 -3 388 -25 5 0 -2147483648
# fix to be able to work with "-"2 ?

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@make -C libft
	@echo "Libft compiled.\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "/obj created.\n"

# Redundant ?
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "push_swap compiled.\n"

$(TEST_DIR):
	@mkdir -p $(TEST_DIR)
	@echo "/$(TEST_DIR) created.\n"

bonus: .bonus

.bonus: $(NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME)
	touch .bonus

valgrind: $(NAME) $(TEST_DIR)
	@valgrind --log-file=$(TEST_DIR)/valgrind_log.log --leak-check=full --show-leak-kinds=all -s \
	./$(NAME) $(TEST_ARGS) > $(TEST_DIR)/test_output.txt
	@echo "Test run concluded.\n"

clean:
	@-rm -f $(OBJS) $(MAIN_OBJS) $(OBJS_BONUS) .bonus
	@make -C libft clean
	@echo "All object files removed.\n"

fclean: clean
	@-rm -f $(NAME)
	@make -C libft fclean
	@-rm -fr $(OBJ_DIR)
	@echo "Object files and libraries removed.\n"

re: fclean all

tclean:
	@rm -f $(TEST_DIR)/valgrind_log.log
	@rm -f $(TEST_DIR)/test_output.txt
	@rm -fr $(TEST_DIR)
	@echo "Test files and directories removed."

.PHONY: all bonus clean fclean re run valgrind tclean