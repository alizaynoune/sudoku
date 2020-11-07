/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _put.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:03:36 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/07 13:54:50 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	put_str_(t_data *d, char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		write(d->fd, &str[i++], 1);
		d->ret++;
	}
}

void	loop_char(t_data *d, char c, int loop)
{
	while (loop > 0)
	{
		write(d->fd, &c, 1);
		d->ret++;
		loop--;
	}
}

void	put_decimal_(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(str[0] == '-') ? d->flag -= (d->flag & SPACE_) : 0;
	(str[0] == '-') ? d->flag -= (d->flag & PLUS_) : 0;
	(d->flag & DOT_) && str[0] == '0' ? str = "" : 0;
	fix_len_decimal_(d, str);
	d->wid_pre->width && (d->flag & PLUS_ || d->flag & SPACE_ ||\
			str[0] == '-') ? d->wid_pre->width-- : 0;
	!(d->flag & LEFT_) && !(d->flag & ZERO_) ?\
		loop_char(d, ' ', d->wid_pre->width) : 0;
	d->flag & PLUS_ || d->flag & SPACE_ ||\
		str[0] == '-' ? put_flag_(d, str[0]) : 0;
	!(d->flag & LEFT_) && (d->flag & ZERO_) ?\
		loop_char(d, '0', d->wid_pre->width) : 0;
	(d->wid_pre->precision) ? loop_char(d, '0', d->wid_pre->precision) : 0;
	str[0] == '-' ? str++ : 0;
	put_str_(d, str);
	(d->flag & LEFT_) ? loop_char(d, ' ', d->wid_pre->width) : 0;
	ft_memdel((void *)&ptr);
}

void	put_octal_(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(d->flag & DOT_) && str[0] == '0' ? str = "" : 0;
	(str[0] == '0') ? d->flag -= (d->flag & HASH_) : 0;
	fix_len_octal_(d, str);
	(d->flag & HASH_) && d->wid_pre->width ? d->wid_pre->width-- : 0;
	!(d->flag & LEFT_) && !(d->flag & ZERO_) ?\
		loop_char(d, ' ', d->wid_pre->width) : 0;
	(d->flag & HASH_) ? loop_char(d, '0', 1) : 0;
	(d->wid_pre->precision) ? loop_char(d, '0', d->wid_pre->precision) : 0;
	!(d->flag & LEFT_) && (d->flag & ZERO_) ?\
		loop_char(d, '0', d->wid_pre->width) : 0;
	put_str_(d, str);
	(d->flag & LEFT_) ? loop_char(d, ' ', d->wid_pre->width) : 0;
	ft_memdel((void *)&ptr);
}

void	put_hexa_(t_data *d, char *str)
{
	char	*ptr;

	ptr = str;
	(d->specif & P_) ? fix_p_(d, &str) : 0;
	(str[0] == '0') ? d->flag -= (d->flag & HASH_) : 0;
	(d->flag & DOT_) && str[0] == '0' ? str = "" : 0;
	fix_len_decimal_(d, str);
	if ((d->flag & HASH_) && d->wid_pre->width >= 1)
		d->wid_pre->width -= d->wid_pre->width > 1 ? 2 : 1;
	(d->wid_pre->width) && ((d->flag & PLUS_) || (d->flag & SPACE_))\
		? d->wid_pre->width-- : 0;
	!(d->flag & LEFT_) && !(d->flag & ZERO_) ?\
		loop_char(d, ' ', d->wid_pre->width) : 0;
	if (d->specif & P_ && ((d->flag & SPACE_) || (d->flag & PLUS_)))
		(d->flag & SPACE_) ?\
			loop_char(d, ' ', 1) : loop_char(d, '+', 1);
	(d->flag & HASH_) ? put_hash_(d) : 0;
	!(d->flag & LEFT_) && (d->flag & ZERO_) ?\
		loop_char(d, '0', d->wid_pre->width) : 0;
	(d->wid_pre->precision) ? loop_char(d, '0', d->wid_pre->precision) : 0;
	put_str_(d, str);
	(d->flag & LEFT_) ? loop_char(d, ' ', d->wid_pre->width) : 0;
	ft_memdel((void *)&ptr);
}
