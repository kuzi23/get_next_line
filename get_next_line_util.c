/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwizera <mkwizera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:53:08 by mkwizera          #+#    #+#             */
/*   Updated: 2024/03/20 08:54:30 by mkwizera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *s1, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = (char *)dst;
	src = (const char *)s1;
	if (!dest && !src)
	{
		return (NULL);
	}
	if (src != dest)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}
