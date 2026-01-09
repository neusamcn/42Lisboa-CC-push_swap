/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 02:51:25 by ncruz-ne         ###   ########.fr       */
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

// int	rotate_or_reverse(t_stack *stack, t_circlist *current, char stack_name)
// {
// 	if (!stack || !stack->head || !stack->head->next)
// 		return (-1);
// 	if (current->index <= (int)stack->size / 2)
// 	{
// 		while (current != stack->head)
// 		{
// 			if (stack_name == 'a')
// 				ra(stack);
// 			else
// 				rb(stack);
// 		}
// 	}
// 	else
// 	{
// 		while (current != stack->head)
// 		{
// 			if (stack_name == 'a')
// 				rra(stack);
// 			else
// 				rrb(stack);
// 		}
// 	}
// 	return (0);
// }

// void	final_rot(t_stack *stack_a)
// {
// 	t_circlist	*current;
// 	size_t		loop_check;

// 	current = stack_a->head;
// 	while (current->rank != 0 && loop_check++ < stack_a->size)
// 		current = current->next;
// 	rotate_or_reverse(stack_a, current, 'a');
// }

// void	pa_all(t_stack *stack_a, t_stack *stack_b)
// {
// 	while (stack_b->head)
// 	{
// 		if (stack_a->head->rank > stack_b->head->rank + 1)
// 			rra(stack_a);
// 		else
// 			pa(stack_a, stack_b);
// 	}
// }

// int	ordered_not_sorted(t_stack *stack, char stack_name)
// {
// 	t_circlist	*current;
// 	size_t		loop_check;

// 	if (!stack || !stack->head || !stack->head->next)
// 		return (1);
// 	current = stack->head;
// 	loop_check = 0;
// 	while (current->rank != 0 && loop_check++ < stack->size)
// 		current = current->next;
// 	loop_check = 0;
// 	while (loop_check++ < stack->size)
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (current->rank < current->next->rank)
// 				current = current->next;
// 			else
// 				return (0);
// 		}
// 		else
// 		{
// 			if (current->rank > current->next->rank)
// 				current = current->next;
// 			else
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

// void	clear_b(t_stack *stack_a, t_stack *stack_b)
// {
// 	size_t		loop_check;
// 	t_circlist	*current;

// 	if (!stack_b || stack_b->head == NULL || !stack_b->head->next)
// 		return ;
// 	if (ordered_not_sorted(stack_b, 'b') == 0)
// 	{
// 		loop_check = 0;
// 		current = stack_b->head;
// 		while (loop_check++ < stack_b->size)
// 		{
// 			if (current->rank > current->next->rank)
// 				current = current->next;
// 			else
// 				rotate_or_reverse(stack_b, current, 'b');
// 			if (current->rank < current->next->rank)
// 				sb(stack_b);
// 		}
// 	}
// 	pa_all(stack_a, stack_b);
// }


// LLLLLLLLLLLLLLLLLLL START
void	rot_ordered(t_stack *stack_a)
{
	t_circlist	*temp_a;
	int			half;
	int			count;

	temp_a = stack_a->head;
	half = (int)(stack_a->size) / 2;
	count = half;
	while (count > 0)
	{
		temp_a = temp_a->next;
		count--;
	}
	if (temp_a->rank <= half)
		while (stack_a->sorted != 0 || stack_a->head->rank != 0)
			ra(stack_a);
	else
		while (stack_a->sorted != 0 || stack_a->head->rank != 0)
			rra(stack_a);
}

void	smart_rot(t_stack *stack_a, int target)
{
	t_circlist	*temp_a;
	int			count;
	int			size;
	int			countdown;

	size = (int)(stack_a->size);
	countdown = size;
	count = 0;
	temp_a = stack_a->head;
	while (countdown > 0 && ((target + 1 == stack_a->head->rank)
			|| (1 + temp_a->previous->rank == target)))
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

// DEBUG WITH CURRENT TEST_ARGS
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL)
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
	rot_ordered(stack_a);
}
// LLLLLLLLLLLLLLLLL END

// void	sort_max_five(t_stack *stack_a, t_stack *stack_b)
// {
// 	size_t	loop_check;

// 	loop_check = stack_a->size;
// 	while ((stack_a->sorted != 0 && stack_a->head->rank != 0)
// 		|| stack_a->size > 3 || loop_check > 0)
// 	{
// 		if (stack_a->head->rank > stack_a->head->next->rank)
// 			sa(stack_a);
// 		else if (stack_a->head->inversions > 0)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		loop_check--;
// 	}
// 	if (stack_a->size == 3)
// 		sort_three(stack_a);
// 	loop_check = stack_b->size;
// 	while (stack_b->head || loop_check > 0)
// 	{
// 		if (stack_a->head->rank + 1 == stack_b->head->rank)
// 		{
// 			pa(stack_a, stack_b);
// 			loop_check--;
// 		}
// 		else if (stack_b->head->next)
// 			ra(stack_a);
// 		loop_check--;
// 	}
// }

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_a->head || stack_a->size < 1|| !stack_b)
		return (-1);
	else if (stack_a->sorted == 0 && stack_a->head->rank == 0 && stack_b->head == NULL)
		return (1);
	else
		return (0);
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

void	pick_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL)
	{
		if (stack_a->size == 2)
			ra(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
		// if (stack_a->size < 6)
		// 	sort_max_five(stack_a, stack_b);
		else
			radix(stack_a, stack_b);
	}
}

