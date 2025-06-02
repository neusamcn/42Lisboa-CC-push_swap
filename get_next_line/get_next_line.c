/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/01 19:35:30 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	tempread;
	size_t	bytesread;
	char	*buffer;
	char	*line;

	bytesread = 0;
	buffer = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	while (*buffer != '\n' && bytesread <= BUFFER_SIZE)
	{
		tempread = read(fd, buffer, 1);
		if (*buffer == EOF || tempread != 1)
		{
			free(buffer);
			if (bytesread == 0)
				{
					free(line);
					return (NULL);
				}
			return (line);
		}
		line[bytesread] = *buffer;
		bytesread++;
	}
	free(buffer);
	return (line);
}

// TO DO:
// 1. TEST ALL edge cases
// 1.1. empty file,
// 1.2. big BUFFER_SIZEs (subject),
// 1.3. extremely long line,
// 1.4. change fd mid function calls
// 1.5. other fails to check for NULL?
// 2. divide function into helpers
// 3. Norminette
// 4. Francinette
