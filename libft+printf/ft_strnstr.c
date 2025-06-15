/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 12:10:41 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/12 18:25:49 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	litlen;

	ib = 0;
	litlen = ft_strlen(little);
	if (!little || little[0] == '\0')
		return ((char *)big);
	if (len > 0 && *big && *little)
	{
		while (ib < len && *(big + ib) != '\0')
		{
			if (ft_strncmp(big + ib, little, litlen) == 0
				&& ib + litlen - 1 < len)
				return ((char *)(big + ib));
			ib++;
		}
	}
	return (NULL);
}
