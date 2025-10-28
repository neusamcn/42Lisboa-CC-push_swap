/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:35:20 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/28 15:54:29 by ncruz-ne         ###   ########.fr       */
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
	write(1, "rr\n", 3);
	return (0);
}
