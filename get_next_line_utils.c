/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:45 by estegana          #+#    #+#             */
/*   Updated: 2023/11/09 14:14:46 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int	i_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
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
// voir si y a un \n
int newline(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}
