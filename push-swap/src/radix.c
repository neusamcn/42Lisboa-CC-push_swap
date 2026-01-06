/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/06 00:26:05 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	stack_index_size(t_stack *stack)
{
	t_circlist	*start;
	t_circlist	*current;
	int			index;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	start = stack->head;
	index = 0;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
		if (current == start)
		{
			stack->size = (size_t)index;
			break ;
		}
	}
}

int	pa_all(t_stack *stack_a, t_stack *stack_b, int moves_count) // tester
{
	if (!stack_b->head || !stack_a)
		return (moves_count);
	while (stack_b->head)
	{
		pa(stack_a, stack_b);
		// moves_count++; // tester
		// printf("%d: pa(%d)\n", moves_count, stack_a->head->rank); // tester
	}
	stack_index_size(stack_a);
	count_stack_inversions(stack_a);
	return (moves_count);
}

int	rotate_or_reverse(t_stack *stack, t_circlist *current)
{
	int		index_diff;
	int		next_move;

	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	index_diff = current->index - stack->head->index;
	if (index_diff < (int)stack->size / 2)
	{
		while (current != stack->head)
			ra(stack);
		next_move = 0;
		// current = current->next->next->next;
	}
	else
	{
		while (current != stack->head)
			rra(stack);
		next_move = 1;
		// current = current->previous->previous->previous;
	}
	return (next_move);
}

// DELETE? REQUIRES TESTING:
// , t_stack *stack_b ?
void inv_a(t_stack *stack_a)
{
	t_circlist	*end;
	t_circlist	*current;
	int			next_move;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	end = stack_a->head->previous;
	current = stack_a->head;
	next_move = 0;
	while (next_move != -1 && current != end)
	{
		if (current->rank == current->next->rank + 1)
		{
			stack_index_size(stack_a);
			count_stack_inversions(stack_a);
			next_move = rotate_or_reverse(stack_a, current);
			sa(stack_a);
			// + (int)stack_b->size ?
		}
		if (next_move == 0)
			current = current->next;
		else if (next_move == 1)
			current = current->previous;
	}
}

void	inv_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next || !stack_b)
		return ;
	while (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL)
	{
	// check when is next node->inversions != 0
	// if node->index > size / 2 rra() before sa()
	// if node->index <= size / 2 ra() before sa()
	}
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	bit;
	size_t			i;
	size_t			max_size;

	if (!stack_a || !stack_a->head || !stack_a->head->next || !stack_b)
		return ;
	bit = 1;
	i = 0;
	max_size = stack_a->size;
	while (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL)
	{
		while (max_size != i)
		{
			if ((stack_a->head->rank & bit) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (stack_b->head != NULL)
			pa(stack_a, stack_b);
		i = 0;
		bit = bit << 1;
	}
}

