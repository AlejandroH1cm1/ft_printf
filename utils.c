/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 05:37:34 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/14 00:50:00 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

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
	while (i < 53 && ft_strcmp(tab[i].fmt, f->lent) != 0)
		i++;
	return (i);
}
