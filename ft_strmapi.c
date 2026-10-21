/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:16:31 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:16:32 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*n_str;

	i = 0;
	n_str = (char *)malloc(ft_strlen(str) + 1);
	if (n_str == NULL)
		return (NULL);
	while (str[i])
	{
		n_str[i] = f(i, str[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
