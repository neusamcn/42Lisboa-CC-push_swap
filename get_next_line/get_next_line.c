/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mu <mu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/23 23:46:25 by mu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytesread;
	int			i;
	int			buf_len_nl;

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
		if (bytesread > 0)
			buf[bytesread] = '\0';
	}
	while (!ft_strchr(buf, '\n'))
	{
		line = append_line(line, buf);
		if (!line)
			return (NULL);
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == 0)
		{
			buf[0] = '\0';
			return (line);
		}
		else if (bytesread < 0)
		{
			buf[0] = '\0';
			return (NULL);
		}
		else if (bytesread > 0)
			buf[bytesread] = '\0';
	}
	buf_len_nl = ft_strlen_nl(buf) + 1;
	line = append_line(line, buf);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[buf_len_nl] && buf_len_nl < BUFFER_SIZE)
		buf[i++] = buf[buf_len_nl++];
	buf[i] = '\0';
	return (line);
}

// TO DO:
// 1. TEST ALL edge cases
// 1.2. big BUFFER_SIZEs (subject),
// 1.3. extremely long line,
// 1.4. change fd mid function calls
// 1.5. other fails to check for NULL?
// 2. divide function into helpers
// 3. Norminette
// 4. Francinette
