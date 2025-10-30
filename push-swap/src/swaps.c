/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/30 17:09:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	swap(t_stack *stack)
{
	t_nodes	top;
	t_nodes	bottom;

	if (!stack->head || !stack->head->next || stack->size < 2)
		return (-1);
	top.previous = stack->head->previous;
	top.current = stack->head;
	bottom.previous = stack->head->next;
	bottom.current = stack->head->next;
	top.previous->next = bottom.previous;
	bottom.previous->previous = top.previous;
	bottom.previous->next = top.current;
	top.current->previous = bottom.previous;
	top.current->next = bottom.current;
	bottom.current->previous = top.current;
	stack->head = bottom.previous;
	stack_index_size(stack);
	count_stack_inversions(stack);
	return (0);
}

// int	swap(t_stack *stack, int max_index)
// {
// 	int	swap;

// 	if (!stack->head || !stack->head->next || stack->size < 2)
// 		return (-1);
// 	swap = stack->head->content;
// 	stack->head->content = stack->head->next->content;
// 	stack->head->next->content = swap;
// 	if (stack->head->content < swap && stack->head->index < max_index)
// 	{
// 		stack->head->inversions--;
// 		stack->sorted--;
// 	}
// 	swap = stack->head->rank;
// 	stack->head->rank = stack->head->next->rank;
// 	stack->head->next->rank = swap;
// 	return (0);
// }

int	sa(t_stack *stack_a)
{
	int	err_check;

	err_check = swap(stack_a);
	if (err_check == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack *stack_b)
{
	int	err_check;

	err_check = swap(stack_b);
	if (err_check == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

// REQUIRES TESTING:
int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check_a;
	int	err_check_b;

	err_check_a = sa(stack_a);
	err_check_b = sb(stack_b);
	if (err_check_a == -1 || err_check_b == -1)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}
