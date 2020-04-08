#include "sudoku.h"

void		error_malloc(t_data *d, char *l)
{
	ft_strdel(&l);
	ft_free_lines(d->l);
	ft_printf("Error malloc (-_-)\n");
	exit(1);
}
