/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:45:50 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/28 15:47:55 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// Consider generalising the function to pop any node of stack
// REQUIRES TESTING:
int	pop_stack_head(t_stack *stack, t_circlist *pop_node)
{
	// Save references before unlinking
	t_circlist *old_head;
	t_circlist *new_head;

	old_head = stack->head;
	new_head = old_head->next;
	if (!stack || !stack->head || stack->head != pop_node || stack->size == 0)
		return (-1);
	if (stack->head->next == stack->head || stack->size == 1)
	{
		// Detaching the only node leaves the stack empty
		stack->head = NULL;
		// min & max representation for empty. use for flags later
		// Optional: leave min/max unchanged or set to neutral; avoid odd sentinels
		stack->min = 1;
		stack->max = -1;
		// Scrub the popped node to a self-loop to avoid accidental traversal UB
		pop_node->next = pop_node;
		pop_node->previous = pop_node;
	}
	else
	{
		// Unlink the current head from the circular list
		old_head->previous->next = old_head->next;
		old_head->next->previous = old_head->previous;

		// Advance head to a node that is still inside the list BEFORE recomputing min/max
		stack->head = new_head;

		// Recompute min/max if necessary using a valid head that belongs to the list
		// Revise in case RANKING becomes necessary:
		if (stack->min == pop_node->content)
			stack->min = find_min(stack);
		if (stack->max == pop_node->content)
			stack->max = find_max(stack);
		// Scrub the detached node to a self-loop for safety
		pop_node->next = pop_node;
		pop_node->previous = pop_node;
	}
	stack->size--;
	stack->sorted -= pop_node->inversions;
	return (0);
}

// Consider generalising the function to push any node of stack
// REQUIRES TESTING:
int	push_stack_head(t_stack *stack, t_circlist *push_node)
{
	if (!stack || !push_node)
		return (-1);
	if (!stack->head)
	{
		stack->head = push_node;
		// push_node->rank = 0;
		push_node->inversions = 0;
		push_node->previous = push_node;
		push_node->next = push_node;
		stack->min = push_node->content;
		stack->max = push_node->content;
	}
	else
	{
		push_node->next = stack->head;
		push_node->previous = stack->head->previous;
		stack->head->previous->next = push_node;
		stack->head->previous = push_node;
		stack->head = push_node;
		// push_node->rank = ;
		// push_node->inversions = count_node_inversions(stack, push_node);
		stack->min = is_stack_min(push_node->content, stack->min);
		stack->max = is_stack_max(push_node->content, stack->max);
	}
	stack->size++;
	// stack->sorted += push_node->inversions;
	return (0);
}

// Consider later to have only push(source, dest);
int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*push_node;

	if (!stack_a || !stack_b || !stack_b->head || stack_b->size == 0)
		return (-1);
	push_node = stack_b->head;
	if (pop_stack_head(stack_b, push_node) == -1)
		return (-1);
	if (push_stack_head(stack_a, push_node) == -1)
		return (-1);
	stack_index(stack_a); // add due to radix
	stack_index(stack_b); // add due to radix
	write(1, "pa\n", 3);
	return (0);
}

// Consider later to have only push(source, dest);
int	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*push_node;

	if (!stack_b || !stack_a || !stack_a->head || stack_a->size == 0)
		return (-1);
	push_node = stack_a->head;
	if (pop_stack_head(stack_a, push_node) == -1)
		return (-1);
	if (push_stack_head(stack_b, push_node) == -1)
		return (-1);
	stack_index(stack_a); // add due to radix
	stack_index(stack_b); // add due to radix
	write(1, "pb\n", 3);
	return (0);
}
