/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:40:19 by mgoliath          #+#    #+#             */
/*   Updated: 2021/11/20 19:40:25 by mgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nlen(unsigned long n, unsigned long nb)
{
	int		nlen;

	nlen = 1;
	while (n >= nb)
	{
		n /= nb;
		nlen++;
	}
	return (nlen);
}

static void	ft_fillstr(char *s, int i, unsigned long n, char *base)
{
	unsigned long	nb;

	nb = (unsigned long)ft_strlen(base);
	while (i > 0)
	{
		s[i - 1] = base[n % nb];
		n /= nb;
		i--;
	}
}

char	*ft_itoabase(unsigned long n, char *base)
{
	int				nlen;
	unsigned long	nbase;
	char			*s;

	nbase = (int)ft_strlen(base);
	nlen = ft_nlen(n, nbase);
	s = malloc(nlen + 1);
	if (s == NULL)
		return (NULL);
	s[nlen] = '\0';
	ft_fillstr(s, nlen, n, base);
	return (s);
}
