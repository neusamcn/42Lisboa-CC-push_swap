/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:38:33 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/25 18:08:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char *nbr_str;
	unsigned int size = 0;
	int help_nbr = nbr;

	if (help_nbr < 0)
    {
        size = 1;
        help_nbr *= -1;
    }
	while (help_nbr > 0)
	{
		help_nbr /= 10;
		size++;
	}
	nbr_str = malloc(size + 1);
    nbr_str[size] = '\0';
    size--;
    if (nbr < 0)
    {
        nbr_str[0] = '-';
        nbr *= -1;
    }
    while (nbr > 0)
    {
        nbr_str[size] = (nbr % 10) + '0';
        nbr /= 10;
        size--;   
    }
	return (nbr_str);
}

// FOR TESTING ONLY:
#include <stdio.h>
#include <limits.h>

int main()
{
    int nbr1 = 243;
    int nbr2 = INT_MIN;
    int nbr3 = INT_MAX;
    int nbr4 = 0;

    char    *nbr_str1 = ft_itoa(nbr1);
    char    *nbr_str2 = ft_itoa(nbr2);
    char    *nbr_str3 = ft_itoa(nbr3);
    char    *nbr_str4 = ft_itoa(nbr4);

    printf("%s\n", nbr_str1);
    free(nbr_str1);
    printf("%s\n", nbr_str2);
    free(nbr_str2);
    printf("%s\n", nbr_str3);
    free(nbr_str3);
    printf("%s\n", nbr_str4);
    free(nbr_str4);
    
    return (0);
}
