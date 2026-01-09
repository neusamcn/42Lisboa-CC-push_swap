/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:35:20 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 14:01:38 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	rotate(t_stack *stack)
{
	if (!stack->head || stack->head->previous == stack->head || stack->size < 2)
		return (-1);
	stack->head = stack->head->next;
	stack_index_size(stack);
	count_stack_inversions(stack);
	return (0);
}

int	ra(t_stack *stack_a)
{
	int	err_check;

	err_check = rotate(stack_a);
	if (err_check == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack *stack_b)
{
	int	err_check;

	err_check = rotate(stack_b);
	if (err_check == -1)
		return (-1);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check;

	err_check = rotate(stack_a);
	if (err_check == -1)
		return (-1);
	err_check = rotate(stack_b);
	if (err_check == -1)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}
