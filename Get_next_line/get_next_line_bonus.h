/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:01:26 by ybahmane          #+#    #+#             */
/*   Updated: 2021/11/16 18:53:46 by ybahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h> 
# include <stdlib.h>
# include <fcntl.h> 
# include <errno.h>
# include <unistd.h>
# include <string.h> 
# include <time.h> 

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*check1(char *s, char **ptr, int start);
int		initialise(char **s, char **ptr, char **str, int *start);
char	*get_next_line(int fd);
#endif
