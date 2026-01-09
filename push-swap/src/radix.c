/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 13:37:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	rot_ordered(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*node_a;
	int			half;
	int			count;

	node_a = stack_a->head;
	half = (int)(stack_a->size) / 2;
	count = half;
	while (count > 0)
	{
		node_a = node_a->next;
		count--;
	}
	if (node_a->rank <= half)
		while (is_sorted(stack_a, stack_b) == 0)
			ra(stack_a);
	else
		while (is_sorted(stack_a, stack_b) == 0)
			rra(stack_a);
}

void	smart_rot(t_stack *stack_a, int target)
{
	t_circlist	*node_a;
	int			count;
	int			size;
	int			countdown;

	size = (int)(stack_a->size);
	countdown = size;
	count = 0;
	node_a = stack_a->head;
	while (countdown > 0 && ((target + 1 == stack_a->head->rank)
			|| (1 + node_a->previous->rank == target)))
	{
		count++;
		countdown--;
	}
	if (count < size)
		ra(stack_a);
	else if (count != size)
		rra(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->rank;
	second = stack_a->head->next->rank;
	third = stack_a->head->next->next->rank;
	if (first > second && first > third)
		ra(stack_a);
	if (second > first && second > third)
		rra(stack_a);
	if (stack_a->head->rank > stack_a->head->next->rank)
		sa(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (is_sorted(stack_a, stack_b) == 0)
		sort_three(stack_a);
	if (stack_b->head->rank == 4 || stack_b->head->rank == 0)
		rb(stack_b);
	while (stack_b->head)
	{
		if (stack_b->head->rank + 1 == stack_a->head->rank)
			pa(stack_a, stack_b);
		if (stack_b->head
			&& stack_a->head->previous->rank + 1 == stack_b->head->rank)
			pa(stack_a, stack_b);
		if (stack_b->head
			&& stack_b->head->rank == 4 && stack_a->head->rank == 0)
			pa(stack_a, stack_b);
		if (stack_b->head)
			smart_rot(stack_a, stack_b->head->rank);
	}
	rot_ordered(stack_a, stack_b);
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
	while (is_sorted(stack_a, stack_b) == 0)
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
