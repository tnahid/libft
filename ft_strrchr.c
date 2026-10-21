/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:43 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:44 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = NULL;
	while (str[i])
	{
		if (str[i] == c)
			p = (char *)&str[i];
		i++;
	}
	if (str[i] == c)
		p = (char *)&str[i];
	return (p);
}
