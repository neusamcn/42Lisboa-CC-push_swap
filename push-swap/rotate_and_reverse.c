/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:35:20 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/07 19:49:35 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

// REQUIRES TESTING:
int	rotate(t_stack *stack)
{
	// return (-1) on error;
	return (0);
}

// REQUIRES TESTING:
int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check;

	err_check = rotate(stack_a);
	if (err_check == -1)
		return (-1);
	err_check = rotate(stack_b);
	if (err_check == -1)
		return (-1);
	return (0);
}

// REQUIRES TESTING:
int	rev_rotate(t_stack *stack)
{
	// return (-1) on error;
	return (0);
}

// REQUIRES TESTING:
int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	err_check;

	err_check = rev_rotate(stack_a);
	if (err_check == -1)
		return (-1);
	err_check = rev_rotate(stack_b);
	if (err_check == -1)
		return (-1);
	return (0);
}
