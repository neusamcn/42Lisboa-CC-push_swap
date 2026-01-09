/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:55:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 17:40:56 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	free_circlst_stack(t_stack *stack)
{
	t_circlist	*current_node;
	t_circlist	*next_node;

	if (!stack || !stack->head)
	{
		free(stack);
		return ;
	}
	current_node = stack->head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		if (current_node == stack->head)
			break ;
	}
	free(stack);
}

void	free_err_stack(t_stack *stack)
{
	t_circlist	*current_node;
	t_circlist	*next_node;

	if (!stack || !stack->head)
	{
		free(stack);
		return ;
	}
	current_node = stack->head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		if (next_node == stack->head)
			break ;
		current_node = next_node;
	}
	free(stack);
}

t_matrix	matrix_err_free(char **list_matrix)
{
	t_matrix	matrix;
	int			li;

	matrix.list = NULL;
	li = 0;
	while (list_matrix[li])
	{
		if (err_not_nbr(list_matrix[li]) == -1
			|| err_empty(list_matrix[li]) == -1
			|| err_exceeds_int_limits(list_matrix[li]) == -1
			|| err_not_unique(li, list_matrix) == -1)
		{
			while (list_matrix[li++])
				freeall(list_matrix, (size_t)li);
			error();
		}
		li++;
	}
	matrix.list = list_matrix;
	matrix.li = li;
	return (matrix);
}
