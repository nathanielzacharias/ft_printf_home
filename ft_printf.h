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

char	*ft_xtoa(unsigned long ul, short uppercase);
size_t	ft_strlen(const char *str);
int		ft_putul(unsigned long n);
int		ft_print_str(const char *str);
int		ft_print_num(int n);
int		ft_print_hex(unsigned long long ull, short uppercase, short is_ptr);

#endif
