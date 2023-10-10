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
#include <stdio.h>
#include "ft_printf.h"




int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			count += print_menu(format[++i], &ap);
		count += write(1, &(format[i]), 1);
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	char test[] = "where is the love";
	int	i = -1;

	printf("printf return: %d\n", printf("printf string: %c\n", test[0]));
	int resultof_ft_printf = ft_printf("%s\n", test);
	printf("ft_ntf return: %d\n", resultof_ft_printf);
	// ft_printf("%s\n", test);
}
