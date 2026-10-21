/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:14:12 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:14:13 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	if (nmemb == 0 || size == 0)
	{
		arr = (char *)malloc(1);
		if (arr == NULL)
			return (NULL);
		arr[0] = 0;
		return (arr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	arr = (char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
