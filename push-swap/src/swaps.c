/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/06 23:27:22 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	swap(t_stack *stack)
{
	t_circlist	*first;
	t_circlist	*second;
	t_circlist	*first_previous;
	t_circlist	*second_next;

	if (!stack->head || !stack->head->next || stack->size < 2)
		return (-1);
	first = stack->head;
	second = first->next;
	first_previous = first->previous;
	second_next = second->next;
	first_previous->next = second;
	second->previous = first_previous;
	second->next = first;
	first->previous = second;
	first->next = second_next;
	second_next->previous = first;
	stack->head = second;
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
