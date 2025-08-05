/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:51:17 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/05 16:31:38 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	count_rows(char *str)
{
	int		i;
	size_t	rows;

	i = 0;
	rows = 0;
	while (str[i] && str[i] != '\0')
	{
		while (str[i] != ' ' || (str[i] >= '\t' && str[i] <= '\v'))
			i++;
		if (!(str[i] != ' ' || (str[i] >= '\t' && str[i] <= '\v')))
		{
			rows++;
			while (!(str[i] != ' ' || (str[i] >= '\t' && str[i] <= '\v')))
				i++;
		}
	}
	return (rows);
}

size_t  row_len(char *str)
{
    size_t  row_len = 0;
    
    while (!(str[row_len] != ' ' || (str[row_len] >= '\t' && str[row_len] <= '\v')))
        row_len++;
    return (row_len);
}

int	free_all(char **splat, size_t row)
{
	if (!splat[row])
	{
		while (row > 0)
		{
			free(splat[row - 1]);
			row--;
		}
		free(splat);
		return (1);
	}
	return (0);
}

char	**ft_split(char *str)
{
	size_t	i;
	size_t	row;
    size_t  row_len;
	size_t	col;
	char	**splat;

	if (!str)
		return (NULL);
	// Allocating memory for the array of pointers:
	splat = (char **)malloc(sizeof(char *) * (count_rows(str) + 1));
	if (!splat)
		return (NULL);
	// Splitting str
	// (not considering form feed ('\f') or carriage return ('\r') to skip):
	i = 0;
	row = 0;
    while (str[i + row_len] != '\0' && row <= count_rows(str))
    {
        // Skipping spaces, tabs and new lines:
        while (str[i + row_len] != ' ' || (str[i + row_len] >= '\t' && str[i] <= '\v'))
            i++;
        // Calculating length of a row:
        while (!(str[i + row_len] != ' ' || (str[i + row_len] >= '\t' && str[i + row_len] <= '\v')))
            row_len++;
        // Allocating memory for each row of splat:
        splat[row] = (char *)malloc(sizeof(char) * (row_len + 1));
        if (free_all(splat, row) == 1)
            return (NULL);
        row_len = 0;
        // Create a new splat[row]:
        col = 0;
        while (!(str[i + row_len] != ' ' || (str[i + row_len] >= '\t' && str[i + row_len] <= '\v')))
        {
            splat[row][col] = str[i + row_len];
            i++;
            col++;
        }
        splat[row][col] = '\0';
        row++;
    }
	// Last row of splat:
	splat[row] = NULL;
	return (splat);
}

// FOR TESTING ONLY:
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int row = 0;
		char **splat = ft_split(av[1]);
		while (splat[row] != NULL)
		{
			printf("%s\n", splat[row]);
			row++;
		}
		free(splat[row]);
		free_all(splat, row);
	}
	return (0);
}