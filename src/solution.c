#include "sudoku.h"

void	ft_convert_line(char *l, int **s1, int **s2)
{
	int	i;
	int	j;
	int	*line[2];

	line[0] = (int *)malloc(sizeof(int) * 8);
	line[1] = (int *)malloc(sizeof(int) * 8);
	i = 0;
	j = 0;
	while (l[i])
	{
		if (i % 2 == 0)
		{
			line[0][j] = ft_atoi(&l[i]);
			line[1][j] = line[0][j];
			j++;
		}
		i++;
	}
	*s1 = line[0];
	*s2 = line[1];
}

int	check_i(int **tab, int j, int nb)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (tab[i][j] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_j(int **tab, int i, int nb)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (tab[i][j] == nb)
			return (0);
		j++;
	}
	return(1);
}

int	get_coor(int coor)
{
	if (coor < 3)
		return (0);
	if (coor > 2 && coor < 6)
		return (3);
	return (6);
}

int	check_sq(int **tab, int i, int j, int nb)
{
	int	k;
	int	l;

	i = get_coor(i);
	j = get_coor(j);
	k = 0;
	while (k < 3)
	{
		l = 0;
		while (l < 3)
		{
			if (tab[i + k][j + l] == nb)
				return (0);
			l++;
		}
		k++;
	}
	return (1);
}

int	check_is_posseble(int **tab, int i, int j, int nb)
{
	if (check_i(tab, j, nb) == 0)
		return (0);
	if (check_j(tab, i, nb) == 0)
		return (0);
	if (check_sq(tab, i, j, nb) == 0)
		return (0);
	return (1);
}

int	chang_num(int **tab, int i, int j)
{
	int	nb;

	nb = tab[i][j] + 1;
	while (nb < 10)
	{
		if (check_is_posseble(tab, i, j, nb))
			break ;
		nb++;
	}
	return (nb % 10);
}

int	get_num(int **tab, int i, int j)
{
	int	nb;

	nb = chang_num(tab, i, j);
	if (j == 0 && nb == 0)
		return (-1);
	return (nb);
}

void	ft_modef(int **tab, int **cp, int slp)
{
	int	i;
	int	j;
	int	nb;
	int	mi;
	int	mj;

	i = 0;
	j = 0;
	mj = 1;
	while (i < 9 && i > -1)
	{
		while (j < 9 && j > -1)
		{
			if (cp[i][j] == 0)
			{
				nb = get_num(tab, i, j);
				if (nb > 0)
					tab[i][j] = nb;
				mj = nb <= 0 ? -1 : 1;
				nb <= 0 ? tab[i][j] = 0 : 0;
			}
			if (slp > 0 && cp[i][j] == 0)
			{
				system("clear");
				ft_print(tab, cp, i, j);
				usleep(slp);
			}
			j += mj;
		}
		mi = j < 0 ? -1 : 1;
		j = mi == -1 ? 8 : 0;
		i += mi;
	}
	system("clear");
	if (i < 0)
	{
		ft_printf("Error no solution\n");
		ft_printf("%s         (-_-)%s\n", RED, DEF);
	}
	else
		ft_printf("%s          WOW   (^_^)    WOW%s\n", GREEN, DEF);
	ft_print(tab, cp, i, j);
}


void	ft_solution(t_data *d)
{
	int	i;
	t_lines	*l;

	i = 0;
	l = d->l;
	d->tab = (int **)malloc(sizeof(int *) * 8);
	d->cp = (int **)malloc(sizeof(int *) * 8);
	while (l)
	{
		ft_convert_line(l->line, &d->tab[i], &d->cp[i]);
		i++;
		l = l->next;
	}
	ft_modef(d->tab, d->cp, d->slp);
	d->l = NULL;
}
