/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/28 20:44:52 by ncruz-ne         ###   ########.fr       */
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

int	b10_to_b2(int decimal)
{
	int	binary;
	int	remainder;
	int	adjust;

	binary = 0;
	remainder = decimal % 2;
	adjust = 1;
	if (remainder == 0)
	{
		adjust = 10;
		decimal = decimal / 2;
	}
	while (decimal > 0)
	{
		remainder = decimal % 2;
		if (remainder == 0)
			binary = binary * 100;
		else
			binary = (binary * 10) + remainder;
		decimal = decimal / 2;
	}
	return (binary * adjust);
}

// int	find_radix_max_div(t_stack *stack)
// {
// 	int	position;
// 	int	radix_max_div;
// 	int	longest_nb;

// 	if (!stack || !stack->head || stack->min > stack->max)
// 		return (-1);
// 	longest_nb = b10_to_b2((int)stack->size - 1);
// 	position = 1;
// 	radix_max_div = 1;
// 	while (position < ft_nlen(longest_nb))
// 	{
// 		radix_max_div *= 10;
// 		position++;
// 	}
// 	return (radix_max_div);
// }

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
	count_stack_inversions(stack_a);
	return (moves_count);
}

void	radix_atob(t_stack *stack_a, t_stack *stack_b, int moves_count) // tester
{
	int			bit_pos;
	int			max_bits;
	t_circlist	*end;
	t_circlist	*current;

	if (!stack_a->head || stack_a->sorted == 0)
		return ;
	bit_pos = 0;
	max_bits = ft_nlen(b10_to_b2((int)stack_a->size - 1));
	while (bit_pos < max_bits)
	{
		end = stack_a->head->previous;
		current = stack_a->head;
		while (current) // && current != current->next
		{
			if ((current->rank >> bit_pos & 1) == 0)
			{
				while (current != stack_a->head)
				{
					ra(stack_a);
					// moves_count++; // tester
					// printf("%d: ra\n", moves_count); // tester
				}
				if (current == end || stack_a->size < 3)
					break ;
				else
				{
					current = current->next;
					pb(stack_a, stack_b);
					// moves_count++; // tester
					// printf("%d: pb(%d)\n", moves_count, stack_b->head->rank); // tester
					continue ;
				}
			}
			else if (current == end)
				break ;
			else
				current = current->next;
		}
		moves_count = pa_all(stack_a, stack_b, moves_count);
		// moves_count = radix_btoa(stack_a, stack_b, bit_pos, moves_count);
		bit_pos++;
	}
}
