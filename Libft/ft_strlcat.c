/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:23:34 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/04 20:26:17 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	lendst;
	int		i;

	len = 0;
	lendst = 0;
	i = 0;
	while (dst[lendst])
		lendst++;
	while (src[len])
		len++;
	if (dstsize <= lendst)
		return (len + dstsize);
	len += lendst;
	while (dstsize - lendst > 1 && src[i])
		dst[lendst++] = src[i++];
	dst[lendst] = '\0';
	return (len);
}
