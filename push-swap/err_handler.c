/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:48:41 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/08 22:20:53 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft/libft.h"
#include "push_swap.h"

int	err_not_nbr(char *list_item)
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

int	err_exceeds_int_limits(char *list_item)
{
	int	i;

	i = 0;
	while (list_item[i])
	{
		if ((list_item[i] >= '1' && list_item[i] <= '9')
			&& ft_atoi(list_item) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	err_not_unique(int row, int ac, char **av)
{
	int	i;
	int	li_nbr;
	int	av_nbr;

	i = row + 1;
	li_nbr = ft_atoi(av[row]);
	while (i < ac)
	{
		av_nbr = ft_atoi(av[i]);
		if (li_nbr == av_nbr)
			return (-1);
		i++;
	}
	return (0);
}
