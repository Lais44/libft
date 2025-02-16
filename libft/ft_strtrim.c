/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleal-go <lleal-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:24:15 by lleal-go          #+#    #+#             */
/*   Updated: 2025/01/24 14:01:03 by lleal-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_start;
	size_t	s1_size;
	size_t	s1_end;

	s1_start = 0;
	s1_size = ft_strlen(s1);
	s1_end = s1_size - 1;
	while (s1[s1_start] && ft_strchr(set, s1[s1_start]))
		s1_start++;
	while (s1[s1_end] && s1_end > s1_start && ft_strchr(set, s1[s1_end]))
		s1_end--;
	return (ft_substr(s1, s1_start, s1_end - s1_start + 1));
}
