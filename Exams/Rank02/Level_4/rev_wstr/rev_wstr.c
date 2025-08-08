/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:39:36 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/08 12:03:42 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\0')
		len++;
	return (len);
}
int	if_whitespace(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\v'))
		return (0);
	return (1);
}
char	*if_endword(char *str)
{
	int		i;
	int		i_wrd;
	size_t	word_len;
	char	*word;

	i = 0;
	i_wrd = 0;
    // FIX
	while (*(str + i) && *(str + i) != '\0' && if_whitespace((str + i)) == 1)
		i--;
	word_len = -i;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	while (i <= 0)
	{
		word[i_wrd] = *(str + i);
		i_wrd++;
		i++;
	}
	word[i_wrd++] = '\0';
	return (word);
}
void	rev_wstr(char *str)
{
	size_t	str_len;
	char	*word;
	size_t	word_len;

	str_len = ft_strlen(str);
	while (str[str_len] && str[str_len] != '\0' && str_len)
	{
		if (if_whitespace(&str[str_len]) == 0)
		{
			write(1, &str[str_len], 1);
			str_len--;
		}
		word = if_endword(&str[str_len]);
		if (!word)
			break ;
		word_len = ft_strlen(word);
		write(1, &word, word_len);
		free(word);
		str_len -= word_len;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}