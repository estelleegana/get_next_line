#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

	fd = open("file_test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		//if (line == NULL)
		//	break;
		printf("%s", line);
		free(line);
		break;
	}
	return (0);
}

//int main()
//{
//	int fd;
//	char *buf;

//	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	fd = open("file_test.txt", O_RDONLY);
//	read(fd, buf, BUFFER_SIZE);
//	printf("%s", buf);
//}
