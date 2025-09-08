/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:57:59 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/08 19:33:11 by ncruz-ne         ###   ########.fr       */
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
	empty_stack->min = 0;
	empty_stack->max = 0;
	empty_stack->sorted = 0;
	return (empty_stack);
}
// this can replace a stack that isn't empty
// do I need to consider saving the content from OG stack first?
// and freeing OG stack?
// always check if stack->size == 0 before doing operations ()