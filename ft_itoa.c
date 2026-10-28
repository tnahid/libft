/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnahid <tnahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 12:14:41 by tnahid            #+#    #+#             */
/*   Updated: 2026/10/16 12:20:25 by tnahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_len(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fill_str(char *str, long n)
{
	size_t	i;
	long	pwr;

	i = 0;
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	pwr = 1;
	while (n / pwr >= 10)
		pwr *= 10;
	while (pwr > 0)
	{
		str[i] = n / pwr + '0';
		n %= pwr;
		pwr /= 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	nb;

	nb = n;
	len = calc_len(nb);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	fill_str(str, nb);
	return (str);
}
