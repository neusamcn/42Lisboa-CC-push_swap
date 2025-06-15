/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:51:33 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 22:06:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_s;
	size_t	lendst;
	size_t	lensrc;

	i_s = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size > lendst)
	{
		while (i_s < size - lendst - 1 && src[i_s])
		{
			dst[lendst + i_s] = src[i_s];
			i_s++;
		}
		dst[lendst + i_s] = '\0';
		return (lendst + lensrc);
	}
	return (size + lensrc);
}
