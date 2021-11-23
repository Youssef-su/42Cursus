/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:19:20 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/04 19:21:52 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocate(int n)
{
	int	size;

	size = 0;
	if (n <= 0 && ++size)
		n = -n;
	while (n && ++size)
		n = n / 10;
	return (size);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	num;

	size = allocate(n);
	str = (char *) malloc(size + 1);
	num = n;
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = 45;
		num = -num;
	}
	if (!num)
		str[0] = '0';
	str[size--] = '\0';
	while (num)
	{
		str[size--] = num % 10 + 48;
		num = num / 10;
	}
	return (str);
}
