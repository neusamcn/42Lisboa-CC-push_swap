/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circlstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:10:37 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/09/01 13:53:19 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

t_list	*ft_circlstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = 0;
	node->rank = 0;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}