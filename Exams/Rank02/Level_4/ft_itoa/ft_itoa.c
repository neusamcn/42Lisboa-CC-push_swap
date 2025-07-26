/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:38:33 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/26 16:43:31 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char			*nbr_str;
	unsigned int	len;
	long int		nbr_len;
	long int		nbr_long;

	len = 1;
	nbr_len = nbr;
	nbr_long = nbr;
	if (nbr_len < 0)
	{
		len++;
		nbr_len *= -1;
	}
	while (nbr_len > 9)
	{
		nbr_len /= 10;
		len++;
	}
	nbr_str = malloc(len + 1);
	if (!nbr_str)
		return (NULL);
	nbr_str[len + 1] = '\0';
	len--;
	if (nbr_long < 0)
	{
		nbr_str[0] = '-';
		nbr_long *= -1;
	}
	while (nbr_long > 9)
	{
		nbr_str[len] = (nbr_long % 10) + '0';
		nbr_long /= 10;
		len--;
	}
	if (nbr_long < 10 && nbr_long >= 0)
		nbr_str[len] = nbr_long + '0';
	return (nbr_str);
}

// // FOR TESTING ONLY:
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		nbr1;
// 	int		nbr2;
// 	int		nbr3;
// 	int		nbr4;
// 	char	*nbr_str1;
// 	char	*nbr_str2;
// 	char	*nbr_str3;
// 	char	*nbr_str4;

// 	nbr1 = 243;
// 	nbr2 = INT_MIN;
// 	nbr3 = INT_MAX;
// 	nbr4 = 0;
// 	nbr_str1 = ft_itoa(nbr1);
// 	nbr_str2 = ft_itoa(nbr2);
// 	nbr_str3 = ft_itoa(nbr3);
// 	nbr_str4 = ft_itoa(nbr4);
// 	printf("Test 1: %s\n", nbr_str1);
// 	free(nbr_str1);
// 	printf("Test 2: %s\n", nbr_str2);
// 	free(nbr_str2);
// 	printf("Test 3: %s\n", nbr_str3);
// 	free(nbr_str3);
// 	printf("Test 4: %s\n", nbr_str4);
// 	free(nbr_str4);
// 	return (0);
// }
