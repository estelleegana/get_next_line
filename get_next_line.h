/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:37 by estegana          #+#    #+#             */
/*   Updated: 2023/11/09 14:14:38 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

//gnl
char	*ft_strcat(char *dst, char *src);
int	newline(char *str);
char	*get_next_line(int fd);
char	*ft_linepure(char *stash);
char	*ft_cleanstash(char	*stash);
char	*get_next_line(int fd);
//gnl_u
int	ft_strlen(char *str);
int	i_newline(char *str);

#endif

