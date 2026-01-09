/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:48:41 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/09 17:48:39 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	err_not_nbr(char *list_item)
{
	int	i;

	i = 0;
	while (list_item[i])
	{
		while (ft_strchr(" \f\n\r\t\v", list_item[i]))
			i++;
		if (list_item[i] == '-' || list_item[i] == '+')
			i++;
		if (list_item[i] < '0' || list_item[i] > '9')
			return (-1);
		while (list_item[i] >= '0' && list_item[i] <= '9')
			i++;
	}
	return (0);
}

int	err_exceeds_int_limits(char *list_item)
{
	long	li_long;

	li_long = ft_atol(list_item);
	if (li_long > INT_MAX || li_long < INT_MIN)
		return (-1);
	return (0);
}

int	err_not_unique(int row, char **av)
{
	int	i;
	int	li_nbr;
	int	av_nbr;

	i = row + 1;
	li_nbr = ft_atol(av[row]);
	while (av[i])
	{
		av_nbr = ft_atol(av[i]);
		if (li_nbr == av_nbr)
			return (-1);
		i++;
	}
	return (0);
}

int	err_empty(char *list_item)
{
	size_t	i;
	size_t	len;

	if (!list_item)
		return (-1);
	i = 0;
	len = ft_strlen(list_item);
	while (list_item[i])
	{
		if (!ft_strchr(" \f\n\r\t\v", list_item[i]))
			break ;
		i++;
	}
	if (i == len)
		return (-1);
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
