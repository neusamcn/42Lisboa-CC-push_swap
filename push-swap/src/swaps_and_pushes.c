/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_and_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/23 23:46:40 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

// Consider later to have only swap(source, dest);
int	sa(t_stack *stack_a, int max_index)
{
	// t_circlist	*swap_node;
	int	swap;

	if (!stack_a->head || stack_a->size == 1)
		return (-1);
	swap = stack_a->head->content;
	stack_a->head->content = stack_a->head->next->content;
	stack_a->head->next->content = swap;
	if (stack_a->head->content < swap && stack_a->head->index < max_index)
	{
		stack_a->head->inversions--;
		stack_a->sorted--;
	}
	// swap_node = malloc(sizeof(t_circlist));
	// swap_node = stack_a->head;
	// // swap_node->content = stack_a->head->content;
	// stack_a->head->content = stack_a->head->next->content;
	// stack_a->head->next->content = swap_node->content;
	// // swap_node->rank = stack_a->head->rank;
	// // stack_a->head->rank = stack_a->head->next->rank;
	// // stack_a->head->next->rank = swap_node->rank;
	// if (stack_a->head->content > swap_node->content)
		// stack_a->head->inversions++;
	// free(swap_node);
	return (0);
}

// Consider later to have only swap(source, dest);
int	sb(t_stack *stack_b)
{
	// t_circlist	*swap_node;
	int	swap;

	if (!stack_b->head || stack_b->size == 1)
		return (-1);
	swap = stack_b->head->content;
	stack_b->head->content = stack_b->head->next->content;
	stack_b->head->next->content = swap;
	// REVIEW:
	// if (stack_b->head->content > swap)
	// {
	// 	stack_b->head->inversions++;
	// 	stack_b->sorted++;
	// }
	// swap_node = malloc(sizeof(t_circlist));
	// swap_node = stack_b->head;
	// // swap_node->content = stack_b->head->content;
	// stack_b->head->content = stack_b->head->next->content;
	// stack_b->head->next->content = swap_node->content;
	// // swap_node->rank = stack_b->head->rank;
	// // stack_b->head->rank = stack_b->head->next->rank;
	// // stack_b->head->next->rank = swap_node->rank;
	// if (stack_b->head->content > swap_node->content)
	// 	stack_b->head->inversions++;
	// free(swap_node);
	return (0);
}

// REQUIRES TESTING:
int	ss(t_stack *stack_a, t_stack *stack_b, int max_index)
{
	int	err_check_a;
	int	err_check_b;

	err_check_a = sa(stack_a, max_index);
	err_check_b = sb(stack_b);
	if (err_check_a == -1 || err_check_b == -1)
		return (-1);
	return (0);
}

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
		push_node->inversions = count_node_inversions(stack, push_node);
		stack->min = is_stack_min(push_node->content, stack->min);
		stack->max = is_stack_max(push_node->content, stack->max);
	}
	stack->size++;
	stack->sorted += push_node->inversions;
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
	return (0);
}
