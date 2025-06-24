/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mu <mu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/24 09:48:31 by mu               ###   ########.fr       */
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

// char	*get_next_line(int fd)
// {
// 	static char	buf[BUFFER_SIZE + 1];
// 	char		*line;
// 	ssize_t		bytesread;
// 	int			i;
// 	int			buf_len_nl;

// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	line = NULL;
// 	while (!ft_strchr(buf, '\n'))
// 	{
// 		if (*buf)
// 		{
// 			line = append_line(line, buf);
// 			if (!line)
// 				return (NULL);
// 		}
// 		bytesread = read(fd, buf, BUFFER_SIZE);
// 		if (bytesread <= 0)
// 		{
// 			buf[0] = '\0';
// 			if (bytesread < 0)
// 				return (NULL);
// 			return (line);
// 		}
// 		buf[bytesread] = '\0';
// 	}
// 	line = append_line(line, buf);
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	buf_len_nl = ft_strlen_nl(buf) + 1;
// 	while (buf[buf_len_nl] && buf_len_nl < BUFFER_SIZE)
// 		buf[i++] = buf[buf_len_nl++];
// 	buf[i] = '\0';
// 	return (line);
// }

// TO DO:
// 1. TEST ALL edge cases
// 1.2. big BUFFER_SIZEs (subject),
// 1.3. extremely long line,
// 1.4. change fd mid function calls
// 1.5. other fails to check for NULL?
// 2. divide function into helpers
// 3. Norminette
// 4. Francinette
