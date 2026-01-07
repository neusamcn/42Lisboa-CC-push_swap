/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:50:14 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/06 23:52:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// REQUIRES NORME:
int	rev_rotate(t_stack *stack)
{
	if (!stack->head || stack->head->previous == stack->head || stack->size < 2)
		return (-1);
	stack->head = stack->head->previous;
	stack_index_size(stack);
	count_stack_inversions(stack);
	return (0);
}

int	rra(t_stack *stack_a)
{
	int	err_check;

	err_check = rev_rotate(stack_a);
	if (err_check == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack *stack_b)
{
	int	err_check;

	err_check = rev_rotate(stack_b);
	if (err_check == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

// Consider removing due to redundancy
// REQUIRES TESTING:
int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check;

	err_check = rev_rotate(stack_a);
	if (err_check == -1)
		return (-1);
	err_check = rev_rotate(stack_b);
	if (err_check == -1)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
