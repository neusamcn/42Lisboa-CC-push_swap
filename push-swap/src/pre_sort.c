/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:48:52 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/23 10:33:09 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// REQUIRES INTEGRATION AND TESTING:
void	sort_sorter(t_stack *stack)
{
	t_circlist	*current;
	int			inversions;
	int			sortedness;

	if (stack->sorted == 0 && stack->head->content == stack->min)
		exit(EXIT_SUCCESS);
	current = stack->head;
	// while (sortedness > 0)
	// 	sortedness += --sortedness;
	inversions = stack->size - 1;
	sortedness = inversions;
	// confirm if necessary after final algorithm is done:
	while (current && inversions >= 0)
	{
		if (current->inversions == inversions)
		{
			if (current->index == (int)stack->size - 1 && inversions == 0)
				// return (function w/ optimised ops to reverse stack);
			inversions--;
			sortedness += inversions;
		}
		else
			break ;
		current = current->next;
	}
	// call quick_sort()
}
