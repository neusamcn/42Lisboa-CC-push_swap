/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/30 18:02:39 by ncruz-ne         ###   ########.fr       */
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

int	ft_max_bits(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	max_rank;

	if (stack_b->head)
		return (-1);
	max_bits = 0;
	stack_index_size(stack_a);
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
// tester moves_count
// void	radix(t_stack *stack_a, t_stack *stack_b, int moves_count)
// {
// 	int			bit_pos;
// 	int			max_bits;
// 	t_circlist	*end;
// 	t_circlist	*current;

// 	if (!stack_a->head || stack_a->sorted == 0)
// 		return ;
// 	bit_pos = 0;
// 	max_bits = ft_max_bits(stack_a);
// 	// max_bits = ft_nlen(b10_to_b2((int)stack_a->size - 1));
// 	while (bit_pos < max_bits)
// 	{
// 		end = stack_a->head->previous;
// 		current = stack_a->head;
// 		while (current)
// 		{
// 			if ((current->rank >> bit_pos & 1) == 0)
// 			{
// 				while (current != stack_a->head)
// 				{
// 					ra(stack_a);
// 					// moves_count++; // tester
// 					// printf("%d: ra\n", moves_count); // tester
// 				}
// 				if (current == end || stack_a->size < 3)
// 					break ;
// 				current = current->next;
// 				pb(stack_a, stack_b);
// 				// moves_count++; // tester
// 				// printf("%d: pb(%d)\n", moves_count, stack_b->head->rank); // tester
// 				continue ;
// 			}
// 			else if (current == end)
// 				break ;
// 			current = current->next;
// 		}
// 		// inv_a(stack_a); // , stack_b ?
// 		moves_count = pa_all(stack_a, stack_b, moves_count);
// 		bit_pos++;
// 	}
// }

 // tester moves_count
void	radix(t_stack *stack_a, t_stack *stack_b, int moves_count)
{
	int			bit_pos;
	int			max_bits;
	t_circlist	*end;

	if (!stack_a->head || stack_a->sorted == 0)
		return ;
	bit_pos = 0;
	max_bits = ft_max_bits(stack_a, stack_b);
	if (max_bits == -1)
		return ;
	end = stack_a->head->previous;
	while (bit_pos < max_bits)
	{
		if ((stack_a->head->rank >> bit_pos & 1) == 0)
			pb(stack_a, stack_b);
		if ((stack_a->head->rank >> bit_pos & 1) == 1)
			ra(stack_a);
		if (stack_a->head == end)
		{
			ra(stack_a);
			moves_count = pa_all(stack_a, stack_b, moves_count);
			end = stack_a->head->previous;
			bit_pos++;
		}
	}
}
