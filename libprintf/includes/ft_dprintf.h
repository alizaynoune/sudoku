/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:16:38 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/07 13:45:10 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define C_		1
# define S_		2
# define P_		4
# define DI_	8
# define O_		16
# define U_		32
# define X_		64
# define X_X	128
# define MOD_	256
# define B_		512

# define H_		1
# define HH_	2
# define L_		4
# define LL_	8

# define LEFT_	1
# define HASH_	2
# define PLUS_	4
# define ZERO_	8
# define SPACE_	16
# define DOT_	32

# define _OUT   1
# define _ERR   2

typedef struct			s_widpre
{
	size_t				width;
	size_t				precision;
}						t_widpre;

typedef struct			s_data
{
	va_list				ap;
	int					fd;
	const char			*str;
	size_t				len;
	size_t				i;
	int					ret;
	int					flag;
	short				specif;
	short				length;
	t_widpre            *wid_pre;
}						t_data;

int						ft_dprintf(int fd, const char *format, ...);
void					get_arg(t_data *d);
void					flags_(t_data *d);
void					width_precision(t_data *d);
void					length_(t_data *d);
void					specifier_(t_data *d);
void					string_(t_data *d, char *str);
void					char_(t_data *d, int c);
void					octal_(t_data *d);
void					binary_(t_data *d);
char					*unsigned_str_(t_data *d, unsigned long long int value);
char					*base_str_(t_data *d, unsigned long long int v,
						char *s_, size_t base);
void					fix_len_decimal_(t_data *d, char *str);
void					fix_len_octal_(t_data *d, char *str);
void					fix_p_(t_data *d, char **str);
void					loop_char(t_data *d, char c, int loop);
void					put_hash_(t_data *d);
void					put_str_(t_data *d, char *str);
void					put_octal_(t_data *d, char *str);
void					put_decimal_(t_data *d, char *str);
void					put_decimal_(t_data *d, char *str);
void					put_flag_(t_data *d, char c);
void					put_hexa_(t_data *d, char *str);
void					exit_error_(t_data *d);
void					reset_data(t_data *d);
size_t					ato_unsint_(const char *str);
int						ft_printf(const char *format, ...);
#endif
