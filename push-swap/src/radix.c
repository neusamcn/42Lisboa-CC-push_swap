/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/29 23:28:32 by ncruz-ne         ###   ########.fr       */
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

int	ft_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	max_rank;

	max_bits = 0;
	max_rank = (int)stack_a->size - 1;
	while (max_rank > 0)
	{
		max_rank = max_rank / 2;
		max_bits++;
	}
	return (max_bits);
}

// NEEDS FIXING:
int	b10_to_b2(int decimal)
{
	int	binary;
	int	remainder;
	int	adjust;

	binary = 0;
	adjust = 1;
	while (decimal > 0)
	{
		remainder = decimal % 2;
		if (remainder == 0 && binary == 0)
		{
			adjust = adjust * 10;
			decimal = decimal / 2;
			if (decimal < 1)
				return (adjust);
			continue ;
		}
		else if (remainder == 0 && adjust != 1)
			binary = binary * 10;
		else if (remainder == 1)
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

// DELETE?
void inv(t_stack *stack_a)
{
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	if (stack_a->head->rank == stack_a->head->next->rank + 1)
		sa(stack_a, (int)stack_a->size - 1); // tester
}

void	radix(t_stack *stack_a, t_stack *stack_b, int moves_count) // tester
{
	int			bit_pos;
	int			max_bits;
	t_circlist	*end;
	t_circlist	*current;

	if (!stack_a->head || stack_a->sorted == 0)
		return ;
	bit_pos = 0;
	max_bits = ft_max_bits(stack_a);
	// max_bits = ft_nlen(b10_to_b2((int)stack_a->size - 1));
	while (bit_pos < max_bits)
	{
		end = stack_a->head->previous;
		current = stack_a->head;
		while (current)
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
				current = current->next;
				pb(stack_a, stack_b);
				// moves_count++; // tester
				// printf("%d: pb(%d)\n", moves_count, stack_b->head->rank); // tester
				continue ;
			}
			else if (current == end)
				break ;
			current = current->next;
		}
		moves_count = pa_all(stack_a, stack_b, moves_count);
		bit_pos++;
	}
}

// void	radix(t_stack *stack_a, t_stack *stack_b, int moves_count) // tester
// {
// 	int			bit_pos;
// 	int			max_bits;
// 	t_circlist	*end;

// 	if (!stack_a->head || stack_a->sorted == 0)
// 		return ;
// 	bit_pos = 0;
// 	max_bits = ft_max_bits(stack_a);
// 	end = stack_a->head->previous;
// 	// max_bits = ft_nlen(b10_to_b2((int)stack_a->size - 1));
// 	while (bit_pos < max_bits)
// 	{
// 		if ((stack_a->head->rank >> bit_pos & 1) == 0)
// 			pb(stack_a, stack_b);
// 		if ((stack_a->head->rank >> bit_pos & 1) == 1)
// 			ra(stack_a);
// 		if (stack_a->head == end)
// 		{
// 			ra(stack_a);
// 			moves_count = pa_all(stack_a, stack_b, moves_count);
// 			end = stack_a->head->previous;
// 			bit_pos++;
// 		}
// 	}
// }
