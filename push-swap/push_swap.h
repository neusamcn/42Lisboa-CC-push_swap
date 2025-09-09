/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/09 20:59:55 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
// TESTING ONLY:
# include <stdio.h>

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
	t_circlist	*head;
	size_t		size;
	int			min;
	int			max;
	int			sorted;
}				t_stack;

typedef struct s_nodes
{
	t_circlist	*previous;
	t_circlist	*current;
}				t_nodes;

int		err_not_nbr(char *list_item);
int		err_not_unique(int li_row, int ac, char **av);
int		err_exceeds_int_limits(char *list_item);
t_stack	*mk_stack(int max_rows_cont, char **rows_cont);
void	mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont);
t_nodes	link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row);
t_stack	*parser(int ac, char **av);
void	free_circlst_stack(t_stack *stack);
void	free_err_stack(t_stack *stack);
int		find_min(int content, int curr_min);
int		find_max(int content, int curr_max);
int		find_radix_max_div(t_stack *stack);
// int		sa(t_stack *stack_a, t_stack *stack_b);
// int		sb(t_stack *stack_a, t_stack *stack_b);
// int		ss(t_stack *stack_a, t_stack *stack_b);
// int		pa(t_stack *stack_a, t_stack *stack_b);
// int		pb(t_stack *stack_a, t_stack *stack_b);
// int		rotate(t_stack *stack);
// int		rr(t_stack *stack_a, t_stack *stack_b);
// int		rev_rotate(t_stack *stack);
// int		rrr(t_stack *stack_a, t_stack *stack_b);
t_stack	*create_empty_stack(void);
int		count_node_inversions(t_stack *stack, t_circlist *node);
void	count_stack_inversions(t_stack *stack);
// t_stack	*hoares_partition(t_stack *stack);

#endif