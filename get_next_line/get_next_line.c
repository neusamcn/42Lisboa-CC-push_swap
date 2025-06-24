/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/24 15:03:10 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	if (!*buf)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			buf[0] = '\0';
			return (NULL);
		}
		buf[bytesread] = '\0';
	}
	line = read_to_nl(fd, buf, line);
	if (!line)
		return (NULL);
	return (line);
}
