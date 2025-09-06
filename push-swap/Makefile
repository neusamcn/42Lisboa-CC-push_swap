#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 12:32:52 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/09/06 00:58:15 by ncruz-ne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# If Makefile @ <project root>/TESTS: make <command> -f TESTS/Makefile

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

OBJS = ft_printf.o \
ft_printf_hex.o \
ft_printf_ptr.o \
ft_putnbr_fd_len.o \
ft_putchar_fd_len.o \
ft_putstr_fd_len.o \
ft_nlen.o \
ft_lstlast.o \
ft_lstsize.o \
ft_lstadd_back.o \
ft_lstadd_front.o \
ft_atoi.o \
push_swap.o input_parser.o free_stack.o
# ft_circlstnew.o ft_lstiter.o \


OBJS_BONUS = 

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: .bonus

.bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	touch .bonus

# FOR TESTING ONLY:
MAIN_SRCS = $(wildcard TESTS/main*.c)

MAIN_OBJS = $(MAIN_SRCS:.c=.o)

EXEC = $(MAIN_SRCS:.c=)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): %: %.o $(NAME)
	$(CC) $(CFLAGS) -g $< $(NAME) -o $@

run: $(EXEC)
	@for exe in $(EXEC); do \
		echo "Running $$exe..."; \
		./$$exe; \
	done

# FOR TESTING ONLY:
valgrind: $(EXEC)
	./TESTS/valgrind_all.sh

clean:
	-rm -f $(OBJS) $(MAIN_OBJS) $(OBJS_BONUS) .bonus

fclean: clean
	-rm -f $(NAME) $(EXEC)

re: fclean all

# REMOVE TESTING COMMANDS:
.PHONY: all clean fclean re run valgrind bonus