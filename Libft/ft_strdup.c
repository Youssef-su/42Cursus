/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:17:58 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/06 17:28:19 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *) malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	if (!*s1)
		*p = '\0';
	else
		p = ft_memcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
