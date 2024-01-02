/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:50:18 by estegana          #+#    #+#             */
/*   Updated: 2023/11/20 11:50:20 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

char	*ft_strjoin(char *dst, char *src)
{
	char	*join;
	int		i;

	join = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (dst && dst[i])
	{
		join[i] = dst[i];
		i++;
	}
	i = 0;
	while (src && src[i])
	{
		join[i + ft_strlen(dst)] = src[i];
		i++;
	}
	join[i + ft_strlen(dst)] = '\0';
	free(dst);
	return (join);
}

char	*ft_cleanstash(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*ft_generatestash(char *stash, int fd, char *buf)
{
	int	res;

	res = 1;
	while (i_nl(stash) < 0 && res != 0)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		buf[res] = '\0';
		if (res > 0)
		{
			stash = ft_strjoin(stash, buf);
			if (!stash)
				return (NULL);
			ft_bzero(buf);
		}
	}
	if (res == -1)
		return (NULL);
	return (stash);
}

char	*ft_linepure(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (i_nl(str) >= 0)
		res = malloc(sizeof(char) * (i + 2));
	else
		res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = ft_generatestash(stash, fd, buf);
	if (!stash)
		return (free(buf), NULL);
	free(buf);
	line = ft_linepure(stash);
	stash = ft_cleanstash(stash);
	if (!stash)
		return (free(line), NULL);
	if (!line)
		return (free(stash), NULL);
	return (line);
}
