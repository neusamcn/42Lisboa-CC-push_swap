/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortedness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:04:57 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/22 17:22:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_node_inversions(t_stack *stack, t_circlist *node)
{
	int			inversions;
	t_circlist	*current;
	// t_circlist	*start;

	inversions = 0;
	current = stack->head;
	// start = stack->head;
	while (current)
	{
		if (current->content == node->content)
		{
			while (current)
			{
				current = current->next;
				if (current->index == 0)
					return (inversions);
				if (node->content > current->content)
					inversions++;
			}
		}
		current = current->next;
		if (current->index == 0)
			break ;
	}
	return (inversions);
}

// REQUIRES TESTING:
void	count_stack_inversions(t_stack *stack)
{
	t_circlist	*current;

	current = stack->head;
	stack->sorted = 0;
	while (current)
	{
		current->inversions = count_node_inversions(stack, current);
		stack->sorted += current->inversions;
		current = current->next;
		if (current->index == 0)
			break ;
	}
}
