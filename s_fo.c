/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 01:21:45 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/14 02:25:21 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

char	*s_fo4(va_list *av, t_form *f, t_fo *tab)
{
	if (gn_fo(f, tab) == 36)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 16, 'A'));
	if (gn_fo(f, tab) == 37)
		return (ft_utoa(va_arg(*av, t_ull), 16, 'A'));
	if (gn_fo(f, tab) == 38)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A'));
	if (gn_fo(f, tab) == 39)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A'));
	if (gn_fo(f, tab) == 40)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 16, 'A'));
	if (gn_fo(f, tab) == 41)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 16, 'A'));
	if (gn_fo(f, tab) == 45)
		return (ft_utoa((t_ull)va_arg(*av, void *), 16, 'a'));
	if (gn_fo(f, tab) == 46)
		return (ctos(va_arg(*av, int)));
	if (gn_fo(f, tab) == 47 || gn_fo(f, tab) == 48)
		return (ctos(va_arg(*av, wint_t)));
	if (gn_fo(f, tab) == 49)
		return (ft_strdup(va_arg(*av, char *)));
/*	if (gn_fo(f, g_fo) == 50 || gn_fo(f, g_fo) == 51)
		return (sf50(s, va_arg(*av, wchar_t *)));*/
	if (gn_fo(f, tab) == 52)
		return (ft_strdup("%"));
	return (NULL);
}

char	*s_fo3(va_list *av, t_form *f, t_fo *tab)
{
	if (gn_fo(f, tab) == 24)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, 0));
	if (gn_fo(f, tab) == 25)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, 0));
	if (gn_fo(f, tab) == 26)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 10, 0));
	if (gn_fo(f, tab) == 27)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 10, 0));
	if (gn_fo(f, tab) == 28)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a'));
	if (gn_fo(f, tab) == 29)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 16, 'a'));
	if (gn_fo(f, tab) == 30)
		return (ft_utoa(va_arg(*av, t_ull), 16, 'a'));
	if (gn_fo(f, tab) == 31)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a'));
	if (gn_fo(f, tab) == 32)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'a'));
	if (gn_fo(f, tab) == 33)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 16, 'a'));
	if (gn_fo(f, tab) == 34)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 16, 'a'));
	if (gn_fo(f, tab) == 35)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 16, 'A'));
	return (NULL);
}

char	*s_fo2(va_list *av, t_form *f, t_fo *tab)
{
	if (gn_fo(f, tab) == 14)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0));
	if (gn_fo(f, tab) == 15 || gn_fo(f, tab) == 43)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 8, 0));
	if (gn_fo(f, tab) == 16)
		return (ft_utoa(va_arg(*av, t_ull), 8, 0));
	if (gn_fo(f, tab) == 17)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0));
	if (gn_fo(f, tab) == 18)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 8, 0));
	if (gn_fo(f, tab) == 19)
		return (ft_utoa((t_ull)va_arg(*av, uintmax_t), 8, 0));
	if (gn_fo(f, tab) == 20)
		return (ft_utoa((t_ull)va_arg(*av, size_t), 8, 0));
	if (gn_fo(f, tab) == 21)
		return (ft_utoa((t_ull)va_arg(*av, unsigned int), 10, 0));
	if (gn_fo(f, tab) == 22 || gn_fo(f, tab) == 44)
		return (ft_utoa((t_ull)va_arg(*av, unsigned long), 10, 0));
	if (gn_fo(f, tab) == 23)
		return (ft_utoa(va_arg(*av, t_ull), 10, 0));
	return (NULL);
}

char	*s_fo1(va_list *av, t_form *f, t_fo *tab)
{
	if (gn_fo(f, tab) == 0 || gn_fo(f, tab) == 7)
		return (ft_lltoa((long long)va_arg(*av, int)));
	if (gn_fo(f, tab) == 1 || gn_fo(f, tab) == 42 || gn_fo(f, tab) == 8)
		return (ft_lltoa((long long)va_arg(*av, long)));
	if (gn_fo(f, tab) == 2 || gn_fo(f, tab) == 9)
		return (ft_lltoa(va_arg(*av, long long)));
	if (gn_fo(f, tab) == 3 || gn_fo(f, tab) == 10)
		return (ft_lltoa((long long)va_arg(*av, int)));
	if (gn_fo(f, tab) == 4 || gn_fo(f, tab) == 11)
		return (ft_lltoa((long long)va_arg(*av, int)));
	if (gn_fo(f, tab) == 5 || gn_fo(f, tab) == 12)
		return (ft_lltoa((long long)va_arg(*av, intmax_t)));
	if (gn_fo(f, tab) == 6 || gn_fo(f, tab) == 13)
		return (ft_lltoa((long long)va_arg(*av, size_t)));
	return (NULL);
}
