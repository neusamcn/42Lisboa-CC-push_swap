/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:30:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/26 21:55:40 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

t_nodes	link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row)
{
	if (!stack->head)
		stack->head = nodes.current;
	if (row <= max_rows)
	{
		nodes.current->previous = nodes.previous;
		if (nodes.previous)
			nodes.previous->next = nodes.current;
		nodes.previous = nodes.current;
		if (row == max_rows)
		{
			nodes.current->next = stack->head;
			stack->head->previous = nodes.current;
		}
	}
	if (row < max_rows)
		nodes.current->next = NULL;
	return (nodes);
}

void	mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont)
{
	t_nodes	nodes;
	int		row;

	nodes.previous = NULL;
	row = 0;
	while (row < max_rows_cont)
	{
		nodes.current = malloc(sizeof(t_circlist));
		if (!nodes.current)
		{
			free_err_stack(stack);
			return ;
		}
		nodes.current->content = ft_atoi(rows_cont[row++]);
		stack->max = is_stack_max(nodes.current->content, stack->max);
		stack->min = is_stack_min(nodes.current->content, stack->min);
		nodes.current->index = stack->size++;
		nodes.current->rank = 0;
		nodes.current->inversions = 0;
		nodes = link_circlst(stack, nodes, max_rows_cont, row);
		nodes.current = nodes.current->next;
	}
}

// REQUIRES TESTING:
t_stack	*mk_stack(int max_rows_cont, char **rows_cont)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	stack->min = ft_atoi(rows_cont[0]);
	stack->max = ft_atoi(rows_cont[0]);
	stack->sorted = 0;
	mk_circlst(stack, max_rows_cont, rows_cont);
	count_stack_inversions(stack);
	printf("rank worked? %d\n", rank(stack));
	return (stack);
}

// REQUIRES TESTING:
t_stack	*parser(int ac, char **av) // should it return a pointer?
{
	int row;
	int	li;
	// t_circlist  *lst_b;
	t_stack *stack_a;
	// t_stack *stack_b;
	char	*temp_join1;
	char	*str_args;
	char	*temp_join2;
	char	**list_matrix;

	row = 1;
	// something's fucking wrong idk what and it doesn't make sense fuck this
	temp_join1 = NULL;
	str_args = NULL;
	while (row < ac)
	{
		if (*av[row] == '\0')
			error();
		temp_join1 = ft_strjoin(av[row], " ");
		if (temp_join1 && str_args)
		{
			temp_join2 = ft_strjoin(str_args, temp_join1);
			free(str_args);
			str_args = NULL;
			str_args = ft_strdup(temp_join2);
			free(temp_join2);
			temp_join2 = NULL;
		}
		else
			str_args = ft_strdup(temp_join1);
		free(temp_join1);
		temp_join1 = NULL;
		row++;
	}
	list_matrix = ft_split_ps(str_args, " \f\n\r\t\v");
	free(str_args);
	str_args = NULL;
	li = 0;
	while (list_matrix[li])
	{
		if (err_not_nbr(list_matrix[li]) == -1
			|| err_exceeds_int_limits(list_matrix[li]) == -1
			|| err_not_unique(li, list_matrix) == -1)
			error();
		li++;
	}
	stack_a = mk_stack(li, list_matrix);
	freeall(list_matrix, (size_t)li);
	return (stack_a);
}
