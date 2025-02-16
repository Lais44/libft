/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:21:11 by lleal-go          #+#    #+#             */
/*   Updated: 2025/02/15 17:33:14 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	n;

	n = 0;
	while (s && *s++)
		n++;
	return (n);
}

char	*ft_substr_g(char *s, unsigned int start, size_t len, int this_free)
{
	size_t	v;
	size_t	size;
	char	*c_s;

	size = 0;
	v = len;
	while (s && s[size])
		size++;
	if ((len + start) >= size)
		v = (size - start);
	if (start > size)
		return (NULL);
	c_s = (char *)malloc((v + 1) * sizeof(char));
	if (c_s == NULL)
	{
		if (this_free == 1)
			free(s);
		return (NULL);
	}
	c_s[v] = '\0';
	while (v--)
		c_s[v] = s[start + v];
	if (this_free == 1)
		free(s);
	return ((char *)c_s);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	size_t	size;
	size_t	aux;
	char	*c;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2 || !*s2)
		return (s1);
	size = ((ft_strlen(s1) + ft_strlen(s2)));
	c = (char *)malloc((size + 1) * sizeof(char));
	if (!c)
		return (free(s1), NULL);
	c[size] = '\0';
	aux = -1;
	size = 0;
	while (s1[++aux])
		c[aux] = s1[aux];
	while (s2[size])
		c[aux++] = s2[size++];
	return (free(s1), c);
}

char	*ft_strchr_g(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
		if ((char)c == *s++)
			return ((char *)--s);
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
