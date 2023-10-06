/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:27 by nzachari          #+#    #+#             */
/*   Updated: 2023/10/05 14:56:54 by nzachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_specs
{
	short	specifier;
	short	extraparams;
	short	justifyleft;
	short	zeroes;
	short	fieldwidth;
	short	precision;
	short	hash;
	short	space;
	short	plus;
}		t_specs = {0, 0, 0, 0, 0, 0, 0, 0, 0};

char	*ft_itoa(int n);
char	*ft_xtoa(unsigned long ul, short uppercase);

#endif
