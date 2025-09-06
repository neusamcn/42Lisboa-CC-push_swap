/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:55:48 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/11 15:47:03 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	dest_uc = (unsigned char *)dest;
	src_uc = (unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		dest_uc[n - 1] = src_uc[n - 1];
		n--;
	}
	dest = (void *)dest_uc;
	return (dest);
}
