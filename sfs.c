/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfs1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 06:14:15 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/14 00:42:07 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

static char	*aux2(long long n)
{
	char	*r;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	r = (char *)malloc((i + 1 + neg) * sizeof(char));
	if (r != NULL)
	{
		if (neg == 1)
			r[i] = '-';
		r[i + neg] = '\0';
	}
	return (r);
}

char		*ft_lltoa(long long n)
{
	int		i;
	char	*r;

	r = aux2(n);
	i = 0;
	if (r != NULL)
	{
		if (n == LL_MIN)
		{
			ft_strcpy(r, LL_MINS);
			return (r);
		}
		if (n == 0)
			r[0] = '0';
		if (n < 0)
			n = n * -1;
		while (n != 0)
		{
			r[i++] = n % 10 + '0';
			n = n / 10;
		}
		ft_strrev(r);
	}
	return (r);
}

static char	*aux(t_ull n, unsigned long long b)
{
	char	*r;
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / b;
		i++;
	}
	r = (char *)malloc((i + 1) * sizeof(char));
	return (r);
}

char		*ft_utoa(t_ull n, t_ull b, char x)
{
	int		i;
	char	*r;

	r = aux(n, b);
	i = 0;
	if (r != NULL)
	{
		if (n == 0)
			r[0] = '0';
		while (n != 0)
		{
			r[i++] = n % b + '0';
			if (r[i - 1] > '9')
				r[i - 1] = r[i - 1] - '0' + x - 10;
			n = n / b;
		}
		ft_strrev(r);
	}
	return (r);
}

char		*ctos(char c)
{
	char *st;

	st = (char *)malloc(2 * sizeof(char));
	st[0] = c;
	st[1] = '\0';
	return (st);
}
