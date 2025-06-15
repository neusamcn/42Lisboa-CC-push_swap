/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/15 20:42:24 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buf1[BUFFER_SIZE + 1];
	static char		*nextline;
	static ssize_t	offset;
	static ssize_t			bytesread;

	// static char		buf2[BUFFER_SIZE + 1];
	// char		*line;
	if (BUFFER_SIZE > 0 && fd >= 0)
	{
		if (offset == 0)
		{
			bytesread = read(fd, buf1, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
		}
		if (offset < bytesread)
		{
			if (ft_strchr(&buf1[offset], 10) != NULL)
			{
				nextline = ft_substr_gnl(buf1, offset, BUFFER_SIZE);
				offset += ft_strlen_nl(nextline);
				return (nextline);
			}
			// should i break?
			ft_strlcpy(nextline, buf1, bytesread);
			bytesread = read(fd, buf1, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
			// concatenate nextline with next trimmed read...
		}
		offset = 0;
	}
	return (NULL);
}

// {
// 	ssize_t	tempread;
// 	ssize_t	bytesread;
// 	ssize_t	i;
// 	ssize_t	i_max;
// 	static char	*buffer;
// 	char	*line_cnt; // ?
// 	t_list	*line_nd;
// 	t_list	**line_lst;

// 	t_list *ft_lstlast(t_list * lst);
// 	void ft_lstadd_back(t_list **lst, t_list *new);
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	// tempread = 0;
// 	bytesread = 0;
// 	i = 0;
// 	i_max = 0;
// 	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
// 	if (!buffer)
// 		return (NULL);
// 	tempread = read(fd, buffer, BUFFER_SIZE);
// 	if (tempread < 0)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	if (tempread == 0)
// 		return (buffer);
// 	if (ft_strrchr(buffer, 10) != NULL)
// 	{
// 		// return (substr up to '\n' & save rest for next call - static buffer);
// 	}
// 	line_nd = ft_lstnew(buffer);
// 	*line_lst = line_nd; // needed? makes sense?
// 	while (tempread > 0)
// 	{
// 		bytesread += tempread;
// 		tempread = read(fd, buffer, BUFFER_SIZE);
// 		if (ft_strrchr(buffer, 10) == NULL)
// 			ft_lstadd_back(line_lst, buffer);
// 	}
// 	// found '\n'. then what
// 	while (buffer[i_max] != '\n')
// 		i_max++;
// 	while (i < i_max)
// 	{
// 		line_cnt[i] = buffer[i];
// 		i++;
// 	}
// 	line_nd = ft_lstnew(line_cnt); // do i need to have
// 	ft_lstadd_back(line_lst, line_nd);
// 	// 1. save buffer leftover; 2. cpy all to char*; 3. return char*

// }

// {
// 	ssize_t	tempread;
// 	size_t	bytesread;
// 	size_t	i;
// 	char	*buffer;
// 	char	*templine;
// 	char	*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	tempread = 0;
// 	bytesread = 0;
// 	i = 0;
// 	templine = NULL;
// 	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while (tempread < BUFFER_SIZE)
// 	{
// 		tempread = read(fd, buffer, BUFFER_SIZE);
// 		if (tempread < 0 || tempread >= BUFFER_SIZE)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		while (*buffer != 0 && *buffer != '\n')
// 		{
// 			templine[bytesread] = *buffer;
// 			bytesread++;
// 			buffer++;
// 		}
// 		if (templine[bytesread - 1] == '\n')
// 		{
// 			free(buffer);
// 			return (templine);
// 		}
// 		bytesread += tempread;
// 		tempread = 0;
// 	}
// 	line = malloc((bytesread + 1) * sizeof(char));
// 	if (!line)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	while (*templine != '\n' && i <= bytesread)
// 	{
// 		line[i] = templine[i];
// 		i++;
// 	}
// 	return (line);

// buffer = ft_calloc(1, sizeof(char));
// if (!buffer)
// 	return (NULL);
// templine = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// if (!templine)
// {
// 	free(buffer);
// 	return (NULL);
// }
// while (*buffer != '\n' && bytesread < BUFFER_SIZE)
// {
// 	tempread = read(fd, buffer, 1);
// 	if (tempread == EOF)
// 	{
// 		free(buffer);
// 		return (templine);
// 	}
// 	else if (tempread != 1)
// 	{
// 		free(buffer);
// 		free(templine);
// 		return (NULL);
// 	}
// 	templine[bytesread] = *buffer;
// 	bytesread++;
// }
// free(buffer);
// if (templine[bytesread - 1] == '\n')
// 	return (templine);
// free(templine);
// return (NULL);
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
