#include "sudoku.h"

void		error_malloc(t_all *d, char *l)
{
	(l) ? ft_strdel(&l) : 0;
	(d->l) ? ft_free_lines(d->l) : 0;
    ft_free_tables(d->tab, d->cp);
    ft_memdel((void *)&d);
	ft_dprintf(2, "%s\n", strerror(errno));
	exit(1);
}
