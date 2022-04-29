/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:38:53 by mgoliath          #+#    #+#             */
/*   Updated: 2021/11/20 19:39:00 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		chcount;
	va_list	list;

	va_start(list, s);
	chcount = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) && (*(s + 1) == 'c' || *(s + 1) == '%' || \
		*(s + 1) == 's' || *(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == \
		'x' || *(s + 1) == 'X' || *(s + 1) == 'p' || *(s + 1) == 'u'))
		{
			if (ft_optionshandler(&chcount, *(++s), list) < 0)
				return (-1);
		}		
		else if (*s == '%' && !*(s + 1))
			return (-1);
		else
		{
			ft_putchar_fd(*s, 1);
			chcount++;
		}
		s++;
	}
	return (chcount);
}
