/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjointest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:00:39 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/09 16:08:22 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	s = (void *)ptr;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	flowcheck;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	flowcheck = nmemb * size;
	if (flowcheck / nmemb == size)
	{
		ptr = malloc(nmemb * size);
		if (ptr == NULL)
			return (NULL);
		ft_bzero(ptr, size * nmemb);
		return (ptr);
	}
	return (NULL);
}

char	*ft_strjoin_nl(char const *s1, char const *s2)
{
	char	*join;
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	join = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (join == NULL)
		return (NULL);
	while (s1[i1] != '\0')
	{
		join[i1] = s1[i1];
		i1++;
	}
	while (s2[i2] != '\n' && s2[i2] != '\0')
	{
		join[i1 + i2] = s2[i2];
		i2++;
	}
	if (s2[i2] == '\n')
		join[i1 + i2] = '\n';
	return (join);
}

int	main(void)
{
	printf("%s\n", ft_strjoin_nl("hello..\n.", "test1\0test2\ntest3"));
	return (0);
}
