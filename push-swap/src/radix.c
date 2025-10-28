/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/28 18:34:23 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	stack_index(t_stack *stack)
{
	t_circlist	*start;
	t_circlist	*current;
	int			index;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	start = stack->head;
	index = 0;
	while (current && index < (int)stack->size)
	{
		current->index = index;
		index++;
		current = current->next;
		if (current == start)
			break ;
	}
}

int	radix_btoa(t_stack *stack_a, t_stack *stack_b, int pos, int moves_count)
{
	int			bitmask;
	t_circlist	*start;
	t_circlist	*current;

	current = stack_b->head;
	if (pos >= 0)
	{
		start = stack_b->head;
		while (current)
		{
			bitmask = current->rank >> pos & 1;
			if (bitmask == 1 || (pos == 0 && bitmask == 0))
			{
				while (current != stack_b->head && current->next != current)
				{
					if (current->index < (int)stack_b->size / 2)
					{
						rb(stack_b);
						moves_count++; // tester
						printf("%d: rb\n", moves_count); // tester
					}
					else
					{
						rrb(stack_b);
						moves_count++; // tester
						printf("%d: rrb\n", moves_count); // tester
					}
					if (current == start)
						start = stack_b->head->next;
					current = stack_b->head->next;
				}
				pa(stack_a, stack_b);
				moves_count++; // tester
				printf("%d: pa(%d)\n", moves_count, stack_a->head->rank); // tester
			}
			else if (current->next != current)
			{
				if (current->index < (int)stack_b->size / 2)
					current = current->next;
				else
					current = current->previous;
			}
			if (current == start)
			{
				if (pos > 0)
					break ;
				else
					continue ;
			}
		}
	}
	return (moves_count);
}

int	pa_all(t_stack *stack_a, t_stack *stack_b, int moves_count)
{
	if (!stack_b->head || !stack_a)
		return (moves_count);
	while (stack_b->head)
	{
		pa(stack_a, stack_b);
		moves_count++; // tester
		printf("%d: pa(%d)\n", moves_count, stack_a->head->rank); // tester
	}
	count_stack_inversions(stack_a);
	return (moves_count);
}

void	radix_atob(t_stack *stack_a, t_stack *stack_b, int moves_count)
{
	int			bitmask;
	int			bit_pos;
	int			max_bits;
	t_circlist	*end;
	t_circlist	*current;

	if (!stack_a->head)
		return ;
	bit_pos = 0;
	max_bits = find_radix_max_div(stack_a);
	while (bit_pos <= max_bits)
	{
		end = stack_a->head->previous;
		current = stack_a->head;
		while (current)
		{
			bitmask = current->rank >> bit_pos & 1;
			if (bitmask == 0)
			{
				while (current != stack_a->head) // && current != current->next
				{
					ra(stack_a);
					moves_count++; // tester
					printf("%d: ra\n", moves_count); // tester
				}
				if (current != end && stack_a->size > 2)
				{
					current = current->next;
					pb(stack_a, stack_b);
					moves_count++; // tester
					printf("%d: pb(%d)\n", moves_count, stack_b->head->rank); // tester
					continue ;
				}
				else
					break ;
			}
			else
				current = current->next;
		}
		moves_count = pa_all(stack_a, stack_b, moves_count);
		// moves_count = radix_btoa(stack_a, stack_b, bit_pos, moves_count);
		bit_pos++;
	}
}
