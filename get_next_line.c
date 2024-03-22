/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzi <kuzi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:55:17 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/22 16:35:01 by kuzi             ###   ########.fr       */
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
	ft_memcpy(read_data, buffer, BUFFER_SIZE);
	read_data[bytes_data] = '\0';
	return (read_data);
}
// ngiye noneho guhita nkora line extractin ninyirangiza 
// igomba kuza kuritaninga new linendibuze guikoresh mur
// get next line 
char *ft_exctract_line(char *read_data,char *left0ver, int leftoversize)
{
	int read_data_size;

	read_data_size = ft_strlen(read_data);
	// ibintu byo gukora aha nuko ndi bunyure muri readdata nshake new line 
	// noneho aho nyibonera nyireturning noneho mpite na updating leftover
	// nshyiramo amagambo asigaye nakuyeho abanza.
	// niba ari yo yanyuma yar isigaye mpite nkora break.
	while (*read_data != '\n')
	{
		
	}
}