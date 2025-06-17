/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:20:31 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 14:11:16 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s || start >= slen)
		return (ft_calloc(1, 1));
	if (slen - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((slen - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
