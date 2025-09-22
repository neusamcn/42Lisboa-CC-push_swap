/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortedness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:04:57 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/22 20:03:37 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	count_node_inversions(t_stack *stack, t_circlist *node)
{
	int			inversions;
	t_circlist	*current;
	t_circlist	*start;

	inversions = 0;
	current = stack->head;
	start = stack->head;
	while (current != NULL)
	{
		if (current->content == node->content)
		{
			while (current)
			{
				current = current->next;
				if (current == start)
					return (inversions);
				if (node->content > current->content)
					inversions++;
			}
		}
		current = current->next;
		if (current == start)
			break ;
	}
	return (inversions);
}

// REQUIRES TESTING:
void	count_stack_inversions(t_stack *stack)
{
	t_circlist	*start;

	start = stack->head;
	while (stack && stack->head)
	{
		stack->head->inversions = count_node_inversions(stack, stack->head);
		stack->sorted += stack->head->inversions;
		stack->head = stack->head->next;
		if (stack->head == start)
			break ;
	}
}
