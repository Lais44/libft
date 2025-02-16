/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:53:41 by lleal-go          #+#    #+#             */
/*   Updated: 2024/10/28 19:53:28 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	counter;

	i = 0;
	j = 0;
	counter = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[counter] && counter < len)
	{
		while (big[i] == little[j] && (i < len))
		{
			i++;
			j++;
			if (j == (size_t) ft_strlen(little))
				return ((char *) &big[i - j]);
		}
		j = 0;
		counter++;
		i = counter;
	}
	return (NULL);
}
