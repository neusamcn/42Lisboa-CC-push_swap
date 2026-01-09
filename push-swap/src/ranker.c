/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:19:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 17:47:36 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	rank(t_stack *stack, int size2rank)
{
	t_circlist	*current;
	t_circlist	*start;
	int			max;

	if (!stack || !stack->head)
		return (-1);
	max = stack->max;
	current = stack->head;
	start = current->previous;
	while (max >= stack->min && size2rank >= 0)
	{
		if (current->content == max)
		{
			current->rank = size2rank;
			size2rank--;
			start = current->previous;
		}
		if (current == start)
			max--;
		current = current->next;
	}
	if (size2rank != -1)
		return (-1);
	return (0);
}
