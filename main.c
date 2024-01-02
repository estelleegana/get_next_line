/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:49:03 by estegana          #+#    #+#             */
/*   Updated: 2023/11/20 11:49:05 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	char *line;
	(void)ac;
	(void)av;

	fd = open("file_test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("la ligne a retourner: %s", line);
		free(line);
		close(fd);
		//break ;
	}
	return (0);
}
