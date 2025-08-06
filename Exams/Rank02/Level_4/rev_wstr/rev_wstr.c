/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 21:39:36 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/08/06 22:51:04 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(char *str)
{
    size_t len = 0;

    while (str[len] && str[len] != '\0')
        len++;
    return (len);
}

char    *if_endword(char *str)
{
    int i = 0;
    int i_wrd = 0;
    char    *word;

    while (*(str + i) && *(str + i) != '\0' && if_whitespace((str + i)) == 1)
        i--;
    while (i <= 0)
    {
        word[i_wrd] = *(str + i);
        i_wrd++;
        i++;
    }
    return (word);
}

int if_whitespace(char *str)
{
    int i = 0;

    if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\v'))
        return (0);
    return (1);
}

char    *rev_wstr(char *str)
{
    size_t  i = 0;
    size_t  str_len = ft_strlen(str);
    char    *rev_str = str;

    while (str[i] && str[i] != '\0' && i >= 0)
    {
        if (if_whitespace(&str[str_len]) == 0)
        {
            rev_str[i] = str[str_len];
            str_len--;
            i++;
        }
        else if (if_endword(&str[i]))
        {
            // finish
        }
    }
}

int main(int ac, char **av)
{
    char    *rev_str = rev_wstr(av[1]);
    int i = 0;

    if (ac == 2)
    {
        while (rev_str[i] && rev_str[i] != '\0')
        {
            write(1, &rev_str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}