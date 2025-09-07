/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/07 15:29:30 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// DOUBLY CIRCULAR LINKED LIST
typedef struct s_circlist
{
	int					content;
	int					index;
	int					rank;
	int					inversions;
	struct s_circlist	*previous;
	struct s_circlist	*next;
}						t_circlist;

typedef struct s_stack
{
	t_circlist			*head;
	size_t				size;
	int					min;
	int					max;
	int					sorted;
}						t_stack;

typedef struct s_nodes
{
	t_circlist			*previous;
	t_circlist			*current;
}						t_nodes;

int		input_err(char *list_item);
t_stack	*mk_stack(int max_rows_cont, char **rows_cont);
void	mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont);
t_nodes	link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row);
t_stack	*parser(int ac, char **av);
void	free_circlst_stack(t_stack *stack);
void	free_err_stack(t_stack *stack);

#endif