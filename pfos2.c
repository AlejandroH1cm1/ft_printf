/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfos2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:34:30 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/21 07:03:59 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

int	pf_foa1(t_form *f, wint_t c)
{
	int i;

	i = 1;
	ft_putwchar(c);
	while (i < f->widt)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	pf_foa2(t_form *f, wint_t c)
{
	int		i;
	char	c2;

	i = 1;
	c2 = ' ';
	if (fl_exists(f->flag, '0'))
		c2 = '0';
	while (i < f->widt)
	{
		ft_putchar(c2);
		i++;
	}
	ft_putwchar(c);
	return (i);
}

int	pf_fob1(t_form *f, wchar_t *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	if (f->prec < j && f->prec >= 0)
		j = f->prec;
	while (i < j && s[i])
		i++;
	ft_putwstr(s, i);
	while (i < f->widt)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	pf_fob2(t_form *f, wchar_t *s)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 32 + fl_exists(f->flag, '0') * 16;
	while (s[j] != '\0')
		j++;
	if (f->prec < j && f->prec >= 0)
		j = f->prec;
	while (i < f->widt - j)
	{
		ft_putchar(c);
		i++;
	}
	c = i + j;
	while (i < c && s[i - (c - j)])
		i++;
	ft_putwstr(s, j);
	return (i);
}
