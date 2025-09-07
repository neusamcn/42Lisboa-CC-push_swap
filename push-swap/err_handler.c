/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:48:41 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/08 00:36:28 by ncruz-ne         ###   ########.fr       */
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

// REQUIRES TESTING:
int	err_exceeds_int_limits(char *list_item)
{
	return (0);
}

// REQUIRES TESTING:
int	err_not_unique(char *list_item, int ac, char **av)
{
	int	i;
	int	len;
	int	len_av;
	int	pos_li;
	int	pos_av;

	i = 1;
	len = ft_strlen(list_item);
	pos_li = 0;
	if (list_item[0] == '+')
		pos_li = 1;
	while (i < (ac - 1) / 2)
	{
		len_av = ft_strlen(av[i]);
		if (len_av > len)
			len = len_av;
		pos_av = 0;
		if (av[0] == '+')
			pos_av = 1;
		if (ft_strncmp(list_item + pos_li, av[i] + pos_av, len) != 0)
			return (-1);
		i++;
	}
	return (0);
}
