/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:30:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 18:14:53 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

t_stack	*mk_stack(int max_rows_cont, char **rows_cont)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	stack->min = ft_atol(rows_cont[0]);
	stack->max = ft_atol(rows_cont[0]);
	stack->sorted = 0;
	mk_circlst(stack, max_rows_cont, rows_cont);
	count_stack_inversions(stack);
	rank(stack, (int)(stack->size) - 1);
	return (stack);
}

char	*conc_str_args(char *temp_join1, char *str_args)
{
	char	*temp_join2;

	temp_join2 = ft_strjoin(str_args, temp_join1);
	free(str_args);
	free(temp_join1);
	return (temp_join2);
}

char	*av_to_str(int ac, char **av)
{
	int		row;
	char	*temp_join1;
	char	*str_args;

	if (ac < 2 || !av)
		return (NULL);
	row = 1;
	temp_join1 = NULL;
	str_args = NULL;
	while (row < ac)
	{
		if (err_empty(av[row]) == -1)
			error();
		temp_join1 = ft_strjoin(av[row], " ");
		if (temp_join1 && str_args)
			str_args = conc_str_args(temp_join1, str_args);
		else
		{
			str_args = ft_strdup(temp_join1);
			free(temp_join1);
		}
		row++;
	}
	return (str_args);
}

t_stack	*parser(int ac, char **av)
{
	t_stack		*stack_a;
	char		*str_args;
	t_matrix	matrix;

	str_args = av_to_str(ac, av);
	if (!str_args)
		return (NULL);
	matrix.list = ft_split_ps(str_args, " \f\n\r\t\v");
	free(str_args);
	str_args = NULL;
	matrix = matrix_err_free(matrix.list);
	stack_a = mk_stack(matrix.li, matrix.list);
	freeall(matrix.list, (size_t)matrix.li);
	return (stack_a);
}
