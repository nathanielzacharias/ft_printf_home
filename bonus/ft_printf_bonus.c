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
#include "ft_printf_bonus.h"

static	int	print_menu(const char *fs, va_list *ap)
{
	int		count;
	char	tmp;

	count = 0;
	if (*fs == 'c')
	{
		tmp = (char)va_arg(*ap, int);
		count += write(1, &tmp, 1);
	}

	

	else if (*fs == 's')
		count += ft_print_str(va_arg(*ap, const char *));
	else if (*fs == 'd' || *fs == 'i')
		count += ft_print_num(va_arg(*ap, int));
	else if (*fs == 'x')
		count += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 0, 0);
	else if (*fs == 'X')
		count += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 1, 0);
	else if (*fs == 'p')
		count += ft_print_hex((unsigned long)(va_arg(*ap, void *)), 0, 1);
	else if (*fs == 'u')
		count += ft_putul((unsigned long)va_arg(*ap, unsigned int));
	else if (*fs == '%')
		count += write(1, "%", 1);
	return (count);
}

static int print_flags_menu(const char *fs, va_list *ap)
{
	int count;
	char tmp;

	count = 0;

	if (*fs == '#' && fs[1] == 'x')
		count += ft_print_hex((unsigned long)(va_arg(*ap, void *)), 0, 1);
	else if (*fs == '#' && fs[1] == 'X')
		count += ft_print_hex((unsigned long)va_arg(*ap, unsigned int), 1, 1);

	return (count);
}

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
		if (format[i] == '%' && format[i + 1] != '#' && format[i + 1])
			count += print_menu(&format[++i], &ap);
		else if (format[i] == '%' && format[i + 1])
		{
			count += print_flags_menu(&format[++i], &ap);
			count--;
			i++;
		}
		else
			count += write(1, &(format[i]), 1);
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	char test[] = "where is the love";

	// printf("   printf default behaviour is this\n");
	// fflush(stdout);
	// ft_printf("ft_printf default behaviour is this\n");

	// printf("   printf c is: %c\n", test[2]);
	// fflush(stdout);
	// ft_printf("ft_printf c is: %c\n", test[2]);

	// printf("   printf s is: %s\n", test);
	// fflush(stdout);
	// ft_printf("ft_printf s is: %s\n", test);

	// printf("   printf d is: %d\n", 13);
	// fflush(stdout);
	// ft_printf("ft_printf d is: %d\n", 13);	

	// printf("   printf i is: %i\n", 17);
	// fflush(stdout);
	// ft_printf("ft_printf i is: %i\n", 17);

	printf("   printf x is: %x\n", 42);
	fflush(stdout);
	ft_printf("ft_printf x is: %x\n", 42);

	printf("   printf X is: %#x\n", 42);  //here
	fflush(stdout);
	ft_printf("ft_printf X is: %#x\n", 42);

	// printf("   printf X is: %X\n", 42);
	// fflush(stdout);
	// ft_printf("ft_printf X is: %X\n", 42);

	// printf("   printf X is: %#X\n", 42);
	// fflush(stdout);
	// ft_printf("ft_printf X is: %#X\n", 42);

	printf("   printf p is: %p\n", test);
	fflush(stdout);
	ft_printf("ft_printf p is: %p\n", test);

	// printf("   printf u is: %u\n", -100);
	// fflush(stdout);
	// ft_printf("ft_printf u is: %u\n", -100);

	// printf("   printf percent is: %%\n");
	// fflush(stdout);
	// ft_printf("ft_printf percent is: %%\n");

	// printf("%x\n", 9223372036854775807LL);
	// ft_printf("%x\n", 9223372036854775807LL);

	// printf("%x\n", 9223372036854775807);
	// ft_printf("%x\n", 9223372036854775807);

	// printf("%x\n", -9223372036854775808);
	// ft_printf("%x\n", -9223372036854775808);
}

