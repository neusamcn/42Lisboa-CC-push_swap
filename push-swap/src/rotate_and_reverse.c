/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:35:20 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/27 22:54:25 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// REQUIRES NORME:
int	rotate(t_stack *stack)
{
	// t_circlist	*current;
	// t_circlist	*start;

	if (!stack->head || stack->head->previous == stack->head || stack->size < 2)
		return (-1);
	// update head & reset sorted
	stack->head = stack->head->next;
	// current = stack->head;
	// start = stack->head;
	// stack->sorted = 0;
	// // update indexes, inversions & sorted
	// while (current)
	// {
	// 	if (current != start->previous)
	// 	{
	// 		current->index--;
	// 		if (current->content > start->previous->content)
	// 		{
	// 			current->inversions++;
	// 			stack->sorted++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		current->index = stack->size - 1;
	// 		current->inversions = 0;
	// 	}
	// 	current = current->next;
	// 	if (current == start)
	// 		break ;
	// }
	return (0);
}

// Consider removing due to redundancy
// REQUIRES TESTING:
int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check;

	err_check = rotate(stack_a);
	if (err_check == -1)
		return (-1);
	err_check = rotate(stack_b);
	if (err_check == -1)
		return (-1);
	return (0);
}

// REQUIRES NORME:
int	rev_rotate(t_stack *stack)
{
	// t_circlist	*current;
	// t_circlist	*start;

	if (!stack->head || stack->head->previous == stack->head || stack->size < 2)
		return (-1);
	// update head & reset sorted
	stack->head = stack->head->previous;
	// current = stack->head;
	// start = stack->head;
	// stack->sorted = 0;
	// // update indexes, inversions & sorted
	// while (current)
	// {
	// 	if (current == start)
	// 	{
	// 		current->index = 0;
	// 		current->inversions = count_node_inversions(stack, current);
	// 		stack->sorted += current->inversions;
	// 	}
	// 	else
	// 	{
	// 		current->index++;
	// 		if (current->content > start->content)
	// 		{
	// 			current->inversions--;
	// 			stack->sorted--;
	// 		}
	// 	}
	// 	current = current->next;
	// 	if (current == start)
	// 		break ;
	// }
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
	return (0);
}
