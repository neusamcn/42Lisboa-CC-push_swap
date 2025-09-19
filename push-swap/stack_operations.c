/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:57:59 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/19 02:42:17 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*create_empty_stack(void)
{
	t_stack	*empty_stack;

	empty_stack = malloc(sizeof(t_stack));
	if (!empty_stack)
		return (NULL);
	empty_stack->head = NULL;
	empty_stack->size = 0;
	empty_stack->min = 1;
	empty_stack->max = -1;
	// representation for empty. use for flags later
	empty_stack->sorted = 0;
	return (empty_stack);
}
// this can replace a stack that isn't empty
// do I need to consider saving the content from OG stack first?
// and freeing OG stack?
// always check if stack->size == 0 before doing operations ()


// function for rank?????
// inversions = rank - index; goal is 0.
// sorted => SUM(inversions). goal is 0.

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