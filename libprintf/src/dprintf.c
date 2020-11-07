/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:59:29 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/07 14:36:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void		putformat_(t_data *d)
{
	ft_putchar_fd(d->str[d->i++], d->fd);
	d->ret++;
}

void		unkown_(t_data *d)
{
	write(d->fd, "%", 1);
	(d->flag & SPACE_) ? write(d->fd, " ", 1) : 0;
	(d->flag & SPACE_) ? d->ret += 2 : d->ret++;
}

void		read_format(t_data *d)
{
	size_t	cp;

	cp = ++d->i;
	if (d->str[d->i])
	{
		flags_(d);
		width_precision(d);
		length_(d);
		d->length ? cp = d->i : 0;
		specifier_(d);
		!(d->specif & DI_) && !(d->specif & P_) ?\
			(d->flag -= (d->flag & PLUS_)) : 0;
		!(d->specif & X_) && !(d->specif & X_X) && !(d->specif & O_) ?\
			(d->flag -= (d->flag & HASH_)) : 0;
		(!(d->specif & DI_) && !(d->specif & P_)) ||\
			(d->flag & PLUS_) ? (d->flag -= (d->flag & SPACE_)) : 0;
		!d->specif && (d->i = cp) ? unkown_(d) : get_arg(d);
	}
	else
		d->ret = -1;
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_data		*d;
    int         ret;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		return (-1);
    if (!(d->wid_pre = (t_widpre *)ft_memalloc(sizeof(t_widpre))))
    {
        ft_memdel((void *)&d);
        return (-1);
    }
	d->str = format;
	d->fd = fd;
	va_start(d->ap, format);
	while (d->str[d->i] && d->ret != -1)
		d->str[d->i] == '%' ? read_format(d) : putformat_(d);
	va_end(d->ap);
	ret = d->ret;
	ft_memdel((void *)&d->wid_pre);
	ft_memdel((void *)&d);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	t_data		*d;
    int         ret;

	if (!(d = (t_data *)ft_memalloc(sizeof(t_data))))
		return (-1);
   if (!(d->wid_pre = (t_widpre *)ft_memalloc(sizeof(t_widpre))))
   {
       ft_memdel((void*)&d);
       return (-1);
   }
	d->str = format;
	d->fd = _OUT;
	va_start(d->ap, format);
	while (d->str[d->i] && d->ret != -1)
		d->str[d->i] == '%' ? read_format(d) : putformat_(d);
	va_end(d->ap);
    ret = d->ret;
    ft_memdel((void *)&d->wid_pre);
	ft_memdel((void *)&d);
	return (ret);
}
