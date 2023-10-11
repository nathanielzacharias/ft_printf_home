/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:31:56 by nzachari          #+#    #+#             */
/*   Updated: 2023/09/06 12:26:45 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str = "wjere?";
	printf("str should be 6 is actually: %i \n", ft_strlen(str));
}
*/
