/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:36:08 by mkwizera          #+#    #+#             */
/*   Updated: 2024/05/30 07:56:31 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line_buffer(int fd, char *buf, char *final)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!final)
			final = ft_strdup("");
		char_temp = final;
		final = ft_strjoin(char_temp, buf);
		if (!final)
			return (NULL);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (final);
}

static char	*_extract_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line)- count);
	if (!backup)
		backup = NULL;
	if (backup[0] == '\0')
	{
		free (backup);
		backup = NULL;
		return (NULL);
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line_buffer(fd, buf, final);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	final = _extract_line(line);
	return (line);
}
