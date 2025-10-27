/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/27 21:53:52 by ncruz-ne         ###   ########.fr       */
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
			if (bitmask == 1)
			{
				while (current != stack_b->head)
				{
					if (current->index < (int)stack_b->size / 2)
					{
						rotate(stack_b);
						moves_count++; // tester
						printf("%d: rb\n", moves_count); // tester
					}
					else
					{
						rev_rotate(stack_b);
						moves_count++; // tester
						printf("%d: rrb\n", moves_count); // tester
					}
					if (current == start)
						start = stack_b->head->next;
					current = current->next;
				}
				pa(stack_a, stack_b);
				moves_count++; // tester
				printf("%d: pa(%d)\n", moves_count, stack_a->head->rank); // tester
			}
			else
			{
				if (current->index < (int)stack_b->size / 2)
					current = current->next;
				else
					current = current->previous;
			}
			if (current == start)
				break ;
		}
	}
	return (moves_count);
}

void	radix_atob(t_stack *stack_a, t_stack *stack_b, int moves_count)
{
	int			bitmask;
	int			pos;
	int			rot;
	t_circlist	*start;
	t_circlist	*current;

	pos = find_radix_max_div(stack_a);
	current = stack_a->head;
	rot = 0;
	while (pos >= 0)
	{
		start = stack_a->head;
		while (current != start || rot != 1)
		{
			bitmask = current->rank >> pos & 1;
			if (bitmask == 0)
			{
				while (current != stack_a->head)
				{
					rotate(stack_a);
					moves_count++; // tester
					printf("%d: ra\n", moves_count); // tester
				}
				if (current == start)
					start = stack_a->head->next;
				current = current->next;
				pb(stack_a, stack_b);
				moves_count++; // tester
				printf("%d: pb(%d)\n", moves_count, stack_b->head->rank); // tester
				continue ;
			}
			else
				current = current->next;
			if (current == start && rot == 0)
				rot = 1;
		}
		moves_count = radix_btoa(stack_a, stack_b, pos, moves_count);
		pos--;
	}
}
