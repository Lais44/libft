/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:20:56 by lleal-go          #+#    #+#             */
/*   Updated: 2024/10/23 19:34:19 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*st;
	unsigned char		ct;
	size_t				i;

	st = (unsigned char *) s;
	ct = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (st[i] == ct)
		{
			return ((char *)&st[i]);
		}
		i++;
	}
	return (0);
}
