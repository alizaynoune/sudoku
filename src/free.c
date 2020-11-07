#include "sudoku.h"

void		ft_free_lines(t_lines *l)
{
	t_lines		*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		(tmp->line) ? ft_memdel((void *)&tmp->line) : 0;
		ft_memdel((void *)&tmp);
	}
}

void	ft_free_tables(int **t, int **c)
{
	int	i;

	i = 0;
	while (t && i < 9)
	{
		(t[i]) ? ft_memdel((void *)&t[i]) : 0;
		i++;
	}
	(t) ? ft_memdel((void *)&t) : 0;
    if (c)
        ft_free_tables(c, NULL);
}
