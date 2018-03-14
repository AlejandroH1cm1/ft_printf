#include "libpf.h"
#include "form.h"

static char	*apply_flags(char **st, t_form *f)
{
	int i;

	i = gn_fo(f, g_fo);
	if (fl_exists(f->flag, '#'))
	{
		if ((i >= 14 && i <= 20) || i == 43)
			strcomb(st, "0", 1);
		if (i >= 28 && i <= 34)
			strcomb(st, "0x", 1);
		if (i >= 35 && i <= 41)
			strcomb(st, "0X", 1);
	}
	return (*st);
}

static char	*s_fo(va_list *av, t_form *f)
{
	char *st;
	char *tmp;

	st = s_fo1(av, f, g_fo);
	if (st == NULL)
		st = s_fo2(av, f, g_fo);
	if (st == NULL)
		st = s_fo3(av, f, g_fo);
	if (st == NULL)
		st = s_fo4(av, f, g_fo);
	if (!st && (gn_fo(f, g_fo) == 49 || gn_fo(f, g_fo) == 50 ||
				gn_fo(f, g_fo) == 51))
		st = ft_strdup("(null)");
	printf("[%d]",gn_fo(f, g_fo));
	if (gn_fo(f, g_fo) == 45)
	{
		tmp = ft_strjoin("0x", st);
		free(st);
		st = tmp;
	}
	return (st);
}

int			p_fo(va_list *av, t_form *f)
{
	char	*st;

	st = s_fo(av, f);
	st = apply_flags(&st, f);
	ft_putendl(st);
	return (ft_strlen(st));
}

int			validate(char *form)
{
	int		i;
	t_form	*f;
	int		k;

	i = -1;
	f = m_fo();
	while (form[++i] != '\0')
		if (form[i] == '%')
		{
			k = r_fo(f, &form[i + 1]);
			i = i + k;
			if (gn_fo(f, g_fo) == 53)
			{
				d_fo(&f,0);
				return (0);
			}
			d_fo(&f, 1);
		}
	d_fo(&f,0);
	return (1);
}
