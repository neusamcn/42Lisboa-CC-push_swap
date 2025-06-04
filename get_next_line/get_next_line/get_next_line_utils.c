/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:40:10 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/04 18:55:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = (void *)ptr;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	flowcheck;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	flowcheck = nmemb * size;
	if (flowcheck / nmemb == size)
	{
		ptr = malloc(nmemb * size);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, size * nmemb);
		return (ptr);
	}
	return (NULL);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	lastnode = lst;
	while (lastnode && lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*currentlastnode;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	currentlastnode = ft_lstlast(*lst);
	currentlastnode->next = new;
}
// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	while (i >= 0)
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i--;
// 	}
// 	return (NULL);
// }
