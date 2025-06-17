/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_acav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:22:59 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/12 18:17:43 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(int ac, char **av)
{
	char	*file;
	int		fd;
	char	*line;

	if (ac == 2)
	{
		file = av[1];
		fd = open(file, O_RDONLY);
		// file offset (mark of current position @ file) set to beginning of file.
		line = "";
        printf(">>> TEST W/ **av <<<\n<><><><><><><><><><>\n");
		if (fd == -1)
			printf("fd = %d => cannot open '%s'\n", fd, file);
		else
			printf("fd = %d => '%s' opened successfully.\n------\n", fd, file);
		while (line != NULL)
		{
			printf("\n***** Next line: *****\n");
			printf("%s\n", line = get_next_line(fd));
			if (line != NULL)
				free(line);
		}
		close(fd);
	}
	return (0);
}
