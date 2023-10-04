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

static	size_t 	n_hexlen(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
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

static int	print_char(char c, t_specs *specs)
{
	int	i;

	i = 0;
	if (specs->justifyleft)
		i += n_putchar(&c);
	else
	{
		i += print_padwidth(specs, 1);
		i += n_putchar(&c);
	}
	return (i);
}

static int	print_num(int n, t_specs *specs)
{
	int		count;
	long	nl;
	char 	*str;

	nl = n;
	count = 0;
	if (nl < 0)
	{
		if(!specs->zeroes)
			specs->width--;
		nl = -n;
	}
	if (!n && !specs->precision)
	{
		count += print_padwidth(specs, 0, 0);
		return (count);
	}
	str = ft_itoa(nl);
	if (!str)
		return (0);
	if (specs->zeroes)
	{
		if (nl < 0)
		{
			count += n_putchar('-');
			specs->fieldwidth--;
		}
		else if (specs->plus)
			count += n_putchar('+');
		else if (specs->space)
		{
			count += n_putchar(' ');
			specs->fieldwidth--;
		}
	}
	//	if (specs->justifyleft )
	//	{
		if (nl < 0)
		{
			if (specs->precision >= 0 || !flags->zeroes)
				count += n_putchar('-');
		}
		else if (!specs->zeroes && specs->plus)
			count += n_putchar('+');
		else if (!specs->zeroes && specs->space)
			count += n_putchar(' ');
		if (specs->precision >= 0)
			count += print_padwidth(specs, n_strlen(str) - 1, 1);
		count += print_str(str);
	//	}
	if (specs->precision >= 0 && specs->precision < n_strlen(str))
		specs->precision = n_strlen(str);
	if (specs->precision >= 0)
	{
		specs->fieldwidth -= specs->precision;
		if (!specs->fieldwidth && n < 0)
			specs->fieldwidth -= 1;
		count += print_padwidth(specs->fieldwidth, 0, 0);
	}
	else
		count += print_padwidth(specs, n_strlen(str), specs->zeroes);
	free(str);
	return (count);
}

static int	print_prefixstr(const char *str, t_specs specs)
{
	int 	i;
	size_t	len;

	i = 0;
	len = n_strlen(str);
	if (specs->precision < 0)
	{
		while (str[i] && i < len)
			n_putchar(&str[i]);
		return (i);
	}
	else
	{
		i += print_padwidth(specs, len, 0);
		while (str[i] && i < specs->precision)
			n_putchar(&str[i]);
		return (i);
	}
}

static int	print_str(const char *str, t_specs *specs)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (specs->precision >= 0 && specs->precision > n_strlen(str))
		specs->precision = n_strlen(str);
	if (specs->justifyleft)
		count += print_prefixstr(str, specs);
	if (specs->precision >= 0)
		count += print_padwidth(specs, specs->precision, 0);
	else
		count += print_padwidth(specs, n_strlen(str), 0);
	if (!specs->justifyleft)
		count += print_prefixstr(str, specs);
	return (count);
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
			flags->zeroes = 1;
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

static int	print_prefixhex(short uppercase)
{
	return ((uppercase && write(1, "0X", 2)) || write(1, "0x", 2));
}

static	int	print_hex_subroutine(cont char *str, int n, short uppercase, t_specs *specs)
{
	int subcount;
	int	i;

	subcount = 0;
	if (n && specs->hash && !specs->zeroes)
		subcount += print_prefixhex(uppercase);
	if (specs->precision >= 0)
		subcount += print_padwidth(specs->precision -1, n_strlen(str) - 1, 1);
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (subcount + i);
}

static	int	print_hex(unsigned int n, short uppercase, t_specs *specs)
{
	char 	*str;
	int 	count;

	count = 0;
	if (specs->precision == 0 && n == 0)
		return (print_padwidth(specs->fieldwidth, 0, 0));
	str = ft_xtoa(n, uppercase);
	if (!str)
		return (0);
	if (n && specs->hash && specs->zeroes)
		count += print_prefixhex(uppercase);
	if (specs->justifyleft)
		count +=  print_hex_subroutine(str, n, uppercase, specs);
	if (specs->precision >= 0 && specs->precision < n_strlen(str))
		specs->precision = n_strlen(str);
	if (specs->precision >= 0)
		count += print_padwidth(specs->fieldwidth - specs->precision, 0, 0);
	else
		count += print_padwidth(specs->fieldwidth, n_strlen(str) + specs->hash * 2, specs->zeroes);
	if (!specs->justifyleft)
		count += print_hex_subroutine(str, n, uppercase, specs);
	free(str);
	return (count);
}

static	int	print_unsigned_subroutine(const char *str, t_specs *specs)
{
	int	subcount;
	int	i;

	subcount = 0;
	if (specs->precision >= 0)
		subcount += print_padwidth(specs->precision - 1, n_strlen(str) - 1, 1);
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (subcount + i);
}

static	int	print_unsigned(unsigned int n, t_specs *specs)
{
	int count;
	char *str;

	count = 0;
	if (!n && !specs->precision)
		return (print_padwidth(specs->fieldwidth, 0, 0));
	str = ft_utoa(n);
	if (!str)
		return (0);
	if (specs->justifyleft)
		count += print_unsigned_subroutine(str, specs);
	if (specs->precision >= 0 && specs->precision < n_strlen(str))
		specs->precision = n_strlen(str);
	if (specs->precision >= 0)
		count += print_padwidth(specs->fieldwidth - specs->precision, 0, 0);
	else
		count += print_padwidth(specs->fieldwidth, n_strlen(str), specs->zeroes);
	if (!specs->justifyleft)
		count += print_unsigned_subroutine(str, specs);
	free(str);
	return (count);
}

static void	print_xtoa(unsigned long int n)
{
	if (n > 15)
	{
		print_xtoa(n / 16);
		print_xtoa(n % 16);
	}
	else if (n < 10)
		n_putchar(n + '0');
	else if (n > 9)
		n_putchar((n - 10) + 'a');
}

static	int	print_ptr_subroutine(unsigned long int	ptr)
{
	int	subcount;

	subcount = write(1, "0x", 2);
	print_xtoa(ptr);
	subcount = n_hexlen(ptr);
	return (subcount);
}

static	int	print_ptr(unsigned long int ptr, t_specs *specs)
{
	int	count;

	count = 0;
	if (!ptr)
		return (count);
	specs->fieldwidth -= 2;
	if (specs->justifyleft)
		count += print_ptr_subroutine(ptr);
	count += print_padwidth(specs->fieldwidth, n_hexlen(ptr), 0);
	if (!specs->justifyleft)
		count += print_ptr_subroutine(ptr);
	return (count);		
}

static	int	print_menu(const char fs, va_list ap, t_specs *specs)
{
	int count;

	count = 0;
	if (fs == '%')
		count += print_char('%', specs);
	else if (fs == 'd' || fs == 'i')
		count += print_num(va_args(ap, int), specs);
	else if (fs == 'c')
		count += print_char(va_arg(ap, int), specs);
	else if (fs == 's')
		count += print_str(va_arg(ap, const char *), specs);
	else if (fs == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0, specs);
	else if (fs == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1, specs);
	else if (fs == 'u')
		count += print_unsigned(va_arg(ap, unsigned int), specs);
	else if (fs == 'p')
		count += print_ptr((unsigned long int)va_arg(args, void *), specs);	
	return (count);
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
		count += write(1, &(format[i]), 1);
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