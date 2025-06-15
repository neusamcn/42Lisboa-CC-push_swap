/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:46:30 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/08 20:42:26 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcounter(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*allocncpy(char const *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	freeall(char **splat, size_t j)
{
	if (!splat[j])
	{
		while (j > 0)
		{
			free(splat[j - 1]);
			j--;
		}
		free(splat);
		return (1);
	}
	return (0);
}

static char	**in2damatrix(char const *s, char c)
{
	char	**splat;
	size_t	strrows;

	if (!s)
		return (NULL);
	strrows = wordcounter(s, c);
	splat = malloc((strrows + 1) * sizeof(char *));
	if (!splat)
		return (NULL);
	return (splat);
}

char	**ft_split(char const *s, char c)
{
	char	**splat;
	size_t	rowlen;
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	splat = in2damatrix(s, c);
	if (!splat)
		return (NULL);
	while (row < wordcounter(s, c))
	{
		rowlen = 0;
		while (s[i + rowlen] == c)
			i++;
		while (s[i + rowlen] != c && s[i + rowlen])
			rowlen++;
		splat[row] = allocncpy(&s[i], rowlen);
		if (freeall(splat, row) == 1)
			return (NULL);
		i += rowlen;
		row++;
	}
	splat[row] = NULL;
	return (splat);
}
