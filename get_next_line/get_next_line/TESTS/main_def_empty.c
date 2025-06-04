/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/03 11:34:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*file;
	char	*line;
	int		fd;

	file = "TESTS/test_empty.txt";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
		printf("fd = %d => '%s' opened successfully.\n----------\n", fd, file);
	printf("%s\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	printf("\n***** Next line: *****\n");
	printf("%s\n", line = get_next_line(fd));
	if (line != NULL)
		free(line);
	close(fd);
	return (0);
}
