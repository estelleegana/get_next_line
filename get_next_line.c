#include "get_next_line.h"

//ajouter une chaine de caractere a dst
char	*ft_strjoin(char *dst, char *src)
{
	int	i;
	int	j;
	int	k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	if (!src)
		return (dst);
	new = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	while (dst && dst[j])
		new[i++] = dst[j++];
	while (src[k])
		new[i++] = src[k++];
	new[i] = '\0';
	return (new);
}

//verifier s'il y a un \n. 1 si oui, sinon 0
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
	int	i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * i_newline(stash) + 1);
	while (stash[i] && stash[i] != '\n')
	{
		new[i] = stash[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
//nettoyer avant le \n et garder ce qu'il y a apres
char	*ft_cleanstash(char	*stash)
{
	char	*cleaned;
	int	i;
	int	j;

	i = 0;
	j = 0;
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
//fonction principale
//char	*get_next_line(int fd)
//{
//	char	*line;
//	static char	*stash;
//	char	*buf;

//	stash = NULL;
//	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	//0. proteger en cas bizarre
//	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
//		return (NULL);
//	line = NULL;
//	//1. lire fd et mettre ds une chn de char
//	while (read(fd, buf, BUFFER_SIZE) > 0 && newline(stash) != 1)
//	{
//		ft_strcat(stash, buf);
//		if (newline(stash) == 1)
//			line = ft_linepure(stash);
//	}
//	//3. nettoyer stash
//	ft_cleanstash(stash);
//	return (line);
//}

char	*get_next_line(int fd)
{
	int readbytes;
	static char *stash;
	char *line;
	char *buf;
	//char *temp;

	line = NULL;
	stash = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readbytes = read(fd, buf, BUFFER_SIZE);
	//proteger les cas exceptionnels
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	//tant que read (=curseur de lecture) lit qqch
	while (readbytes > 0)
	{
		buf[readbytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (newline(buf))
			break;
		readbytes = read(fd, buf, BUFFER_SIZE);
	}
	line = ft_linepure(stash);
	return (line);
}

