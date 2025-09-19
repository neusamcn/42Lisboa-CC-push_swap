#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:32:52 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/09/19 01:27:30 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -I.

OBJS = push_swap.o input_parser.o free_stack.o find_stack_members.o \
	stack_operations.o err_handler.o swaps_and_pushes.o rotate_and_reverse.o \


OBJS_BONUS = 

TEST_ARGS = 3 4 # 1 2 5000 7 2147483647 3 9 -3 388 -25 5 0 -2147483648

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus: .bonus

.bonus: $(NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_BONUS) -o $(NAME)
	touch .bonus

valgrind: $(NAME)
	valgrind --log-file=valgrind_log --leak-check=full --show-leak-kinds=all -s \
	./$(NAME) $(TEST_ARGS) > test_output.txt

clean:
	-rm -f $(OBJS) $(MAIN_OBJS) $(OBJS_BONUS) .bonus
	make -C libft clean

fclean: clean
	-rm -f $(NAME) $(EXEC)
	make -C libft fclean

re: fclean all

tclean:
	rm -f valgrind_log
	rm -f test_output.txt

.PHONY: all bonus clean fclean re run valgrind tclean