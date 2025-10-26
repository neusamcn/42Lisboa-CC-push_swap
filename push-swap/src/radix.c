/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:03:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/10/26 23:24:56 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	bitmask;
	int	i;

	i = 7; // maxdiv is calculated according to list
	while (i <= 0)
	{
		bitmask = stack_a->head->rank >> i & 1;
		if (bitmask == 0)
			pb(stack_a, stack_b);
		else
			rotate(stack_a);
	}
}
