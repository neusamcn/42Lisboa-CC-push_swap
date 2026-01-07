#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:32:52 by ncruz-ne          #+#    #+#              #
#    Updated: 2026/01/07 00:02:38 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
HEADER = include/push_swap.h

LIBFT = libft/libft.a

SRC_DIR = src
OBJ_DIR = obj
# SRC_BONUS_DIR = src/bonus
# OBJ_BONUS_DIR = obj/bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

SRCS = $(SRC_DIR)/err_handler.c $(SRC_DIR)/free_stack.c $(SRC_DIR)/input_parser.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/rotate.c $(SRC_DIR)/reverse.c $(SRC_DIR)/sortedness.c \
	$(SRC_DIR)/stack_min_max.c $(SRC_DIR)/stack_operations.c \
	$(SRC_DIR)/swaps.c $(SRC_DIR)/pushes.c $(SRC_DIR)/ranker.c \
	$(SRC_DIR)/ft_split_ps.c $(SRC_DIR)/ft_atol.c $(SRC_DIR)/radix.c \
	$(SRC_DIR)/inv_sort.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
# SRCS_BONUS =
# OBJS_BONUS = 

# Testing variables' assignments:
DEBUGFLAGS = -g -O0 -fno-omit-frame-pointer
TEST_DIR = TESTS
OBJ_DIR_DB = $(TEST_DIR)/db_obj
OBJS_DEBUG = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR_DB)/%.o,$(SRCS))
NAME_DEBUG = $(TEST_DIR)/push_swap_db
TEST_ARGS = 4 0 "1" 6
# 13844 11822 21121 39887 26951 34912 37038
# 32 34 5464 -2135344233
# 4 0 "1" 6 2 5 3
# 47641 9299 21173 5918 14069 23633 21426 20878 18485 16744 19102 43542 5543 21225 28907 22286 17046 25362 17889 12926
# "-"2 4 1 2 5000 7 2147483647 9 -3 388 -25 5 0 -2147483648
# fix to be able to work with "-"2 ?
# seq -2147483648 101 2147483647 | shuf -n 10 | tr '\n' ' '


$(LIBFT):
	@make -C libft
	@echo "🟢  $(LIBFT) compiled. ✅\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "🟢  $(OBJ_DIR) directory created. ✅\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🟢  $@ created. ✅\n"
# 	@echo "🟢  All object files created. ✅\n"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "🟢  $(NAME) compiled. ✅\n"

# Testing rules:
$(TEST_DIR):
	@mkdir -p $(TEST_DIR)
	@echo "⚙️  $(TEST_DIR) directory created. ✅\n"

$(OBJ_DIR_DB):
	@mkdir -p $(OBJ_DIR_DB)
	@echo "⚙️  $(OBJ_DIR_DB) directory created. ✅\n"

$(OBJ_DIR_DB)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@
	@echo "🟢  $@ created. ✅\n"
#	@echo "⚙️  All object files for debugging created. ✅\n"

$(NAME_DEBUG): $(LIBFT) $(OBJS_DEBUG) | $(TEST_DIR) $(OBJ_DIR_DB)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS_DEBUG) -Llibft -lft -o $(NAME_DEBUG)
	@echo "⚙️  $(NAME_DEBUG) for debugging compiled. ✅\n"


all: $(LIBFT) $(OBJ_DIR) $(NAME)

# bonus: .bonus

# .bonus: $(NAME) $(OBJS_BONUS)
#	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME)
#	touch .bonus

clean:
	@-rm -f $(OBJS)
# $(OBJS_BONUS) .bonus
	@make -C libft clean
	@echo "🗑️  All object files removed.\n"

fclean: clean
	@-rm -f $(NAME)
	@make -C libft fclean
	@-rm -fr $(OBJ_DIR)
	@echo "🗑️  Object files and libraries removed.\n"

re: fclean all

# Testing Make targets to remove test artifacts and debug binary:
tclean:
	@rm -f $(TEST_DIR)/$(NAME_DEBUG)
	@echo "⚙️  push_swap_db for debugging removed. 🗑️\n"
	@rm -f $(OBJ_DIR_DB)/$(OBJS_DEBUG)
	@echo "⚙️  All object files for debugging removed. 🗑️\n"
	@rm -fr $(TEST_DIR)/$(OBJ_DIR_DB)
	@echo "⚙️  $(OBJ_DIR_DB) removed. 🗑️\n"
	@rm -f $(TEST_DIR)/valgrind_log.log
	@rm -f $(TEST_DIR)/test_output.txt
# 	@rm -fr $(TEST_DIR)
	@echo "⚙️   Test files and directories removed. 🗑️"

debug: fclean tclean $(NAME_DEBUG)
	@valgrind --log-file=$(TEST_DIR)/valgrind_log.log --leak-check=full --show-leak-kinds=all -s \
	$(NAME_DEBUG) $(TEST_ARGS) > $(TEST_DIR)/test_output.txt
	@echo "⚙️  Test run concluded. ✅\n"


.PHONY: all clean fclean re tclean debug # bonus