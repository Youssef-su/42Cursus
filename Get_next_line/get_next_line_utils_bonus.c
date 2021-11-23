/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:01:42 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/16 18:16:15 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = dst;
	source = src;
	if (!src && !dst)
		return (NULL);
	while (n--)
	{
		*dest++ = *source++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char) c)
			return ((char *)--s);
	if (!c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1));
	ft_memcpy(p + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free ((char *)s1);
	return (p);
}

int	initialise(char **s, char **ptr, char **str, int *start)
{
	*start = 0;
	*s = (char *) malloc(BUFFER_SIZE + 1);
	if (!*s)
		return (0);
	*s[0] = 0;
	*str = NULL;
	if (!*ptr)
	{
		*ptr = malloc(1);
		if (!*ptr)
			return (0);
		*ptr[0] = 0;
	}
	return (1);
}
