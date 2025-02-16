/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:48 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/15 17:30:40 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_null(char **to_free)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	return (NULL);
}

char	*read_document(int fd, char *rest)
{
	char		*buffer;
	int			found_nl;
	long long	bytes;

	if (rest && ft_strchr(rest, '\n'))
		return (rest);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buffer), free(rest), NULL);
	bytes = 1;
	found_nl = 0;
	while (!found_nl && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && (!rest || !*rest)))
			return (free(buffer), free(rest), NULL);
		buffer[bytes] = '\0';
		if (ft_strchr(buffer, '\n'))
			found_nl = 1;
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free(buffer), free(rest), NULL);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;
	ssize_t		i;

	i = 0;
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_null(&rest));
	rest = read_document(fd, rest);
	if (!rest || !*rest)
		return (free_null(&rest));
	while (rest[i] && rest[i] != '\n')
		i++;
	str = ft_substr_g(rest, 0, i + 1, 0);
	if (!str || !*str)
		return (free_null(&rest));
	if (rest[i] == '\n')
		i++;
	rest = ft_substr_g(rest, i, BUFFER_SIZE, 1);
	if (!rest)
		return (free(str), free_null(&rest));
	return (str);
}
