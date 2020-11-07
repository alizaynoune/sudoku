#include "sudoku.h" 
int		check_filee(char *f)
{
	char	c;
	int	err;
	int	fd;

	if ((fd = open(f, O_RDONLY)) < 0)
	{
		ft_dprintf(2, "%s\n", strerror(errno));
		exit(1);
	}
	err = read(fd, &c, 1);
	if (!err)
	{
		ft_dprintf(2, "%s is empty\n", f);
		close(fd);
		exit(0);
	}
	if (err < 0)
	{
		ft_dprintf(2, "%s\n", strerror(errno));
		close(fd);
		exit(1);
	}
	lseek(fd, -1, SEEK_CUR);
	return (fd);
}

t_lines		*ft_link_list(char *line, t_lines *l)
{
	t_lines		*tmp;
	t_lines		*new;

	tmp = l;
	if (!(new = (t_lines *)ft_memalloc(sizeof(t_lines))))
		return(NULL);
	new->line = line;
	if (!l)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (l);
}

void		read_file(t_all *d)
{
	char	*l;
	int	nb;

	nb = 0;
	while (get_next_line(d->fd, &l) > 0)
	{
		nb++;
		if (count_words(l, " ") != 9)
		{
			ft_strdel(&l);
			close(d->fd);
			ft_dprintf(2, "Error lenght line %d\n", nb);
			ft_free_lines(d->l);
			exit(1);
		}
		if (!(d->l = ft_link_list(l, d->l)))
		{
			close(d->fd);
			error_malloc(d, l);
		}
	}
	if (nb != 9)
	{
		close(d->fd);
		ft_free_lines(d->l);
		ft_dprintf(2, "Error nuber of lines\n");
		exit(1);
	}
	close(d->fd);
}

void		check_syntax(t_all *d)
{
	t_lines		*l;
	int		i;

	l = d->l;
	while (l)
	{
		i = 0;
		while (l->line[i])
		{
			if ((!ft_isdigit(l->line[i]) && l->line[i] != ' ') ||
                    (ft_isdigit(l->line[i]) && ft_isdigit(l->line[i + 1])))
			{
				ft_free_lines(d->l);
				ft_dprintf(2, "Error syntax file\n");
				exit(1);
			}
			i++;
		}
		l = l->next;
	}
}

void		ft_print(int **tab, int **cp, int a, int b)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	ft_printf("%s ___________________________________%s\n", BLUE, DEF);
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			j % 3 == 0 ? ft_printf("%s|", BLUE) : ft_printf("%s|", MAGENTA);
			ft_printf("%s", DEF);
			if (cp[i][j] == 0 && i == a && j == b && tab[i][j] != 0)
				ft_printf(" %s%d%s ", YELLOW, tab[i][j], DEF);
			else if (cp[i][j] == 0 && tab[i][j] != 0)
				ft_printf(" %s%d%s ", GREEN, tab[i][j], DEF);
			else if (tab[i][j] == 0)
				ft_printf("   ");
			else
				ft_printf(" %s%d%s ", RED, tab[i][j], DEF);
			j++;
		}
		i++;
		ft_printf("%s|\n", BLUE);
		l = 0;
		while (l < 9)
		{
			l % 3 == 0 ? ft_printf("%s", BLUE) : ft_printf("%s", MAGENTA);
			ft_printf("|");
			i % 3 == 0 ? ft_printf("%s", BLUE) : ft_printf("%s", MAGENTA);
			ft_printf("___");
			l++;
		}
		ft_printf("%s|%s\n", BLUE, DEF);
	}
}

int		flag_sleep(char *f, t_all *d)
{
	int	sng;

	if (strlen(f) >= 2)
	{
		sng = f[2] == '+' || f[2] == '-' ? 1 : 0;
		if (!ft_strncmp(f, SFLG, 2) && ft_all_digit(&f[2 + sng]))
		{
			d->slp = ft_atoi(&f[2 + sng]);
			return (1);
		}
		else if (!ft_strncmp(f, STP, 2) && ft_all_digit(&f[2 + sng]))
		{
			d->stop = ft_atoi(&f[2 + sng]);
			return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_all		*d;
	int		i;

    if (!(d = (t_all *)ft_memalloc(sizeof(t_all))))
    {
        ft_dprintf(2, "%s\n", strerror(errno));
        return (-1);
    }
	if (ac >= 2)
	{
		i = flag_sleep(av[1], d) ? 2 : 1;
		ac > 2 && flag_sleep(av[2], d) && i == 2 ? i = 3 : 0;
		while (i < ac)
		{
			d->fd = check_filee(av[i]);
			read_file(d);
			check_syntax(d);
			ft_solution(d);
			ft_print(d->tab, d->cp, -1, -1);
			ft_free_tables(d->tab, d->cp);
			d->tab = NULL;
			d->cp = NULL;
			ft_free_lines(d->l);
			d->l = NULL;
			i++;
			i < ac ? sleep(d->stop) : 0;
		}
	}
	else
	{
		ft_printf("usage : ./sudoku [file sudoku]\n");
		ft_printf("	 -s[time sleep milliseconde]\n");
	}
    ft_memdel((void *)&d);
	return (0);
}
