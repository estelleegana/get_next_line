/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:54:16 by estegana          #+#    #+#             */
/*   Updated: 2023/11/20 11:54:17 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

//gnl
int		newline(char *str);
char	*ft_linepure(char *stash);
char	*ft_cleanstash(char	*stash);
char	*get_next_line(int fd);
//gnl_u
int		ft_strlen(char *str);
int		i_newline(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *dst, char *src);

#endif
