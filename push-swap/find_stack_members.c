/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_members.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:17:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/17 18:02:28 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

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

int	find_radix_max_div(t_stack *stack)
{
	int	position;
	int	radix_max_div;
	int	min;
	int	max;
	int	longest_nb;

	min = stack->min;
	if (stack->min < 0)
		min = -stack->min;
	max = stack->max;
	if (stack->max < 0)
		max = -stack->max;
	longest_nb = max;
	if (min > max)
		longest_nb = min;
	position = 1;
	radix_max_div = 1;
	while (position < ft_nlen(longest_nb))
	{
		radix_max_div *= 10;
		position++;
	}
	return (radix_max_div);
}

int	count_node_inversions(t_stack *stack, t_circlist *node)
{
	int			inversions;
	t_circlist	*current;

	inversions = 0;
	current = stack->head;
	while (current != NULL)
	{
		if (current->content == node->content)
		{
			while (current != NULL)
			{
				current = current->next;
				if (current->index == 0)
					return (inversions);
				if (node->content > current->content)
					inversions++;
			}
		}
		current = current->next;
		if (current->index == 0)
			break ;
	}
	return (inversions);
}

void	count_stack_inversions(t_stack *stack)
{
	while (stack && stack->head)
	{
		stack->head->inversions = count_node_inversions(stack, stack->head);
		stack->sorted += stack->head->inversions;
		stack->head = stack->head->next;
		if (stack->head->index == 0)
			break ;
	}
}
