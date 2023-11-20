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

#include "get_next_line.h"

//voir si y a un \n
int	newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
//ecrire tout ce qu'il y a avant le \n
char	*ft_linepure(char *stash)
{
	int			i;
	char		*new;

	i = 0;
	new = malloc(sizeof(char) * (i_newline(stash) + 1));
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		i++;
	}
	new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

//nettoyer avant le \n et garder ce qu'il y a apres
char	*ft_cleanstash(char	*stash)
{
	char	*cleaned;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cleaned = malloc(sizeof(char) * (ft_strlen(stash) - i_newline(stash) + 1));
	if (!cleaned)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		i++;
		while (stash[i])
			cleaned[j++] = stash[i++];
	}
	return (cleaned);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	int			readbytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (stash == NULL)
	{
		while (readbytes > 0)
		{
			buf[readbytes] = '\0';
			stash = ft_strdup(buf);
			if (newline(stash))
				break ;
		}
	}
	else
	{
		while (readbytes > 0)
		{
			buf[readbytes] = '\0';
			stash = ft_strjoin(stash, buf);
			if (newline(stash))
				break ;
		}
	}
	line = ft_linepure(stash);
	stash = ft_cleanstash(stash);
	free(buf);
	if (!stash)
		return (free(line), NULL);
	if (!line)
		return (free(stash), NULL);
	//printf("stash restante : %s\n", stash);
	return (line);
}
