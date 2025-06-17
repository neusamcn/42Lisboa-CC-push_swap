/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:09:38 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 14:08:26 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;
	char			*p;

	i = 0;
	chr = (unsigned char)c;
	p = (char *)s;
	while (*(p + i))
	{
		if (*(p + i) == chr)
			return (p + i);
		i++;
	}
	if (chr == '\0')
		return (p + i);
	return (NULL);
}
