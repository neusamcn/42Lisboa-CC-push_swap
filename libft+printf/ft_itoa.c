/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:45:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 14:13:16 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n >= 0)
		len++;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*strn;
	long long	div;
	int			len;

	div = (long long)n;
	len = nlen(n);
	strn = malloc((len + 1) * sizeof(char));
	if (!strn)
		return (NULL);
	if (div < 0)
	{
		strn[0] = '-';
		div *= -1;
	}
	len--;
	while (div > 9)
	{
		strn[len] = (div % 10) + '0';
		div /= 10;
		len--;
	}
	if (div < 10 && div >= 0)
		strn[len] = div + '0';
	strn[nlen(n)] = '\0';
	return (strn);
}
