/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 05:36:41 by aherrera          #+#    #+#             */
/*   Updated: 2018/03/14 00:50:05 by aherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H
# include <stdio.h>
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdlib.h>
# define LL_MIN -9223372036854775807
# define LL_MINS "-9223372036854775807"

typedef unsigned long long t_ull;

typedef struct	s_fo
{
	char		*fmt;
}				t_fo;

typedef struct	s_form
{
	char		*flag;
	int			widt;
	int			prec;
	char		*lent;
}				t_form;

int				ft_printf(char *form, ...);
int				validate(char *form);
int				p_fo(va_list *av, t_form *f);
int				gn_fo(t_form *f, t_fo *tab);
int				fl_exists(char *fl, char f);
void			strcomb(char **st, char *s, int order);
char			*ft_utoa(t_ull n, t_ull b, char x);
char			*ft_lltoa(long long n);
char			*ctos(char c);
t_form			*m_fo(void);
void			d_fo(t_form **f, int v);
int				r_fo(t_form *f, char *fo);
char			*s_fo1(va_list *av, t_form *f, t_fo *tab);
char			*s_fo2(va_list *av, t_form *f, t_fo *tab);
char			*s_fo3(va_list *av, t_form *f, t_fo *tab);
char			*s_fo4(va_list *av, t_form *f, t_fo *tab);

#endif
