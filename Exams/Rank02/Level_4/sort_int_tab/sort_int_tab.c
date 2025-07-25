/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:36:01 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/25 17:35:44 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
            i = 0;
            continue;
		}
		i++;
	}
}
// // FOR TESTING ONLY:
// #include <stdio.h>

// int	main()
// {
// 	int tab[] = {5, 2, 2, 1};
// 	unsigned int size = 4;
// 	unsigned int i = 0;

//     sort_int_tab(tab, size);
// 	while (i < size)
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }