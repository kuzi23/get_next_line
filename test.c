/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:09:41 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/26 10:08:43 by kuzi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define BUFFER_SIZE 4096

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
	memcpy(read_data, buffer, bytes_data);
	read_data[bytes_data] = '\0';
	return (read_data);
}

static char	*ft_exctract_line(char *read_data)
{
	char	*left0ver;
	char 	*start;

	if (*read_data == '\0')
		return (NULL);
	while (*read_data == '\n')
		read_data ++;
	start = read_data;
	while (*read_data != '\n' && *read_data != '\0')
	{
		read_data++;
	}
	left0ver = malloc(strlen(read_data)+1);
	if (left0ver == NULL)
		return (NULL);
	memcpy(left0ver, start, read_data - start);
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
		leftover = read_data + strlen(line) + 1;
	else
		leftover = NULL;

	return (line);
}

int main()
{
    int fd;
    char *line;

    // Open a file for reading
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Read lines using get_next_line until EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line); // Free memory allocated by get_next_line
    }

    // Close the file descriptor
    close(fd);

    return (0);
}
