/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:09:41 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/23 17:23:16 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
// #include <fcntl.h>
#include <string.h>
// #define BUFFER_SIZE 4096

// char	*ft_read_from_fd(int fd)
// {
// 	char	buffer[BUFFER_SIZE];
// 	char	*read_data;
// 	int		bytes_data;

// 	bytes_data = 0;
// 	bytes_data = read(fd, (char *)buffer, BUFFER_SIZE);
// 	if (bytes_data == -1)
// 	{
// 		return (NULL);
// 	}
// 	else if (bytes_data == 0)
// 	{
// 		return (NULL);
// 	}
// 	read_data = (char *)malloc(bytes_data +1);
// 	if (read_data == NULL)
// 		return (NULL);
// 	ft_memcpy(read_data, buffer, bytes_data);
// 	read_data[bytes_data] = '\0';
// 	return (read_data);
// }

static char	*ft_exctract_line(char *read_data)
{
	char	*left0ver;

	if (*read_data == '\0')
		return (NULL);
	while (*read_data == '\n')
		read_data ++;
	left0ver = malloc(strlen(read_data)+1);
	if (*left0ver != *read_data)
	{
		while (*read_data != '\n' && *read_data != '\0')
		{
			*left0ver++ = *read_data++;
		}
	}
	if (left0ver == NULL)
		return (NULL);
	*left0ver = '\0';
	return (left0ver);
}

int main()
{
    char name[40] = "marius12 \n kwizera \n Tresor.";
    char *extracted_line = ft_exctract_line(name);
    if (extracted_line != NULL) {
        printf("%s", extracted_line);
    }
    return (0);
}
