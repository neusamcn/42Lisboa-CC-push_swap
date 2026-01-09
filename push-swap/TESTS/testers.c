/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:43:37 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 13:42:31 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "testers.h"

void	print_stack(t_stack *stack, char stack_name)
{
	t_circlist	*current;
	t_circlist	*start;

	current = stack->head;
	start = stack->head;
	printf("STACK_%c: %p\n", stack_name, stack);
	printf("head: %p\n", stack->head);
	printf("size: %lu\n", stack->size);
	printf("min: %d\n", stack->min);
	printf("max: %d\n", stack->max);
	printf("sorted: %d\n\n", stack->sorted);
	while (current)
	{
		printf("node: %p\n", current);
		printf("content: %d\n", current->content);
		printf("index: %d\n", current->index);
		printf("rank: %d\n", current->rank);
		printf("inversions: %d\n", current->inversions);
		printf("previous: %p\n", current->previous);
		printf("next: %p\n------------\n\n", current->next);
		current = current->next;
		if (current == start)
			break ;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (av[i] && i < ac)
		{
			printf("av[%d]: %s\nerr_empty return: %d\n",
				i, av[i], err_empty(av[i]));
			i++;
		}
	}
	return (0);
}

	// TESTS START
	// print_stack(stack_a, 'A');
	// printf("><><><><><><><><><><><><><\n");
	// print_stack(stack_b, 'B');
	// printf("><><><><><><><><><><><><><\n");

	// printf("><><><><><><><><><><><><><\n");
	// print_stack(stack_a, 'A');
	// printf("><><><><><><><><><><><><><\n");
	// print_stack(stack_b, 'B');
	// TESTS END

	// // str_args() tester:
	// write(1, str_args, ft_strlen(str_args));
	// write(1, "\n", 1);
	// int	i = 0;
	// char	c;
	// while (list_matrix[i])
	// {
	// 	c = i + '0';
	// 	write(1, &c, 1);
	// 	write(1, ": ", 2);
	// 	write(1, list_matrix[i], ft_strlen(list_matrix[i]));
	// 	write(1, "\n", 1);
	// 	i++;
	// }