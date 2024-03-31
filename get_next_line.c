/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:55:17 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/27 08:31:48 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_from_fd(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*read_data;
	int		bytes_data;

	bytes_data = 0;
	bytes_data = read(fd, (char *)buffer, BUFFER_SIZE);
	if (bytes_data == -1)
	{
		return (NULL);
	}
	else if (bytes_data == 0)
	{
		return (NULL);
	}
	read_data = (char *)malloc(bytes_data +1);
	if (read_data == NULL)
		return (NULL);
	ft_memcpy(read_data, buffer, bytes_data);
	read_data[bytes_data] = '\0';
	return (read_data);
}

static char	*ft_exctract_line(char *read_data)
{
	char	*left0ver;
	char	*start;

	if (*read_data == '\0')
		return (NULL);
	while (*read_data == '\n')
		read_data ++;
	start = read_data;
	while (*read_data != '\n' && *read_data != '\0')
	{
		read_data++;
	}
	left0ver = malloc(ft_strlen(read_data)+2);
	if (left0ver == NULL)
		return (NULL);
	ft_memcpy(left0ver, start, read_data - start);
	if (*read_data == '\n')
		left0ver[read_data - start] = '\n';
	else
	{
		left0ver[read_data - start] = '\0';
	}
	left0ver[read_data - start] = '\0';
	return (left0ver);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*read_data;

	leftover = NULL;
	if (!leftover)
	{
		read_data = ft_read_from_fd(fd);
		if (!read_data)
			return (NULL);
	}
	else
		read_data = leftover;
	line = ft_exctract_line(read_data);
	if (line)
		leftover = read_data + ft_strlen(line) + 1;
	else
		leftover = NULL;
	return (line);
}

// int	main()
// {
// 	int fd;
// 	char *line;
// 	fd = open("input.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
//         perror("Error opening file");
//         return 1;
//     }
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
// 	}
//     close(fd);
//     return (0);
// }

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("input.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (*line != '\0')
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	return (0);
// }
