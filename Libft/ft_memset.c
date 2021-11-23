/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:37:42 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/04 19:38:44 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*src;

	src = b;
	while (len--)
		*src++ = (unsigned char) c;
	return (b);
}
