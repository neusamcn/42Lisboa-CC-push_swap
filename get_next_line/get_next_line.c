/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/20 18:31:55 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*nextline;
	ssize_t		bytesread;
	int			i;
	int			buf_nl_len;

	// 'memmove'
	if (BUFFER_SIZE > 0 && fd >= 0)
	{
		if (!*buf)
		{
			bytesread = read(fd, buf, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
		}
		if (ft_strchr(buf, 10))
		{
			buf_nl_len = ft_strlen_nl(buf);
			line = ft_calloc(buf_nl_len + 1, 1);
			ft_strlcpy_nl(line, buf, BUFFER_SIZE);
			// 'memmove'
			i = 0;
			while (i < BUFFER_SIZE - buf_nl_len)
			{
				buf[i] = buf[buf_nl_len];
				i++;
				buf_nl_len++;
			}
			buf[i] = '\0';
			return (line);
		}
		// !'\n' after 1st read
		line = ft_calloc(BUFFER_SIZE + 1, 1);
		while (!ft_strchr(buf, 10))
		{
			ft_strlcpy_nl(line, buf, BUFFER_SIZE);
			bytesread = read(fd, buf, BUFFER_SIZE);
			nextline = ft_strjoin_nl(line, buf);
		}
		if (ft_strchr(buf, 10))
		{
			buf_nl_len = ft_strlen_nl(buf);
			line = ft_calloc(buf_nl_len + 1, 1);
			nextline = ft_strjoin_nl(line, buf);
			// 'memmove'
			i = 0;
			while (i < BUFFER_SIZE - buf_nl_len)
			{
				buf[i] = buf[buf_nl_len];
				i++;
				buf_nl_len++;
			}
			buf[i] = '\0';
			return (nextline);
		}
	}
	return (NULL);
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
