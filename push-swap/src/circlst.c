/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circlst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:43:14 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 17:43:39 by ncruz-ne         ###   ########.fr       */
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
