/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:04:01 by nzachari          #+#    #+#             */
/*   Updated: 2023/10/05 14:55:05 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return ((int)len);
}

static char	*convert_to_str(char *str, int len, int n)
{
	int		is_negative;
	long	long_n;

	is_negative = 0;
	long_n = n;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (long_n < 0)
	{
		is_negative = 1;
		long_n *= -1;
	}
	str[len] = '\0';
	while (long_n)
	{
		str[--len] = (char)((long_n % 10) + '0');
		long_n /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = convert_to_str(str, len, n);
	return (str);
}
/*
#include <stdio.h>
#include <limits.h>
int main(void)
{
 	printf("result is: %s\n", ft_itoa(INT_MIN));
 	printf("result is: %s\n", ft_itoa(0));
 	return (0);
}
*/
