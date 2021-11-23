/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:00:05 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/04 21:03:36 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;

	source = src + len - 1;
	destination = dst + len - 1;
	if (!src && !dst)
		return (NULL);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*destination-- = *source--;
	return (dst);
}
