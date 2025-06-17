# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 17:11:21 by ncruz-ne          #+#    #+#              #
#    Updated: 2025/06/03 14:15:47 by ncruz-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# If Makefile @ <project root>/TESTS: make <command> -f TESTS/Makefile

NAME = getnextline.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

OBJS = get_next_line.o get_next_line_utils.o

OBJS_BONUS = get_next_line_bonus.o get_next_line_utils_bonus.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

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

valgrind: $(EXEC)
	./TESTS/valgrind_all.sh

clean:
	-rm -f $(OBJS) $(MAIN_OBJS)

fclean: clean
	-rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re run valgrind