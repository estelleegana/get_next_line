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

// ecrire tout ce qu'il y a avant le \n
char *ft_linepure(char *stash)
{
	int i;
	char *new;

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

// nettoyer avant le \n et garder ce qu'il y a apres
char *ft_cleanstash(char *stash)
{
	char *cleaned;
	int i;
	int j;

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

char *get_next_line(int fd)
{
	static char *stash = NULL;
	char *line;
	char *buf;
	int readbytes = 0;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (!buf)
		return (NULL);
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || readbytes < 0)
		return (NULL);
	//premiere boucle
	if (stash == NULL)
		stash = ft_strdup(buf);
	printf("premiere init %s", buf);
	//autre + premiere boucle
	while (buf)
	{
		if (newline(stash))
			break ;
		else
		{
			stash = ft_strjoin(stash, buf);
			printf("join %s", stash);
		}

	}
	//isoler tt cquil y a avant \n
	line = ft_linepure(stash);
	printf("line :::: %s", line);
	//nettoyer avant \n laisser le reste
	stash = ft_cleanstash(stash);
	printf("stash ::::%s", stash);
	free(buf);
	if (!stash)
		return (free(line), NULL);
	if (!line)
		return (free(stash), NULL);
	return (line);
}
