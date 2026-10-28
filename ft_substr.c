/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:52 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:53 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
	{
		sub = ft_strdup("");
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, str + start, len + 1);
	return (sub);
}
