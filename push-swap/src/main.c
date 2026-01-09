/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:54:12 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 13:56:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

void	pick_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->sorted != 0 || stack_a->head->rank != 0
		|| stack_b->head != NULL)
	{
		if (stack_a->size == 2)
			ra(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
		else
			radix(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parser(ac, av);
	if (!stack_a)
		error();
	stack_b = create_empty_stack();
	pick_algo(stack_a, stack_b);
	free_circlst_stack(stack_a);
	free_circlst_stack(stack_b);
	exit(EXIT_SUCCESS);
}
