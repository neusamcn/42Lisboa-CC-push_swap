/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:36:26 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/24 20:36:27 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int row = 1;
    int col;
    if (ac > 1)
    {
        while (row < ac)
        {
            col = 0;
            while (av[row][col] && av[row][col] != '\0')
            {
                // Capitalizing last character of words:   
                if (av[row][col + 1] == '\0' || av[row][col + 1] == ' ' ||
                    (av[row][col + 1] >= '\t' && av[row][col + 1] <= '\r'))
                {
                    if (av[row][col] >= 'a' && av[row][col] <= 'z')
                        av[row][col] = av[row][col] - 32;
                }
                // Uppercases that need to become lowercase:
                else
                {
                    if (av[row][col] >= 'A' && av[row][col] <= 'Z')
                        av[row][col] = av[row][col] + 32;
                }
                // write() everything:
                write(1, &av[row][col], 1);
                col++;
            }
            write(1, "\n", 1);
            row++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}
