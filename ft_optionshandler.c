/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optionshandler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:42:51 by mgoliath          #+#    #+#             */
/*   Updated: 2021/11/20 19:42:53 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_coptionshandler(char option, va_list list)
{
	if (option == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd(va_arg(list, int), 1);
	return (1);
}

static int	ft_freesmem(char *s)
{
	int	count;

	if (!s)
		return (-1);
	count = ft_putstr(s);
	free(s);
	return (count);
}

static int	ft_poptionhandler(va_list list)
{
	char	*s;

	s = ft_itoabase(va_arg(list, unsigned long), "0123456789abcdef");
	if (s)
		ft_putstr("0x");
	else
		return (-1);
	return (ft_freesmem(s) + 2);
}

static int	ft_othoptionshandler(char option, va_list list)
{
	char	*s;

	s = NULL;
	if (option == 's')
	{
		s = va_arg(list, char *);
		if (!s)
			return (ft_putstr("(null)"));
		return (ft_putstr(s));
	}
	else if (option == 'd' || option == 'i')
		s = ft_itoa(va_arg(list, int));
	else if (option == 'u')
		s = ft_itoabase(va_arg(list, unsigned int ), "0123456789");
	else if (option == 'x')
		s = ft_itoabase(va_arg(list, unsigned int ), "0123456789abcdef");
	else if (option == 'X')
		s = ft_itoabase(va_arg(list, unsigned int ), "0123456789ABCDEF");
	else if (option == 'p')
		return (ft_poptionhandler(list));
	return (ft_freesmem(s));
}

int	ft_optionshandler(int *chcount, char opt, va_list list)
{
	int	count;

	if (opt == 'c' || opt == '%')
		count = ft_coptionshandler(opt, list);
	else
		count = ft_othoptionshandler(opt, list);
	if (count < 0)
		return (-1);
	*chcount = *chcount + count;
	return (count);
}
