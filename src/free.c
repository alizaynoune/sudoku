#include "sudoku.h"

void		ft_free_lines(t_lines *l)
{
	t_lines		*tmp;

	tmp = l;
	while (tmp)
	{
		l = tmp;
		tmp = tmp->next;
		free(l->line);
		free(l);
	}
}

void	ft_free_tables(int **t, int **c)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		free(t[i]);
		free(c[i]);
		i++;
	}
	free(t);
	free(c);
}
