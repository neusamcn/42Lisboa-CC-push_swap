/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neusa <neusa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:51:17 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/06 21:33:48 by neusa            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

size_t	whitespace_skips(char *str)
{
	size_t	i;

	i = 0;
	// not considering form feed ('\f') or carriage return ('\r') to skip:
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\v'))
		i++;
	return (i);
}

size_t	count_rows(char *str)
{
	int		i;
	size_t	rows;

	i = 0;
	rows = 0;
	while (str[i] && str[i] != '\0')
	{
		i += whitespace_skips(&str[i]);
		if (str[i] != '\0' && whitespace_skips(&str[i]) == 0)
		{
			rows++;
			while (str[i] != '\0' && whitespace_skips(&str[i]) == 0)
				i++;
		}
	}
	return (rows);
}

size_t	ft_row_len(char *str)
{
	size_t	row_len;

	row_len = 0;
	while (str[row_len] != '\0' && whitespace_skips(&str[row_len]) == 0)
		row_len++;
	return (row_len);
}

void	free_all(char **splat, size_t row)
{
	while (row > 0)
	{
		free(splat[row - 1]);
		row--;
	}
	free(splat);
}

char	**ft_split(char *str)
{
	size_t	i;
	size_t	row;
	size_t	total_rows;
	size_t	row_len;
	size_t	col;
	char	**splat;

	if (!str)
		return (NULL);
	// Allocating memory for the array of pointers:
	total_rows = count_rows(str);
	splat = (char **)malloc(sizeof(char *) * (total_rows + 1));
	if (!splat)
		return (NULL);
	// Splitting str:
	i = 0;
	row = 0;
	while (str[i] != '\0' && row < total_rows)
	{
		// Skipping spaces, tabs and new lines:
		i += whitespace_skips(&str[i]);
		// Check if we've reached end of string:
		if (str[i] == '\0')
			break ;
		// Calculating length of a row:
		row_len = ft_row_len(&str[i]);
		// Allocating memory for each row of splat:
		splat[row] = (char *)malloc(sizeof(char) * (row_len + 1));
		if (!splat[row])
		{
			free_all(splat, row);
			return (NULL);
		}
		// Create a new splat[row]:
		col = 0;
		while (str[i] != '\0' && whitespace_skips(&str[i]) == 0)
		{
			splat[row][col] = str[i];
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
		if (!splat)
			return (1);
		while (splat[row] != NULL)
		{
			printf("%s\n", splat[row]);
			free(splat[row]);
			row++;
		}
		free(splat);
	}
	return (0);
}