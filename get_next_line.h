/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:00:04 by mkwizera          #+#    #+#             */
/*   Updated: 2024/05/30 08:01:34 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(char *str, int c);
char		*get_next_line(int fd);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *s, unsigned int start, size_t len);

#endif