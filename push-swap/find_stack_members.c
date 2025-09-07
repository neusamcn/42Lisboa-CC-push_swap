/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_members.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:17:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/07 18:22:41 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

int	find_max(int content, int curr_max)
{
	if (content > curr_max)
		return (content);
	return (curr_max);
}

int	find_min(int content, int curr_min)
{
	if (content < curr_min)
		return (content);
	return (curr_min);
}

// function for ranks, inversions and stack's min, max and sorted
// rank?????
// if (content == min) {rank == 0};
// if (content == max) {rank == stack->size - 1};
// inversions = rank - index; goal is 0.
// sorted = SUM(inversions). goal is 0.

// REQUIRES TESTING:
int	find_max_digits(t_stack *stack)
{
	int	position;
	int	max_digits;

	position = 0;
	while (position < ft_nlen(stack->max))
	{
		max_digits *= 10;
		position++;
	}
	return (max_digits);
}

// REQUIRES TESTING:
void	ft_mk_lst_rank(t_stack *stack)
{
	t_nodes	nodes;
	int		lsd;
	int		bucket;
	int		div;

	nodes.previous = NULL;
	nodes.current = NULL;
	div = find_max_digits(stack);
	while (bucket >= 0)
	{
		bucket = 9;
		while (stack)
		{
			lsd = stack->head->content % div;
			if (lsd == bucket)
			{

			}
			stack->head = stack->head->next;
			if (stack->head->index == 0)
				break ;
		}
		bucket--;
	}
}
