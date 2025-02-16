/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:31:59 by lleal-go          #+#    #+#             */
/*   Updated: 2024/10/23 19:38:53 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destt;
	const char	*srct;
	size_t		i;

	destt = (char *)dest;
	srct = (const char *)src;
	i = 0;
	if (!destt && !srct)
		return (NULL);
	while (i < n)
	{
		destt[i] = srct[i];
		i++;
	}
	return (dest);
}
