/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 01:45:52 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/13 23:28:53 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

t_form			*m_fo(void)
{
	t_form	*f;

	f = (t_form *)malloc(sizeof(t_form));
	f->flag = (char *)ft_memalloc(6 * sizeof(char));
	f->lent = (char *)ft_memalloc(4 * sizeof(char));
	f->widt = -1;
	f->prec = -1;
	return (f);
}

void			d_fo(t_form **f, int v)
{
	free((*f)->flag);
	free((*f)->lent);
	free(*f);
	*f = NULL;
	if (v == 0)
		return ;
	*f = m_fo();
}

int				r_fo(t_form *f, char *fo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (fo[i] == ' ' || fo[i] == '+' || fo[i] == '-' || fo[i] == '0' ||
			fo[i] == '#')
		f->flag[j++] = fo[i++];
	f->widt = ft_atoi(&fo[i]);
	while (fo[i] >= '0' && fo[i] <= '9')
		i++;
	if (fo[i] == '.')
		f->prec = ft_atoi(&fo[i + 1]);
	while ((fo[i] >= '0' && fo[i] <= '9') || fo[i] == '.')
		i++;
	j = 0;
	if (fo[i] == '%')
		f->lent[j] = fo[i++];
	while ((fo[i] == 's' || fo[i] == 'd' || fo[i] == 'D' || fo[i] == 'p' ||
	fo[i] == 'S' || fo[i] == 'i' || fo[i] == 'o' || fo[i] == 'O' ||
	fo[i] == 'u' || fo[i] == 'U' || fo[i] == 'x' || fo[i] == 'X' ||
	fo[i] == 'c' || fo[i] == 'C' || fo[i] == 'h' || fo[i] == 'l' ||
	fo[i] == 'j' || fo[i] == 'z') && fo[i] != '%')
		f->lent[j++] = fo[i++];
	return (i);
}

static int		inner(va_list *av, char *form)
{
	int		i;
	int		j;
	int		k;
	t_form	*f;

	i = -1;
	j = 0;
	f = m_fo();
	while (form[++i] != '\0')
		if (form[i] == '%')
		{
			k = r_fo(f, &form[i + 1]);
			i = i + k;
			j = j + p_fo(av, f);
			d_fo(&f, 1);
		}
		else
		{
			j++;
			ft_putchar(form[i]);
		}
	d_fo(&f, 0);
	return (j);
}

int				ft_printf(char *form, ...)
{
	va_list	av;
	int		i;

	va_start(av, form);
	if (validate(form) == 1)
		i = inner(&av, form);
	va_end(av);
	i = 0;
	return (i);
}
