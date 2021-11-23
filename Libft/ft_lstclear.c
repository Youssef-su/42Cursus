/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:28:31 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/06 17:17:02 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*p;

	if (!*lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		p = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = p;
	}
	*lst = NULL;
}
