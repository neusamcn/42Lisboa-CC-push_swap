/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:42:28 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/21 16:53:18 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// quick_sort()
// Hoare's partition
// https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/
// Bentley-McIlroy 3-way partitioning
// https://sedgewick.io/wp-content/themes/sedgewick/talks/2002QuicksortIsOptimal.pdf
// REQUIRES TESTING:
t_stack	*hoares_partition(t_stack *stack)
{
	t_circlist	*swap;
	t_circlist	*pivot;
	t_circlist	*head_current;
	t_circlist	*tail_current;
	// t_stack		*cp_stack;

	if (!stack || !stack->head || stack->size < 2)
		return (stack);
	pivot = stack->head;
	head_current = stack->head;
	tail_current = stack->head->previous;
	swap = malloc(sizeof(t_circlist));
	while (stack && head_current->index < tail_current->index
		&& head_current != tail_current)
	{
		while (head_current->content < pivot->content
			&& head_current->index <= (int)stack->size / 2)
			head_current = head_current->next;
		while (tail_current->content >= pivot->content
			&& tail_current->index >= (int)stack->size / 2)
			tail_current = tail_current->previous;
		if (head_current->index > tail_current->index)
			break ;
		// can't swap on original stack:
		if (head_current->content > tail_current->content)
		{
			// confirm if rank is necessary:
			swap->content = head_current->content;
			swap->rank = head_current->rank;
			head_current->content = tail_current->content;
			head_current->rank = tail_current->rank;
			tail_current->content = swap->content;
			tail_current->rank = swap->rank;
			head_current = head_current->next;
			tail_current = tail_current->previous;
		}
	}
	// count inversions and sortedness?
	free(swap);
	return (stack);
}

// REQUIRES WORKING AND TESTING:
int	traverse2tail(t_stack *stack_a, t_stack *stack_b, int max_index)
{
	t_circlist	*current;
	int			moves_count;

	current = stack_a->head;
	moves_count = 0;
	// iterate through stack_a to find inv == 1 closest to head
	while (current && current->index < max_index)
	{
		// move to head (ra()) and pb()
		if (current->inversions > 1)
		{
			while (current != stack_a->head)
			{
				rotate(stack_a);
				moves_count++;
				printf("%d: ra\n", moves_count);
			}
			if (current == stack_a->head)
			{
				pb(stack_a, stack_b);
				current = stack_a->head;
				moves_count++;
				printf("%d: pb(%d)\n", moves_count, stack_b->head->content);
			}
			continue ;
		}
		current = current->next;
	}
	// needed?:
	// count_stack_inversions(stack_a);
	// count_stack_inversions(stack_b);
	return (moves_count);
}

int	sa_or_ss(t_stack *stack_a, t_stack *stack_b, int max_index, int moves_count)
{
	t_circlist	*current;
	int			anext_bhead;
	int			anext_bnext;

	current = stack_a->head;
	while (current && current->index < max_index)
	{
		if (current->inversions > 0)
		{
			while (current != stack_a->head)
			{
				rotate(stack_a);
				moves_count++;
				printf("%d: ra\n", moves_count);
			}
			if (current == stack_a->head)
			{
				if (stack_b->head && stack_b->size > 1)
				{
					anext_bhead = current->next->content - stack_b->head->content;
					if (anext_bhead < 0)
						anext_bhead *= -1;
					anext_bnext = current->next->content - stack_b->head->next->content;
					if (anext_bnext < 0)
						anext_bnext *= -1;
					if (anext_bhead > anext_bnext)
					{
						ss(stack_a, stack_b, max_index);
						moves_count++;
						printf("%d: ss (sa: %d & %d; sb: %d & %d)\n", moves_count, stack_a->head->content, stack_a->head->next->content, stack_b->head->content, stack_b->head->next->content);
					}
					else if (anext_bhead < anext_bnext)
					{
						sa(stack_a, max_index);
						moves_count++;
						printf("%d: sa (%d & %d)\n", moves_count, stack_a->head->content, stack_a->head->next->content);
					}
				}
				else if (stack_b->head && stack_b->size < 2)
				{
					sa(stack_a, max_index);
					moves_count++;
					printf("%d: sa (%d & %d)\n", moves_count, stack_a->head->content, stack_a->head->next->content);
				}
			}
		}
		current = current->next;
	}
	// needed?:
	// count_stack_inversions(stack_a);
	// count_stack_inversions(stack_b);
	return (moves_count);
}
// IF STACK_A IS SORTED == 0
// { SORT STACK_B TO SORTED == 0 ??
// AND/OR
// ROTATE STACK_A TO PA() }

// REQUIRES WORKING AND TESTING:
int		traverse2head(t_stack *stack_a, t_stack *stack_b, int max_index, int moves_count)
{
	t_circlist	*current_a;
	t_circlist	*current_b;
	t_circlist	*start_a;

	if (!stack_a || !stack_a->head)
		return (moves_count);
	current_a = stack_a->head;
	start_a = stack_a->head;
	current_b = stack_b->head;
	// iterate through stack_a to find current_a->rank + 1 in stack_b->head
	while (current_a && current_b)
	{
		// if (current_a->rank == current_a->next->rank + 1 ||
		// 	current_a->rank == current_a->next->rank - 1 ||
		// 	current_a->rank == current_a->previous->rank + 1 ||
		// 	current_a->rank == current_a->previous->rank - 1)
		// {
		// 	if (current_a->rank < max_index / 2)
		// 	{
		// 		while (current_a != stack_a->head)
		// 		{
		// 			rotate(stack_a);
		// 			moves_count++;
		// 			printf("%d: ra\n", moves_count);
		// 		}
		// 	}
		// 	else
		// 	{
		// 		rev_rotate(stack_a);
		// 		moves_count++;
		// 		printf("%d: rra\n", moves_count);
		// 	}
		// 	sa(stack_a, max_index);
		// 	moves_count++;
		// 	printf("%d: sa (%d & %d)\n", moves_count, stack_a->head->content, stack_a->head->next->content);
		// }
		if (stack_b->head && (current_a->rank == current_b->rank + 1 ||
			(current_a->rank == 0 && current_b->rank == max_index)))
		{
			while (current_a != stack_a->head)
			{
				rotate(stack_a);
				moves_count++;
				printf("%d: ra\n", moves_count);
			}
			current_b = current_b->next;
			pa(stack_a, stack_b);
			moves_count++;
			printf("%d: pa(%d)\n", moves_count, stack_a->head->content);
		}
		current_a = current_a->previous;
		if (!stack_b->head && current_a->index == start_a->index)
			break ;
	}
	// ensure stack_a->min is at head
	// consider separating as individual ft() w/ check !stack_b->head
	if (!stack_b->head)
		count_stack_inversions(stack_a);
	while (stack_a->head->content != stack_a->min)
	{
		rotate(stack_a);
		moves_count++;
		printf("%d: ra\n", moves_count);
	}
	// needed?:
	// count_stack_inversions(stack_a);
	// count_stack_inversions(stack_b);
	return (moves_count);
}

// REQUIRES WORKING AND TESTING:
int	inv_algo(t_stack *stack_a, t_stack *stack_b, int max_index)
{
	int	moves;
	
	moves = traverse2tail(stack_a, stack_b, max_index);
	moves = sa_or_ss(stack_a, stack_b, max_index, moves);
	moves = traverse2head(stack_a, stack_b, max_index, moves);
	return (moves);
}

