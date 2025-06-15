/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:41:50 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/12 18:21:36 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	s1len;
	char	*trimmed;

	if (!s1)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, (int)s1[i]) != NULL)
		i++;
	if (i == s1len)
	{
		trimmed = ft_calloc(1, 1);
		if (!trimmed)
			return (NULL);
		return (trimmed);
	}
	s1len--;
	while (s1[s1len] && ft_strrchr(set, (int)s1[s1len]) != NULL)
		s1len--;
	trimmed = malloc((s1len - i + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + i, s1len - i + 2);
	return (trimmed);
}
