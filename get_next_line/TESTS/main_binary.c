/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mu <mu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:42:55 by mu                #+#    #+#             */
/*   Updated: 2025/06/23 20:46:44 by mu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int main(void)
{
    char	*file;
	int		fd;
	char	*line;

    FILE *fp = fopen("TESTS/test_binary.bin", "wb");  // Open in binary write mode
    if (!fp)
    {
        perror("Error opening file");
        return (1);
    }

    // Example: write an array of bytes
    unsigned char data[] = {0x41, 0x42, 0x43, 0x00, 0xFF};  // 'A', 'B', 'C', '\0', 255
    size_t size = sizeof(data);

    if (fwrite(data, 1, size, fp) != size)
    {
        perror("Error writing to file");
        fclose(fp);
        return (1);
    }

    fclose(fp);
	file = "TESTS/test_binary.bin";
	fd = open(file, O_RDONLY);
	// file offset (mark of current position @ file) set to beginning of file.
	line = NULL;
	if (fd == -1)
		printf("fd = %d => cannot open '%s'\n", fd, file);
	else
		printf("fd = %d => '%s' opened successfully.\n----------\n", fd, file);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("\n***** Next line: *****\n");
		printf("%s\n", line);
		free(line);
	}
	close(fd);
    return (0);
}
