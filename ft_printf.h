/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:43:39 by mgoliath          #+#    #+#             */
/*   Updated: 2021/12/12 13:15:50 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);
char	*ft_itoabase(unsigned long n, char *base);
int		ft_optionshandler(int *chcount, char opt, va_list list);
int		ft_putstr(char *s);

#endif
