/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_and_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/18 19:48:36 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

int	sa(t_stack *stack_a)
{
	t_circlist	*swap_node;

	if (!stack_a->head || stack_a->size == 1)
		return (-1);
	swap_node = malloc(sizeof(t_circlist));
	swap_node->content = stack_a->head->content;
	stack_a->head->content = stack_a->head->next->content;
	stack_a->head->next->content = swap_node->content;
	swap_node->rank = stack_a->head->rank;
	stack_a->head->rank = stack_a->head->next->rank;
	stack_a->head->next->rank = swap_node->rank;
	if (stack_a->head->content > swap_node->content)
		stack_a->head->inversions++;
	free(swap_node);
	return (0);
}

int	sb(t_stack *stack_b)
{
	t_circlist	*swap_node;

	if (!stack_b->head || stack_b->size == 1)
		return (-1);
	swap_node = malloc(sizeof(t_circlist));
	swap_node->content = stack_b->head->content;
	stack_b->head->content = stack_b->head->next->content;
	stack_b->head->next->content = swap_node->content;
	swap_node->rank = stack_b->head->rank;
	stack_b->head->rank = stack_b->head->next->rank;
	stack_b->head->next->rank = swap_node->rank;
	if (stack_b->head->content > swap_node->content)
		stack_b->head->inversions++;
	free(swap_node);
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
	return (0);
}

// REQUIRES TESTING:
int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*push_node;

	if (!stack_b || !stack_b->head || stack_b->size == 0)
		return (-1);
	push_node = stack_b->head;
	if (stack_b->size == 1 || stack_b->head->next == NULL)
	{
		stack_b->head = NULL;
		stack_b->min = 0;
		stack_b->max = 0;
	}
	else
	{
		stack_b->head->previous->next = stack_b->head->next;
		stack_b->head->next->previous = stack_b->head->previous;
		// if (stack_b->min == push_node->content)
		// 	stack_b->min = ;
		// if (stack_b->max == push_node->content)
		// 	stack_b->max = ;
		stack_b->head = stack_b->head->next;
	}
	stack_b->size--;
	stack_b->sorted -= push_node->inversions;
	// add to stack_a
	if (!stack_a->head)
	{
		stack_a->head = push_node;
		push_node->rank = 0;
		push_node->inversions = 0;
		push_node->previous = NULL;
		push_node->next = NULL;
		stack_a->min = push_node->content;
		stack_a->max = push_node->content;
	}
	else
	{
		push_node->next = stack_a->head;
		push_node->previous = stack_a->head->previous;
		stack_a->head->previous->next = push_node;
		stack_a->head->previous = push_node;
		stack_a->head = push_node;
		// push_node->rank = ;
		push_node->inversions = count_node_inversions(stack_a, push_node);
		stack_a->min = is_stack_min(push_node->content, stack_a->min);
		stack_a->max = is_stack_max(push_node->content, stack_a->max);
	}
	stack_a->size++;
	stack_a->sorted += push_node->inversions;
	// need to free the node ?
	return (0);
}

// REQUIRES TESTING:
int	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*push_node;

	if (!stack_a || !stack_a->head || stack_a->size == 0)
		return (-1);
	push_node = stack_a->head;
	if (stack_a->size == 1 || stack_a->head->next == NULL)
	{
		stack_a->head = NULL;
		stack_a->min = 0;
		stack_a->max = 0;
	}
	else
	{
		stack_a->head->previous->next = stack_a->head->next;
		stack_a->head->next->previous = stack_a->head->previous;
		// if (stack_a->min == push_node->content)
		// 	stack_a->min = ;
		// if (stack_a->max == push_node->content)
		// 	stack_a->max = ;
		stack_a->head = stack_a->head->next;
	}
	stack_a->size--;
	stack_a->sorted -= push_node->inversions;
	// add to stack_b
	if (!stack_b->head)
	{
		stack_b->head = push_node;
		push_node->rank = 0;
		push_node->inversions = 0;
		push_node->previous = NULL;
		push_node->next = NULL;
		stack_b->min = push_node->content;
		stack_b->max = push_node->content;
	}
	else
	{
		push_node->next = stack_b->head;
		push_node->previous = stack_b->head->previous;
		stack_b->head->previous->next = push_node;
		stack_b->head->previous = push_node;
		stack_b->head = push_node;
		// push_node->rank = ;
		push_node->inversions = count_node_inversions(stack_b, push_node);
		stack_b->min = is_stack_min(push_node->content, stack_b->min);
		stack_b->max = is_stack_max(push_node->content, stack_b->max);
	}
	stack_b->size++;
	stack_b->sorted += push_node->inversions;
	// need to free the node ?
	return (0);
}
