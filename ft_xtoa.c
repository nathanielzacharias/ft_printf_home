/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:22:17 by nzachari          #+#    #+#             */
/*   Updated: 2023/10/06 14:55:41 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	hexlen (unsigned long long ull)
{
	size_t	len;

	if (ull == 0)
		return (1);
	len = 0;
	while (ull > 0)
	{
		len++;
		ull /= 16;
	}
	return (len);
}

char	*ft_xtoa(unsigned long long ull, short uppercase)
{
	char		*str;
	int			i;
	int			rem;
	size_t		len;

	len = hexlen(ull);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (--len >= 0)
	{
		rem = ull % 16;
		if (rem < 10)
			str[len] = rem + '0';
		else if (rem >= 10)
			str[len] = (rem - 10) + 'a';
		ull = ull / 16;
		if (len == 0)
			break ;
	}
	i = -1;
	while (uppercase && str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		else 
			continue ;
	}
	return (str);
}
