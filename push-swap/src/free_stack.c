/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:55:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/21 21:29:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "../include/push_swap.h"

void	free_circlst_stack(t_stack *stack)
{
	t_circlist	*current_node;
	t_circlist	*next_node;

	if (!stack || !stack->head)
	{
		free(stack);
		return ;
	}
	current_node = stack->head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		if (current_node == stack->head)
			break ;
	}
	free(stack);
}

void	free_err_stack(t_stack *stack)
{
	t_circlist	*current_node;
	t_circlist	*next_node;

	if (!stack || !stack->head)
	{
		free(stack);
		return ;
	}
	current_node = stack->head;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		if (next_node == stack->head)
			break ;
		current_node = next_node;
	}
	free(stack);
}
