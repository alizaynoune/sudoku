#ifndef SUDOKU_H
#define SUDOKU_H
/* includes
 */
#include <errno.h>
#include "../libprintf/includes/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>

/* Macros
 */
#define RED	("\e[1;31m")
#define GREEN	("\e[32;1m")
#define DEF	("\e[0m")
#define YELLOW	("\e[1;33m")
#define BLUE	("\e[1;96m")
#define MAGENTA	("\e[1;95m")
#define SFLG	("-s")
/* structur
 */
typedef struct		s_lines
{
	char		*line;
	struct s_lines	*next;
}			t_lines;


typedef struct		s_data
{
	t_lines		*l;
	int		fd;
	int		**tab;
	int		**cp;
	int		flag;
	long		slp;
}			t_data;

void		error_malloc(t_data *d, char *l);
void		ft_free_lines(t_lines *l);
void		ft_solution(t_data *d);
void		ft_print(int **tab, int **cp, int a, int b);
void		ft_free_tables(int **t, int **c);

#endif
