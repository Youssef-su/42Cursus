/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:19:39 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/06 17:27:58 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	block(char const *s, char c)
{
	int	num;
	int	i;

	num = 1;
	i = 0;
	while (!s[i] || s[i] == c)
	{
		num = 0;
		i++;
	}
	i = 0;
	while (s[i])
		if (s[i++] == c && s[i] != c && s[i])
			num++;
	return (num);
}

static char	**free_memory(char **ptr, int block)
{
	while (block--)
		free(ptr[block]);
	return (NULL);
}

static char	**fill(char **ptr, char const *s, char c, int num)
{
	int		j;
	size_t	size;

	j = 0;
	size = 0;
	while (*s)
	{
		while (s[size] && s[size] != c)
			size++;
		if (size && j < num)
		{
			ptr[j] = (char *) malloc(size + 1);
			if (!ptr[j])
				free_memory(ptr, j);
			ft_memcpy(ptr[j], s, size);
			ptr[j][size] = '\0';
			s += size;
			size = 0;
			j++;
		}
		else
			s++;
	}
	ptr[num] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		num;

	if (!s)
		return (NULL);
	num = block(s, c);
	p = (char **) malloc((num + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	fill(p, s, c, num);
	return (p);
}
