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

static size_t	hexlen (long int nl)
{
	size_t	len;

	if (nl == 0)
		return (1);
	len = 0;
	while (nl > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char	*ft_xtoa(unsigned long ul, short uppercase)
{
	char		*str;
	int			i;
	int			rem;
	size_t		len;

	len = hexlen(ul);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (--len >= 0)
	{
		rem = ul % 16;
		if (rem < 10)
			str[len] = rem + '0';
		str[len] = (rem - 10) + 'a';
		ul = ul / 16;
	}
	i = -1;
	while (uppercase && str[++i] && str[i] >= 'a' && str[i] <= 'f')
		str[i] -= 32;
	return (str);
}
