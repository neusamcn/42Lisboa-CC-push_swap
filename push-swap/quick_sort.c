/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:42:28 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/19 23:09:49 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

// quick_sort()
// Hoare's partition
// https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/
// REQUIRES TESTING:
t_stack	*hoares_partition(t_stack *stack)
{
	t_circlist	*swap;
	t_circlist	*pivot;
	t_circlist	*head_current;
	t_circlist	*tail_current;
	// t_stack		*cp_stack;

	if (!stack || !stack->head || stack->size <= 1)
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
int	freestylin(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*current;
	int			inversions;
	int			moves_count;

	inversions = 1;
	moves_count = 0;
	current = stack_a->head;
	// iterate through stack_a to find inv == 1 closest to head
	while (current)
	{
		if (current->inversions > (int)stack_a->size / 2)
		{
			// move to head (ra()) and pb()
			while (current != stack_a->head)
			{
				rotate(stack_a);
				moves_count++;
			}
			if (current == stack_a->head)
			{
				pb(stack_a, stack_b);
				moves_count++;
				count_stack_inversions(stack_a);
				count_stack_inversions(stack_b);
			}
			continue ;
		}
		if (current->inversions == inversions)
		{
			// move to head (ra()) and use sa()
			while (current != stack_a->head)
			{
				rotate(stack_a);
				moves_count++;
			}
			if (current == stack_a->head)
			{
				sa(stack_a);
				moves_count++;
				count_stack_inversions(stack_a);
			}
			continue ;
		}
		if (current == stack_a->head->previous
			&& inversions < (int)stack_a->size / 2)
			inversions++;
		else if (current->index == (int)stack_a->size - 1)
			break ;
		current = current->next;
		moves_count++;
	}
	return (moves_count);
}
