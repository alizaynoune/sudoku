/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:22:59 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/07 14:34:14 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void		exit_error_(t_data *d)
{
	(d) ? va_end(d->ap) : 0;
    (d && d->wid_pre) ? ft_memdel((void *)&d->wid_pre) : 0;
	(d) ? ft_memdel((void *)&d) : 0;
	exit(-1);
}

void		reset_data(t_data *d)
{
	ft_bzero((void *)d->wid_pre, sizeof(t_widpre));
	d->flag = 0;
	d->specif = 0;
	d->length = 0;
}

size_t		ato_unsint_(const char *str)
{
	size_t		num;
	size_t		i;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	return (num);
}

void		flags_(t_data *d)
{
	while (d->str[d->i])
	{
		if (d->str[d->i] == '#')
			d->flag |= HASH_;
		else if (d->str[d->i] == ' ')
			d->flag |= SPACE_;
		else if (d->str[d->i] == '0')
			d->flag |= ZERO_;
		else if (d->str[d->i] == '-')
			d->flag |= LEFT_;
		else if (d->str[d->i] == '+')
			d->flag |= PLUS_;
		else
			break ;
		d->i++;
	}
}
