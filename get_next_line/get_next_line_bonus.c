/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:35 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/07/01 17:39:28 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	if (!buf[fd][0])
	{
		bytesread = read(fd, buf[fd], BUFFER_SIZE);
		if (bytesread <= 0)
		{
			buf[fd][0] = '\0';
			return (NULL);
		}
		buf[fd][bytesread] = '\0';
	}
	line = read_until_nl(fd, buf[fd], line);
	if (!line)
		return (NULL);
	return (line);
}
