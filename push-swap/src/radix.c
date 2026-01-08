/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/08 00:50:01 by ncruz-ne         ###   ########.fr       */
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

int	rotate_or_reverse(t_stack *stack, t_circlist *current, char stack_name)
{
	if (!stack || !stack->head || !stack->head->next)
		return (-1);
	if (current->index <= (int)stack->size / 2)
	{
		while (current != stack->head)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (current != stack->head)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
	return (0);
}

void	final_rot(t_stack *stack_a)
{
	t_circlist	*current;
	size_t		loop_check;

	current = stack_a->head;
	while (current->rank != 0 && loop_check++ < stack_a->size)
		current = current->next;
	rotate_or_reverse(stack_a, current, 'a');
}

void	pa_all(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->head)
	{
		if (stack_a->head->rank > stack_b->head->rank + 1)
			rra(stack_a);
		else
			pa(stack_a, stack_b);
	}
}

int	ordered_not_sorted(t_stack *stack, char stack_name)
{
	t_circlist	*current;
	size_t		loop_check;

	if (!stack || !stack->head || !stack->head->next)
		return (1);
	current = stack->head;
	loop_check = 0;
	while (current->rank != 0 && loop_check++ < stack->size)
		current = current->next;
	loop_check = 0;
	while (loop_check++ < stack->size)
	{
		if (stack_name == 'a')
		{
			if (current->rank < current->next->rank)
				current = current->next;
			else
				return (0);
		}
		else
		{
			if (current->rank > current->next->rank)
				current = current->next;
			else
				return (0);
		}
	}
	return (1);
}

// void	sort_five(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	head_a;
// 	int	head_next_a;

// 	if (!stack_a || !stack_a->head || !stack_a->head->next || !stack_b)
// 		return ;
// 	while (stack_a->sorted != 0 || stack_a->head->rank != 0
// 		|| stack_b->head != NULL)
// 	{
// 		head_a = stack_a->head->rank;
// 		head_next_a = stack_a->head->next->rank;
// 		if (stack_a->head->inversions != 0
// 			&& (head_a - head_next_a > 1 || head_a - head_next_a < -1))
// 			pb(stack_a, stack_b);
// 		if (stack_a->size == 4)
// 			sort_four(stack_a, stack_b);
// 		if (stack_a->size == 3)
// 		{}
// 	}
// }

void	clear_b(t_stack *stack_a, t_stack *stack_b)
{
	size_t		loop_check;
	t_circlist	*current;

	if (!stack_b || stack_b->head == NULL || !stack_b->head->next)
		return ;
	if (ordered_not_sorted(stack_b, 'b') == 0)
	{
		loop_check = 0;
		current = stack_b->head;
		while (loop_check++ < stack_b->size)
		{
			if (current->rank > current->next->rank)
				current = current->next;
			else
				rotate_or_reverse(stack_b, current, 'b');
			if (current->rank < current->next->rank)
				sb(stack_b);
		}
	}
	pa_all(stack_a, stack_b);
}

void	inv_check(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*current_a;
	t_circlist	*current_b;
	size_t		loop_check;

	current_a = stack_a->head;
	if (ordered_not_sorted(stack_a, 'a') == 0)
	{
		loop_check = 0;
		while (current_a->inversions == 0 && loop_check++ < stack_a->size)
			current_a = current_a->next;
	}
	if (stack_a->size > 1 && current_a->inversions > 0)
		rotate_or_reverse(stack_a, current_a, 'a');
	if (stack_b->head != NULL)
	{
		current_b = stack_b->head;
		loop_check = 0;
		while (current_b->rank > stack_a->head->rank
			&& loop_check++ < stack_b->size)
			current_b = current_b->next;
		rotate_or_reverse(stack_b, current_b, 'b');
	}
	if (stack_a->size > 1)
		pb(stack_a, stack_b);
}

// DEBUG WITH CURRENT TEST_ARGS
void	sort_max_five(t_stack *stack_a, t_stack *stack_b)
{
	size_t	loop_check;
	if (!stack_a || !stack_a->head || !stack_a->head->next || !stack_b)
		return ;
	loop_check = 0;
	while (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL || loop_check++ < stack_a->size)
	{
		if (ordered_not_sorted(stack_a, 'a') == 1)
		{
			if (stack_b->head != NULL)
				clear_b(stack_a, stack_b);
			final_rot(stack_a);
			break ;
		}
		else
			inv_check(stack_a, stack_b);
	}
}

// 		if (stack_a->size == 4)
		
// 		if (stack_a->size == 2)
// 			ra(stack_a);


// 		if (stack_a->head->rank == stack_a->head->next->rank + 1)
// 			sa(stack_a);
// 		current = stack_a->head;
// 		while (current->inversions != 0)
// 			current = current->next;
// 		if (stack_a->head->inversions != 0)
// 			rotate_or_reverse(stack_a, current);
// 		if (stack_b->head)
// 		{
// 			if (stack_b->head->rank == stack_a->head->rank + 1)
// 				pa(stack_a, stack_b);
// 		}
// 		if (stack_a->head->inversions > 1)
// 			pb(stack_a, stack_b);
// 	// check when is next node->inversions != 0
// 	}
// }

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
	while (stack_a->size > 1 && (stack_a->sorted != 0
		|| stack_a->head->rank != 0 || stack_b->head != NULL))
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
		if (stack_a->size < 6)
			sort_max_five(stack_a, stack_b);
		else
			radix(stack_a, stack_b);
	}
}

