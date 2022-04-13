/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:56:24 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 00:02:19 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sysexits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

void	*ft_gnl_calloc(size_t n, size_t size);
char	*ft_gnl_strjoin(char const *s1, char *s2);
char	*ft_gnl_strcpy(char *dest, const char *src);
char	*ft_gnl_strchr(const char *s, int c, int is_before);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *str);
char	*get_next_line(int fd);
char	*ft_strchr_before(const char *s, int c);
void	ft_gnl_bzero(void *buf, size_t n);

#endif
