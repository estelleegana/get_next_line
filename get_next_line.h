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
char	*ft_strjoin(char *stash, char *buf);
char	*ft_cleanstash(char *stash);
char	*ft_generatestash(char *stash, int fd, char *buf);
char	*ft_linepure(char *str);
char	*get_next_line(int fd);
//gnlu
int		ft_strlen(char *s);
void	ft_bzero(char *buf);
int		i_nl(char *line);

#endif
