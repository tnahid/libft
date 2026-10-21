/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:47 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:48 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) - ft_strlen(set);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
		{
			str[j] = s1[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
