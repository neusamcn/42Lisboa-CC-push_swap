/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/06 00:57:58 by ncruz-ne         ###   ########.fr       */
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
	int				index;
	int				rank;
	int				inversions; // inversions = rank - index; goal is 0.
	struct s_list	*previous;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*head;
	size_t	size;
	int		min;
	int		max;
	int		sorted; // = SUM(inversions). goal is 0.
}	t_stack;

// ERROR CHECKER FOR FT_PRINTF()
typedef struct s_fmt
{
	int	i;
	int	len;
	int	errchck;
}		t_fmt;

int		ft_atoi(const char *nptr);
int		input_err(char *list_item);
t_stack *mk_stack(int max_rows_cont, char **rows_cont);
t_stack *parser(int ac, char **av);
void    free_circlst_stack(t_stack *stack);
void    free_err_stack(t_stack *stack);
int		ft_printf(const char *format, ...);
int		ft_printf_ptr(void *ptr);
int		ft_putnbr_fd_len(long long n, int fd);
int		ft_putchar_fd_len(char c, int fd);
int		ft_putstr_fd_len(const char *s, int fd);
int		ft_printf_hex(size_t n, int len, char x);
int		ft_nlen(long long n);
t_list	*ft_circlstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif