/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:21:01 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 14:13:39 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (s1[i1] != '\0')
	{
		join[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\0')
	{
		join[i1 + i2] = s2[i2];
		i2++;
	}
	join[i1 + i2] = '\0';
	return (join);
}
