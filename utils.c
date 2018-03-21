/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 05:37:34 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/21 06:52:27 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"
#include "libft.h"

void	strcomb(char **st, char *s, int order)
{
	char *tmp;

	if (order == 0)
		tmp = ft_strjoin(*st, s);
	else
		tmp = ft_strjoin(s, *st);
	free(*st);
	*st = tmp;
}

int		fl_exists(char *fl, char f)
{
	int i;

	i = 0;
	while (fl[i] != '\0')
	{
		if (fl[i] == f)
			return (1);
		i++;
	}
	return (0);
}

int		gn_fo(t_form *f, t_fo *tab)
{
	int i;

	i = 0;
	while (i < 54 && ft_strcmp(tab[i].fmt, f->lent) != 0)
		i++;
	if (f->lent[ft_strlen(f->lent) - 1] == 'p')
		i = 45;
	if (f->lent[ft_strlen(f->lent) - 1] == 'O')
		i = 16;
	if (f->lent[ft_strlen(f->lent) - 1] == 'D')
		i = 2;
	if (f->lent[ft_strlen(f->lent) - 1] == 'U')
		i = 23;
	return (i);
}

int		is_ec(char c)
{
	if (c == 's' || c == 'S' || c == 'O' || c == 'o' || c == 'x' || c == 'X' ||
		c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || c == 'C' ||
		c == 'p' || c == '%' || c == 'c')
		return (1);
	return (0);
}

t_ull	change(t_ull n, int len)
{
	unsigned short	s;
	unsigned char	c;
	unsigned long	l;
	unsigned int	i;
	size_t			t;

	t = (size_t)n;
	s = (unsigned short)n;
	c = (unsigned char)n;
	i = (unsigned int)n;
	l = (unsigned long)n;
	if (len == 0)
		return ((t_ull)i);
	if (len == -1)
		return ((t_ull)s);
	if (len == -2)
		return ((t_ull)c);
	if (len == 1)
		return ((t_ull)t);
	if (len == 2)
		return ((t_ull)l);
	return (n);
}
