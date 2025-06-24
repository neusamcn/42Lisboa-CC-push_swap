/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:47 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/24 14:35:03 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_read_to_nl_vars
{
	int		i;
	int		buf_len_nl;
	ssize_t	bytesread;
}			t_read_to_nl_vars;

void		*ft_calloc(size_t nmemb, size_t size);

char		*append_line(char *s1, char const *buf);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*read_to_nl(int fd, char *buf, char *line);

size_t		ft_strlen_nl(const char *s);

#endif