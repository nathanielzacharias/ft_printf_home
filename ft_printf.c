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

static int	n_isdigit(char c)
{
	return (c >= '0' && c <= '9')
}

static int	validconversion(char c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*' || c == '#' || 
		c == ' ' || c == '+');
}

static int	validspecifier()
{
	return ();
}

static void	set_precision(va_list ap, t_specs *specs, const char *s, int i)
{}

static void	set_width(va_list ap, t_specs *specs)
{}

static int	set_specs(const char *s, int i, va_list ap, t_specs *specs)
{
	while (s[++i] && (validconversion(s[i]) || validspecifier(s[i]) || 
		n_isdigit(s[i])))
	{
		if (s[i] == '+')
			specs->plus = 1;
		if (s[i] == '#')
			specs->hash = 1;
		if (s[i] == ' ')
			specs->space = 1;
		if (s[i] == '.')
			set_precision(ap, specs, s, i);
		if (s[i] == '*')
			set_width(ap, specs);
		if (s[i] == '0' && !(specs->left) && !(flags->width))
			flags->zero = 1;
		if (s[i] == '-')
		{
			specs->justifyleft = 1;
			specs->zeroes = 0; //test this, can this be removed?
		}
		if (n_isdigit(s[i]) && specs->extraparams == 1)
			specs->fieldwidth = 0;
		else if (n_isdigit(s[i]))
			specs.fieldwidth = (specs.fieldwidth * 10) + (c - '0');
		if (validconversion(str[i]))
		{
			specs->specifier = str[i];
			break ;
		}
	}
	return (i);
}


int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;
	t_specs	*specs;

	if (!(*format) || !format)
		return (0);
	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i] && format[i] == '%' && format[i + 1])
	{
		i = set_specs(format, i, ap, specs);
		if (specs->specifier && validconversion(format[i]))
			count += print_menu(format[i], ap, specs);
		count += print_char(format[i], specs);
	}
	while (format[i])
		count += write(1, &(format[i], 1);
	va_end(ap); //is this optional?
	return (count);
}


/*
int	main(void)
{
	char test[] = "where is the love";
	int	i = -1;
}
*/