/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:39:42 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/04 18:56:24 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	ssize_t	tempread;
	ssize_t	i;
	char	*buffer;
	char	*line;

	t_list *ft_lstnew(void *content);
	t_list *ft_lstlast(t_list * lst);
	void ft_lstadd_back(t_list * *lst, t_list * new);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// tempread = 0;
	i = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	tempread = read(fd, buffer, BUFFER_SIZE);
	if (tempread < 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc();
	while (buffer[i] !=  '\n' && i <= tempread)
	{
		line[i] = buffer[i];
		if (line[i] == '\n')
		{
			free(buffer);
			return (line);
		}
		i++;
	}

}
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
