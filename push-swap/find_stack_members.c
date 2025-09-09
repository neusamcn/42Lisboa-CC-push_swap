/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stack_members.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:17:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/10 00:20:47 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

int	find_min(int content, int curr_min)
{
	if (content < curr_min)
		return (content);
	return (curr_min);
}

int	find_max(int content, int curr_max)
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

// function for ranks, inversions and stack's min, max and sorted
// rank?????
// if (content == min) {rank == 0};
// if (content == max) {rank == stack->size - 1};
// inversions = rank - index; goal is 0.
// sorted = SUM(inversions). goal is 0.

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

// bucket_sort + radix_sort ?
// REQUIRES TESTING:
// void	ft_mk_lst_rank(t_stack *stack)
// {
// 	t_nodes	nodes;
// 	int		lsd;
// 	int		bucket;
// 	int		div;

// 	nodes.previous = NULL;
// 	nodes.current = NULL;
// 	div = find_radix_max_div(stack);
// 	while (bucket >= -9)
// 	{
// 		bucket = 9;
// 		while (stack)
// 		{
// 			lsd = (stack->head->content) % div;
// 			if (lsd == bucket)
// 			{
// 			}
// 			stack->head = stack->head->next;
// 			if (stack->head->index == 0)
// 				break ;
// 		}
// 		bucket--;
// 	}
// }

// quick_sort()
// Hoare's partition
// https://www.geeksforgeeks.org/dsa/hoare-s-partition-algorithm/
// REQUIRES TESTING:
// t_stack	*hoares_partition(t_stack *stack)
// {
// 	int			pivot;
// 	int			swap;
// 	t_circlist	*head_current;
// 	t_circlist	*tail_current;
// 	// t_stack		*cp_stack;

// 	pivot = stack->head->content;
// 	head_current = stack->head;
// 	tail_current = stack->head->previous;
// 	while (stack)
// 	{
// 		while (head_current->content < pivot)
// 			head_current = head_current->next;
// 		while (tail_current->content > pivot)
// 			tail_current = tail_current->previous;
// 		if (head_current->index > tail_current->index)
// 			break ;
// 		// not swapping on original stack:
// 		swap = head_current->content;
// 		head_current->content = tail_current->content;
// 		tail_current->content = swap;
// 	}
// 	return (stack);
// }
