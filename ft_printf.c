/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:50 by nzachari          #+#    #+#             */
/*   Updated: 2023/09/25 18:23:25 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	n_putchar(const char *c)
{
	return(write(1, c, 1));
}

static size_t	n_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	if (!(*format) || !format)
		return (0);
	i = 0;
	va_start(ap, format);
	//parse
	va_end(ap);
	return (i);
}


/*
int	main(void)
{
	char test[] = "where is the love";
	int	i = -1;
}
*/