/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:30:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/07 19:24:15 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

int	input_err(char *list_item)
{
	int	i;

	i = 0;
	if (list_item[i] == '-' || list_item[i] == '+')
		i++;
	while (list_item[i])
	{
		if (!(list_item[i] >= '0' && list_item[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

t_nodes	link_circlst(t_stack *stack, t_nodes nodes, int max_rows, int row)
{
	if (!stack->head)
		stack->head = nodes.current;
	if (row <= max_rows)
	{
		nodes.current->previous = nodes.previous;
		if (nodes.previous)
			nodes.previous->next = nodes.current;
		nodes.previous = nodes.current;
		if (row == max_rows)
		{
			nodes.current->next = stack->head;
			stack->head->previous = nodes.current;
		}
	}
	if (row < max_rows)
		nodes.current->next = NULL;
	return (nodes);
}

void	mk_circlst(t_stack *stack, int max_rows_cont, char **rows_cont)
{
	t_nodes	nodes;
	int		row;

	nodes.previous = NULL;
	row = 1;
	while (row < max_rows_cont)
	{
		nodes.current = malloc(sizeof(t_circlist));
		if (!nodes.current)
		{
			free_err_stack(stack);
			return ;
		}
		nodes.current->content = ft_atoi(rows_cont[row++]);
		stack->max = find_max(nodes.current->content, stack->max);
		stack->min = find_min(nodes.current->content, stack->min);
		nodes.current->index = stack->size++;
		nodes.current->rank = 0;
		nodes.current->inversions = 0;
		nodes = link_circlst(stack, nodes, max_rows_cont, row);
		nodes.current = nodes.current->next;
	}
}

// REQUIRES TESTING:
t_stack	*mk_stack(int max_rows_cont, char **rows_cont)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	stack->min = ft_atoi(rows_cont[1]);
	stack->max = ft_atoi(rows_cont[1]);
	stack->sorted = 0;
	mk_circlst(stack, max_rows_cont, rows_cont);
	// function for ranks, inversions and stack's min, max and sorted
	return (stack);
}

// REQUIRES TESTING:
t_stack	*parser(int ac, char **av) // should it return a pointer?
{
	int row;
	// t_circlist  *lst_b;
	t_stack *stack_a;
	// t_stack *stack_b;

	row = 1;
	while (row < ac)
	{
		if (input_err(av[row++]) == -1)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE); // yes? or only in main?
		}
	}
	stack_a = mk_stack(ac, av);
	return (stack_a);
}
