/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:50 by nzachari          #+#    #+#             */
/*   Updated: 2023/09/25 18:02:00 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

static void	ft_putchar(const char *c)
{
	write(1, c, 1);
}

static void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(&str[i]);
		i++;
	}
}

int	main(void)
{
	char test[] = "where is the love";
	int	i = -1;
	ft_putstr(test);
}
