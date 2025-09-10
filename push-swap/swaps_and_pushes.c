/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_and_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:21:19 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/10 20:59:37 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

// REQUIRES TESTING:
int	sa(t_stack *stack_a)
{
	t_circlist	*swap;

	if (!stack_a->head || !stack_a->head->next) // == NULL ? && redundant?
		return (-1);
	swap->content = stack_a->head->content;
	stack_a->head->content = stack_a->head->next->content;
	stack_a->head->next->content = swap->content;
	swap->rank = stack_a->head->rank;
	stack_a->head->rank = stack_a->head->next->rank;
	stack_a->head->next->rank = swap->rank;
	return (0);
}

// REQUIRES TESTING:
int	sb(t_stack *stack_b)
{
	t_circlist	*swap;

	if (!stack_b->head || !stack_b->head->next) // == NULL ? && redundant?
		return (-1);
	swap->content = stack_b->head->content;
	stack_b->head->content = stack_b->head->next->content;
	stack_b->head->next->content = swap->content;
	swap->rank = stack_b->head->rank;
	stack_b->head->rank = stack_b->head->next->rank;
	stack_b->head->next->rank = swap->rank;
	return (0);
}

// REQUIRES TESTING:
int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check_a;
	int	err_check_b;

	err_check_a = sa(stack_a);
	err_check_b = sb(stack_b);
	if (err_check_a == -1 || err_check_b == -1)
		return (-1);
	return (0);
}

// REQUIRES TESTING:
int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*copy;
	
	if (!stack_b->head) // == NULL ?
		return (-1);
	copy = stack_b->head;
	stack_b->head = stack_a->head->next;
	copy->next = stack_a->head;
	stack_a->head->previous = copy;
	stack_a->head = copy;
	return (0);
}

// REQUIRES TESTING:
int	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_circlist	*copy;

	if (!stack_a->head) // == NULL ?
		return (-1);
	copy = stack_a->head;
	stack_a->head = stack_b->head->next;
	copy->next = stack_b->head;
	stack_b->head->previous = copy;
	stack_b->head = copy;
	return (0);
}
