/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/12 18:26:02 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buf1;
	static char	*buf2;
	char		*line;
	char		*nextline;
	ssize_t		bytesread;

	if (BUFFER_SIZE > 0 && fd >= 0)
	{
		buf1 = ft_calloc(BUFFER_SIZE + 1, 1);
		bytesread = read(fd, buf1, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			free(buf1);
			return (NULL);
		}
		buf2 = ft_calloc(BUFFER_SIZE + 1, 1);
		bytesread = read(fd, buf2, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buf1);
			free(buf2);
			return (NULL);
		}
		line = ft_strjoin_nl(buf1, buf2);
		free(buf1);
		if (bytesread == 0)
		{
			free(buf2);
			return (line);
		}
		while (bytesread >= 0)
		{
			bytesread = read(fd, buf2, BUFFER_SIZE);
			nextline = ft_strjoin_nl(line, buf2);
			if (ft_strrchr(nextline, 10) != NULL || bytesread == 0)
			{
				free(buf2);
				free(line);
				return (nextline);
			}
			ft_strlcpy(line, nextline, ft_strlen(nextline));
		}
		free(buf2);
		free(line);
		free(nextline);
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
// 		// return (substring up to '\n' & save rest for next call - static buffer);
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
