/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:31:06 by lleal-go          #+#    #+#             */
/*   Updated: 2025/01/21 17:30:15 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
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
