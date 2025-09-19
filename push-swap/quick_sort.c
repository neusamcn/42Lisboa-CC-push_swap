/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 02:42:28 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/19 02:43:05 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

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
