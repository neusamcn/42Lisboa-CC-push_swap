/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:42:28 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/23 23:49:36 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
