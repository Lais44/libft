/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:56:47 by lleal-go          #+#    #+#             */
/*   Updated: 2024/10/28 20:28:23 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*st;
	size_t		i;

	st = malloc(ft_strlen(s) + 1);
	if (!st)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
