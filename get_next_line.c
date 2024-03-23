/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:55:17 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/23 14:24:37 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	ft_memcpy(read_data, buffer, bytes_data);
	read_data[bytes_data] = '\0';
	return (read_data);
}

char	*ft_exctract_line(char *read_data, char *left0ver)
{
	if (*read_data == '\0')
		return (NULL);
	while (*read_data == '\n')
		read_data ++;
	while (*read_data != '\n' && *read_data != '\0')
	{
		*left0ver++ = *read_data++;
	}
	*left0ver = '\0';
	return (left0ver);
}
// ngiye noneho guhita nkora line extractin ninyirangiza 
// igomba kuza kuritaninga new linendibuze guikoresh mur
// get next line
// ibintu byo gukora aha nuko ndi bunyure muri readdata nshake new line 
// noneho aho nyibonera nyireturning noneho mpite na updating leftover
// nshyiramo amagambo asigaye nakuyeho abanza.
// niba ari yo yanyuma yar isigaye mpite nkora break.
