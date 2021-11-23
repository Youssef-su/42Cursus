/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:51:33 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/06 17:29:23 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	int				i;
	unsigned int	size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = (char *) malloc(len + 1);
	if (!p)
		return (NULL);
	while (len-- && start < size)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
