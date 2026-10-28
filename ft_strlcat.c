/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:18 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:19 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	s_len;
	size_t	d_len;

	i = 0;
	n = 0;
	d_len = 0;
	s_len = ft_strlen(src);
	while (d_len < size && dst[d_len])
		d_len++;
	if (d_len == size)
		return (s_len + d_len);
	n = size - d_len - 1;
	while (i < n && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
