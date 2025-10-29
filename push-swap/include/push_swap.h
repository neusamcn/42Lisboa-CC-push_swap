/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/29 23:02:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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

char	**ft_split_ps(char const *str, char *skip);
int		ft_atoi_ps(const char *nptr);
int		freeall(char **splat, size_t j);
int		err_not_nbr(char *list_item);
int		err_not_unique(int li_row, char **av);
int		err_exceeds_int_limits(char *list_item);
int		err_empty(char *list_item);
void	error(void);
t_stack	*mk_stack(int max_rows_cont, char **rows_cont);
void	mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont);
t_nodes	link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row);
t_stack	*parser(int ac, char **av);
void	free_circlst_stack(t_stack *stack);
void	free_err_stack(t_stack *stack);
int		is_stack_min(int content, int curr_min);
int		is_stack_max(int content, int curr_max);
int		find_min(t_stack *t_stack);
int		find_max(t_stack *t_stack);
int 	rank(t_stack *stack_a);
int		swap(t_stack *stack, int max_index);
int		sa(t_stack *stack_a, int max_index);
int		sb(t_stack *stack_b, int max_index);
int		ss(t_stack *stack_a, t_stack *stack_b, int max_index);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
int		rotate(t_stack *stack);
int		ra(t_stack *stack_a);
int		rb(t_stack *stack_b);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		rev_rotate(t_stack *stack);
int		rra(t_stack *stack_a);
int		rrb(t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
t_stack	*create_empty_stack(void);
int		count_node_inversions(t_stack *stack, t_circlist *node);
void	count_stack_inversions(t_stack *stack);
t_stack	*hoares_partition(t_stack *stack);
int		traverse2tail(t_stack *stack_a, t_stack *stack_b, int max_index);
int		traverse2head(t_stack *stack_a, t_stack *stack_b, int max_index, int moves_count);
void	sort_sorter(t_stack *stack);
int		sa_or_ss(t_stack *stack_a, t_stack *stack_b, int max_index, int moves_count);
int		inv_algo(t_stack *stack_a, t_stack *stack_b, int max_index);
int		check_rot_only(t_stack *stack_a);
int		min_to_head(t_stack *stack_a, t_stack *stack_b, int max_index, int moves_count);
int		ft_max_bits(t_stack *stack_a);
int		b10_to_b2(int decimal);
// int		find_radix_max_div(t_stack *stack);
void	radix(t_stack *stack_a, t_stack *stack_b, int moves_count);
int		pa_all(t_stack *stack_a, t_stack *stack_b, int moves_count);
void 	inv(t_stack *stack_a);
void	stack_index(t_stack *stack);
// TESTER
void	print_stack(t_stack *stack, char stack_name);

#endif