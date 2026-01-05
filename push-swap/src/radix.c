/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/05 23:50:12 by ncruz-ne         ###   ########.fr       */
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


// tester. NEEDS FIXING? :
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

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	bit;
	size_t			i;
	size_t			max_size;

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

