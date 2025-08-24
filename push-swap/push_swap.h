/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/25 00:46:24 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// DOUBLY CIRCULAR LINKED LIST
typedef struct s_list
{
	int				content;
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*head;
	size_t	size;
	int	min;
	int	max;
}	t_stack;


typedef struct s_fmt
{
	int	i;
	int	len;
	int	errchck;
}		t_fmt;

int		ft_printf(const char *format, ...);
int		ft_printf_ptr(void *ptr);
int		ft_putnbr_fd_len(long long n, int fd);
int		ft_putchar_fd_len(char c, int fd);
int		ft_putstr_fd_len(const char *s, int fd);
int		ft_printf_hex(size_t n, int len, char x);
int		ft_nlen(long long n);

#endif