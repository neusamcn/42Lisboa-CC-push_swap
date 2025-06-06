/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:00:09 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/06 18:53:16 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char *line;

    line = "";
	while (line != NULL)
	{
		printf("\n***** Next line: *****\n");
		printf("> %s\n", line = get_next_line(0));
		if (line != NULL)
			free(line);
	}
	return (0);
}
// Ctrl + D to signal EOF