/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_def_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mu <mu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:24:56 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/24 11:53:30 by mu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	char	*file1 = "TESTS/test.txt";
	char	*file2 = "TESTS/one_line_no_nl.txt";
	char	*file3 = "TESTS/test_nonl.txt";
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);
	fd3 = open(file3, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	if (fd1 == -1)
		printf("fd1 = %d => cannot open '%s'\n", fd1, file1);
	else
		printf("fd = %d => '%s' opened successfully.\n----------\n", fd1, file1);
	if (fd2 == -1)
		printf("fd2 = %d => cannot open '%s'\n", fd2, file2);
	else
		printf("fd2 = %d => '%s' opened successfully.\n----------\n", fd2, file2);
	if (fd3 == -1)
		printf("fd3 = %d => cannot open '%s'\n", fd3, file3);
	else
		printf("fd3 = %d => '%s' opened successfully.\n----------\n", fd3, file3);
	printf("\n***** Next line fd1: *****\n");
	printf("%s", line = get_next_line_bonus(fd1));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd2: *****\n");
	printf("%s", line = get_next_line_bonus(fd2));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd3: *****\n");
	printf("%s", line = get_next_line_bonus(fd3));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd1: *****\n");
	printf("%s", line = get_next_line_bonus(fd1));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd1: *****\n");
	printf("%s", line = get_next_line_bonus(fd1));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd2: *****\n");
	printf("%s", line = get_next_line_bonus(fd2));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd2: *****\n");
	printf("%s", line = get_next_line_bonus(fd2));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd3: *****\n");
	printf("%s", line = get_next_line_bonus(fd3));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd3: *****\n");
	printf("%s", line = get_next_line_bonus(fd3));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd1: *****\n");
	printf("%s", line = get_next_line_bonus(fd1));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd3: *****\n");
	printf("%s", line = get_next_line_bonus(fd3));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd2: *****\n");
	printf("%s", line = get_next_line_bonus(fd2));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd3: *****\n");
	printf("%s", line = get_next_line_bonus(fd3));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd2: *****\n");
	printf("%s", line = get_next_line_bonus(fd2));
	if (line != NULL)
		free(line);
	printf("\n***** Next line fd1: *****\n");
	printf("%s\n", line = get_next_line_bonus(fd1));
	if (line != NULL)
		free(line);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
