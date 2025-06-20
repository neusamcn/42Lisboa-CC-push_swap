/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:40:10 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/06/20 18:15:29 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
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

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;
	char			*p;

	i = 0;
	chr = (unsigned char)c;
	p = (char *)s;
	while (*(p + i))
	{
		if (*(p + i) == chr)
			return (p + i);
		i++;
	}
	if (chr == '\0')
		return (p + i);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
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

size_t	ft_strlcpy_nl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0 && src[ft_strlen(src)] == '\0')
	{
		while (i < size - 1 && src[i] != '\n' && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		if (src[i] == '\n')
		{
			dst[i] = '\n';
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(dst));
}

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	i;
// 	size_t	s1len;
// 	char	*trimmed;

// 	if (!s1)
// 		return (NULL);
// 	i = 0;
// 	s1len = ft_strlen(s1);
// 	while (s1[i] && ft_strchr(set, (int)s1[i]) != NULL)
// 		i++;
// 	if (i == s1len)
// 	{
// 		trimmed = ft_calloc(1, 1);
// 		if (!trimmed)
// 			return (NULL);
// 		return (trimmed);
// 	}
// 	s1len--;
// 	while (s1[s1len] && ft_strrchr(set, (int)s1[s1len]) != NULL)
// 		s1len--;
// 	trimmed = malloc((s1len - i + 2) * sizeof(char));
// 	if (trimmed == NULL)
// 		return (NULL);
// 	ft_strlcpy(trimmed, s1 + i, s1len - i + 2);
// 	return (trimmed);
// }

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	rem;
	char			*substr;
	size_t			slen;

	slen = ft_strlen(s);
	if (!s || start >= slen)
		return (ft_calloc(1, 1));
	if (slen - start >= len)
		substr = malloc((len + 1) * sizeof(char)); // switch to calloc?
	else
		substr = malloc((slen - start + 1) * sizeof(char)); // switch to calloc?
	if (!substr)
		return (NULL);
	rem = 0;
	while (s[rem])
	{
		if (s[rem] == 10)
			break ;
		rem++;
	}
	i = 0;
	if (rem > len)
		return (NULL);
	while (s[start] && start <= rem)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0'; // remove (calloc)?
	return (substr);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*dest_uc;
// 	unsigned char	*src_uc;

// 	dest_uc = (unsigned char *)dest;
// 	src_uc = (unsigned char *)src;
// 	if (dest == src || n == 0)
// 		return (dest);
// 	if (dest < src)
// 		return (ft_memcpy(dest, src, n));
// 	while (n > 0)
// 	{
// 		dest_uc[n - 1] = src_uc[n - 1];
// 		n--;
// 	}
// 	dest = (void *)dest_uc;
// 	return (dest);
// }
