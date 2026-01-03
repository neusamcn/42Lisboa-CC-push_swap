/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 03:18:06 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/31 05:20:30 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	a_node_inversions(t_stack *stack, t_circlist *node)
{
	int			inversions;
	t_circlist	*current;

	inversions = 0;
	current = stack->head;
	while (current)
	{
		if (current->content == node->content)
		{
			while (current)
			{
				current = current->next;
				if (current->rank == 0)
					return (inversions);
				if (node->content > current->content)
					inversions++;
			}
		}
		current = current->next;
		if (current->rank == 0)
			break ;
	}
	return (inversions);
}

void	stack_a_sortedness(t_stack *stack_a)
{
	t_circlist	*current;

	current = stack_a->head;
	stack_a->sorted = 0;
	while (current->rank != 0)
		current = current->next;
	while (current)
	{
		current->inversions = a_node_inversions(stack_a, current);
		stack_a->sorted += current->inversions;
		current = current->next;
		if (current->rank == 0)
			break ;
	}
}

// void	min_to_head(t_stack *stack_a, t_stack *stack_b)
// {
// 	if (!stack_a || !stack_b || !stack_a->head
// 		|| stack_a->sorted == 0 || stack_a->head->rank == 0)
// 		return ;
// 	while (stack_a->head->rank != 0)
// 	{
// 		if ()
// 	}
// }

void	inv_above_one(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_a->head || stack_a->sorted == 0)
		return ;
	if (stack_a->head->inversions > 1 && stack_a->head->rank != 0)
		pb(stack_a, stack_b);
	stack_index_size(stack_a);
	stack_a_sortedness(stack_a);
}

void	rank_diff_1move(t_stack *stack_a, t_stack *stack_b)
{
	int	a_head;
	int	a_next;
	int	b_head;
	int	b_next;

	if (!stack_a || !stack_b || !stack_a->head || stack_a->sorted == 0)
		return ;
	if (stack_b->head)
	{
		a_head = stack_a->head->rank;
		a_next = stack_a->head->next->rank;
		b_head = stack_b->head->rank;
		b_next = stack_b->head->next->rank;
		if (a_head == a_next + 1 && b_head + 1 == b_next)
			ss(stack_a, stack_b);
		a_head = stack_a->head->rank;
		b_head = stack_b->head->rank;
		if (a_head == b_head + 1)
			pa(stack_a, stack_b);
	}
	a_head = stack_a->head->rank;
	a_next = stack_a->head->next->rank;
	if (a_head == a_next + 1)
		sa(stack_a);
	stack_index_size(stack_a);
	stack_a_sortedness(stack_a);
}

void	rank_diff_2moves(t_stack *stack_a, t_stack *stack_b)
{
	int	a_head;
	int	b_previous;
	int	b_next;

	if (!stack_a || !stack_b || !stack_a->head
		|| !stack_b->head || stack_a->sorted == 0)
		return ;
	a_head = stack_a->head->rank;
	b_previous = stack_b->head->previous->rank;
	b_next = stack_b->head->next->rank;
	if (a_head == b_next + 1)
		rb(stack_b);
	else if (a_head == b_previous + 1)
		rrb(stack_b);
	pa(stack_a, stack_b);
	stack_index_size(stack_a);
	stack_a_sortedness(stack_a);
}

void	rot_all_b(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*current;
	t_circlist	*end_b;

	if (!stack_a || !stack_b || !stack_a->head || stack_a->sorted == 0)
		return ;
	end_b = stack_b->head->previous;
	while (stack_a->sorted != 0 || stack_b->head || stack_b->head == end_b)
	{
		current = stack_a->head;
		rank_diff_1move(stack_a, stack_b);
		rank_diff_2moves(stack_a, stack_b);
		if (current != stack_a->head && stack_b->head != end_b)
			continue ;
		if (stack_b->head == end_b)
		{
			stack_index_size(stack_a);
			stack_a_sortedness(stack_a);
			break ;
		}
		rb(stack_b);
	}
}

void	rankinv_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*current;
	t_circlist	*end_a;
	int			direction;

	if (!stack_a || !stack_b || !stack_a->head || stack_a->sorted == 0)
		return ;
	end_a = stack_a->head->previous;
	direction = 0;
	while (stack_a->sorted != 0 || stack_b->head)
	{
		current = stack_a->head;
		rank_diff_1move(stack_a, stack_b);
		inv_above_one(stack_a, stack_b);
		rank_diff_2moves(stack_a, stack_b);
		if (current != stack_a->head)
			continue ;
		if (stack_a->head != end_a)
		{
			if (direction == 0)
				ra(stack_a);
			else if (direction == 1)
				rra(stack_a);
			stack_index_size(stack_a);
			stack_a_sortedness(stack_a);
			continue ;
		}
		if (direction == 0 && stack_a->head == end_a)
		{
			rot_all_b(stack_a, stack_b);
			end_a = stack_b->head->next;
			direction = 1;
		}
		else if (direction == 1 && stack_a->head == end_a)
		{
			rot_all_b(stack_a, stack_b);
			end_a = stack_a->head->previous;
			direction = 0;
		}
		stack_index_size(stack_a);
		stack_a_sortedness(stack_a);
		continue ;
	}
}
