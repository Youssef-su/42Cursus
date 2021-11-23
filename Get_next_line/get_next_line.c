/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:16:55 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/16 18:28:21 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_last(char *s, char **ptr)
{
	char	*str;
	size_t	len;

	str = NULL;
	len = ft_strlen(*ptr);
	if (len)
	{
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		ft_memcpy(str, *ptr, len + 1);
	}
	free(s);
	free(*ptr);
	*ptr = NULL;
	return (str);
}

char	*get_line(char *s, int *pos, int start, int *len)
{
	char	*str;

	str = NULL;
	while (s[start])
	{
		if (!(s[start] - '\n'))
		{
			*len = ft_strlen(s + start + 1);
			str = malloc(start + 2);
			if (!str)
				return (NULL);
			str[start + 1] = 0;
			ft_memcpy(str, s, start + 1);
			*pos = start;
			return (str);
		}
		start++;
	}
	return (str);
}

char	*check_remaining(char **ptr, int start)
{
	char	*tab;
	char	*str;
	int		len;
	int		pos;

	str = get_line(*ptr, &pos, start, &len);
	if (len)
	{
		tab = malloc(len + 1);
		if (!tab)
			return (NULL);
		ft_memcpy(tab, *ptr + pos + 1, len + 1);
		free(*ptr);
		*ptr = tab;
	}
	else
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (str);
}

char	*check1(char *s, char **ptr, int start)
{
	char	*str;

	str = check_remaining(ptr, start);
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	size_t		size;
	char		*s;
	char		*str;
	static char	*ptr;
	int			start;

	if (fd < 0 || BUFFER_SIZE <= 0 || !initialise(&s, &ptr, &str, &start))
		return (NULL);
	if (ft_strchr(ptr, '\n'))
		return (check1(s, &ptr, start));
	size = read(fd, s, BUFFER_SIZE);
	if (!size || size == (unsigned long)(-1))
		return (get_last(s, &ptr));
	while (size > 0)
	{
		s[size] = 0;
		ptr = ft_strjoin(ptr, s);
		if (!ptr)
			return (NULL);
		if (ft_strchr(s, '\n'))
			return (check1(s, &ptr, start));
		start += size;
		size = read(fd, s, BUFFER_SIZE);
	}
	return (get_last(s, &ptr));
}
