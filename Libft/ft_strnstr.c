/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:33:30 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/06 17:28:55 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	char	*p;
	char	size;

	i = 0;
	p = NULL;
	size = len;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		p = (char *)haystack;
		while (haystack[i] == needle[i] && len--)
			if (!needle[++i])
				return (p);
		len = size - 1;
		size = len;
		haystack++;
		i = 0;
	}
	return (NULL);
}
