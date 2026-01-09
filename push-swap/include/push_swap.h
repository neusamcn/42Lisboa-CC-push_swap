/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:46:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 18:07:10 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* DOUBLY CIRCULAR LINKED LIST */
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

typedef struct s_matrix
{
	char	**list;
	int		li;
}				t_matrix;

typedef struct s_tempjoin
{
	char	*temp_join1;
	char	*temp_join2;
	char	*str_args;
}				t_tempjoin;

char	**ft_split_ps(char const *str, char *skip);
long	ft_atol(const char *nptr);

int			err_not_nbr(char *list_item);
int			err_not_unique(int li_row, char **av);
int			err_exceeds_int_limits(char *list_item);
int			err_empty(char *list_item);
void		error(void);

int			freeall(char **splat, size_t j);
void		free_err_stack(t_stack *stack);
void		free_circlst_stack(t_stack *stack);
t_matrix	matrix_err_free(char **list_matrix);

t_stack		*parser(int ac, char **av);
char		*conc_str_args(char *temp_join1, char *str_args);
char		*av_to_str(int ac, char **av);
void		mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont);
t_nodes		link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row);
t_stack		*mk_stack(int max_rows_cont, char **rows_cont);
t_stack		*create_empty_stack(void);

int			is_stack_min(int content, int curr_min);
int			is_stack_max(int content, int curr_max);
int			find_min(t_stack *t_stack);
int			find_max(t_stack *t_stack);
int			rank(t_stack *stack_a, int size2rank);

int			count_node_inversions(t_stack *stack, t_circlist *node); // keep?
void		count_stack_inversions(t_stack *stack); // keep?
void		stack_index_size(t_stack *stack);
int			is_sorted(t_stack *stack_a, t_stack *stack_b);

int			swap(t_stack *stack);
int			sa(t_stack *stack_a);
int			sb(t_stack *stack_b);
int			ss(t_stack *stack_a, t_stack *stack_b);
int			pa(t_stack *stack_a, t_stack *stack_b);
int			pb(t_stack *stack_a, t_stack *stack_b);
int			rotate(t_stack *stack);
int			ra(t_stack *stack_a);
int			rb(t_stack *stack_b);
int			rr(t_stack *stack_a, t_stack *stack_b);
int			rev_rotate(t_stack *stack);
int			rra(t_stack *stack_a);
int			rrb(t_stack *stack_b);
int			rrr(t_stack *stack_a, t_stack *stack_b);

void		pick_algo(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack_a);
void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		radix(t_stack *stack_a, t_stack *stack_b);
void		smart_rot(t_stack *stack_a, int target);
void		rot_ordered(t_stack *stack_a, t_stack *stack_b);

#endif