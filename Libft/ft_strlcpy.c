/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:26:31 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/04 20:29:37 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = 0;
	if (dstsize)
	{
		len = -1;
		while (src[++len] && dstsize-- > 1)
			dst[len] = src[len];
		dst[len] = '\0';
	}
	while (src[len])
		len++;
	return ((size_t) len);
}
