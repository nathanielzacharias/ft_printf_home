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

static size_t	hexlen(unsigned long long ull)
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

static void	ft_xtoa_subroutine(int len, unsigned long long ull, char *str)
{
	int	rem;

	str[len] = 0;
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
}

char	*ft_xtoa(unsigned long ull, short uppercase)
{
	char	*str;
	int		i;
	int		len;

	len = hexlen(ull);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_xtoa_subroutine(len, ull, str);
	i = -1;
	while (uppercase && str[++i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
	}
	return (str);
}
