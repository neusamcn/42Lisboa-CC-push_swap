/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:17:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/27 17:11:37 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	is_stack_min(int content, int curr_min)
{
	if (content < curr_min)
		return (content);
	return (curr_min);
}

int	is_stack_max(int content, int curr_max)
{
	if (content > curr_max)
		return (content);
	return (curr_max);
}

int	find_min(t_stack *stack)
{
	t_circlist	*current;
	t_circlist	*start;
	int			min;

	// worth it to keep as an err checker?
	if (!stack || !stack->head/* || stack->head->previous->next != stack->head */)
		return (1);
	current = stack->head;
	start = stack->head;
	min = stack->head->content;
	while (current)
	{
		min = is_stack_min(current->content, min);
		current = current->next;
		if (current == start)
			break ;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_circlist	*current;
	t_circlist	*start;
	int			max;

	// worth it to keep as an err checker?
	if (!stack || !stack->head/*  || stack->head->previous->next != stack->head */)
		return (-1);
	current = stack->head;
	start = stack->head;
	max = stack->head->content;
	while (current)
	{
		max = is_stack_max(current->content, max);
		current = current->next;
		if (current == start)
			break ;
	}
	return (max);
}

int	find_radix_max_div(t_stack *stack)
{
	int	position;
	int	radix_max_div;
	int	longest_nb;

	if (!stack || !stack->head || stack->min > stack->max)
		return (-1);
	longest_nb = stack->size - 1;
	position = 1;
	radix_max_div = 1;
	while (position < ft_nlen(longest_nb))
	{
		radix_max_div *= 10;
		position++;
	}
	return (radix_max_div);
}
