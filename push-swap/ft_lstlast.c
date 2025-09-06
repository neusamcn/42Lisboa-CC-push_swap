/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:14:51 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/27 22:05:30 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	lastnode = lst;
	while (lastnode)
	{
		if (lastnode->index == 0)
		{
			lastnode = lastnode->previous;
			break ;
		}
		lastnode = lastnode->previous;
	}
	return (lastnode);
}