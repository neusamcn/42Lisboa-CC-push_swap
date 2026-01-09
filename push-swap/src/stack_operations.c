/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:57:59 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 13:23:53 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

t_stack	*create_empty_stack(void)
{
	t_stack	*empty_stack;

	empty_stack = malloc(sizeof(t_stack));
	if (!empty_stack)
		return (NULL);
	empty_stack->head = NULL;
	empty_stack->size = 0;
	empty_stack->min = 1;
	empty_stack->max = -1;
	empty_stack->sorted = 0;
	return (empty_stack);
}

void	stack_index_size(t_stack *stack)
{
	t_circlist	*start;
	t_circlist	*current;
	int			index;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	start = stack->head;
	index = 0;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
		if (current == start)
		{
			stack->size = (size_t)index;
			break ;
		}
	}
}

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->head || stack_a->size < 1 || !stack_b)
		return (-1);
	else if (stack_a->sorted == 0 && stack_a->head->rank == 0
		&& stack_b->head == NULL)
		return (1);
	else
		return (0);
}
