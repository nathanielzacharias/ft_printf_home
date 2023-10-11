/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:28:19 by nzachari          #+#    #+#             */
/*   Updated: 2023/10/11 17:28:23 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putul(unsigned long n)
{
	int		count;
	char	c;

	count = 0;
	if (n == 0)
		count += write (1, "0", 1);
	else if (n > 0 && n < 10)
	{
		c = (char) n + '0';
		count += write (1, &c, 1);
	}
	else if (n >= 10)
	{
		count += ft_putul(n / 10);
		count += ft_putul(n % 10);
	}
	return (count);
}

int	ft_print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		count += write(1, "(null)", 1);
	count += write(1, str, ft_strlen(str));
	return (count);
}

int	ft_print_num(int n)
{
	int		count;
	long	nl;

	count = 0;
	nl = (long) n;
	if (n < 0)
	{
		nl *= -1;
		count += write(1, "-", 1);
	}
	count += ft_putul(nl);
	return (count);
}

int	ft_print_hex(unsigned long long ull, short uppercase, short is_ptr)
{
	int		count;
	char	*str;

	count = 0;
	if (is_ptr && ull == 0)
		return (write(1, "(nil)", 5));
	str = ft_xtoa(ull, uppercase);
	if (!str)
		return (count);
	if (is_ptr)
		count += write(1, "0x", 2);
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
