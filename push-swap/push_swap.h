/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/06 15:22:52 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

// DOUBLY CIRCULAR LINKED LIST
typedef struct s_circlist
{
	int				content;
	int				index;
	int				rank;
	int				inversions; // inversions = rank - index; goal is 0.
	struct s_circlist	*previous;
	struct s_circlist	*next;
}					t_circlist;

typedef struct s_stack
{
	t_circlist	*head;
	size_t	size;
	int		min;
	int		max;
	int		sorted; // = SUM(inversions). goal is 0.
}	t_stack;

int		input_err(char *list_item);
t_stack *mk_stack(int max_rows_cont, char **rows_cont);
t_stack *parser(int ac, char **av);
void    free_circlst_stack(t_stack *stack);
void    free_err_stack(t_stack *stack);

#endif