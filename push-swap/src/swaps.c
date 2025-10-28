/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/28 15:48:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	swap(t_stack *stack, int max_index)
{
	int	swap;

	if (!stack->head || stack->size == 1)
		return (-1);
	swap = stack->head->content;
	stack->head->content = stack->head->next->content;
	stack->head->next->content = swap;
	if (stack->head->content < swap && stack->head->index < max_index)
	{
		stack->head->inversions--;
		stack->sorted--;
	}
	swap = stack->head->rank;
	stack->head->rank = stack->head->next->rank;
	stack->head->next->rank = swap;
	return (0);
}

int	sa(t_stack *stack_a, int max_index)
{
	int	err_check;

	err_check = swap(stack_a, max_index);
	if (err_check == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack *stack_b, int max_index)
{
	int	err_check;

	err_check = swap(stack_b, max_index);
	if (err_check == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

// REQUIRES TESTING:
int	ss(t_stack *stack_a, t_stack *stack_b, int max_index)
{
	int	err_check_a;
	int	err_check_b;

	err_check_a = sa(stack_a, max_index);
	err_check_b = sb(stack_b, max_index);
	if (err_check_a == -1 || err_check_b == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
