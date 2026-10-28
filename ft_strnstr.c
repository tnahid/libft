/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:39 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:40 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!to_find[0])
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
