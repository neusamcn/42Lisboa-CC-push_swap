/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:36:44 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:36:54 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		len;

	current = begin_list;
	len = 0;
	while (current != 0)
	{
		current = begin_list->next;
		len++;
	}
	return (len);
}
