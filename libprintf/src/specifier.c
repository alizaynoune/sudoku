/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:15:29 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 19:44:16 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void		length_(t_data *d)
{
	if (d->str[d->i] == 'l' || d->str[d->i] == 'h')
	{
		if (d->str[d->i] == 'l')
			d->str[d->i + 1] == 'l' ? d->length |= LL_
				: (d->length |= L_);
		else if (d->str[d->i] == 'h')
			d->str[d->i + 1] == 'h' ? d->length |= HH_
				: (d->length |= H_);
		(d->length & LL_) || (d->length & HH_) ? d->i += 2 : d->i++;
	}
}

void		width_(t_data *d)
{
	if (d->str[d->i] == '*')
	{
		d->wid_pre->width = va_arg(d->ap, unsigned int);
		d->i++;
	}
	else
	{
		d->wid_pre->width = ato_unsint_(&d->str[d->i]);
		while (ft_isdigit(d->str[d->i]))
			d->i++;
	}
}

void		precision_(t_data *d)
{
	if (d->str[d->i] == '*')
	{
		d->wid_pre->precision = va_arg(d->ap, unsigned int);
		d->i++;
	}
	else
	{
		d->wid_pre->precision = ato_unsint_(&d->str[d->i]);
		while (ft_isdigit(d->str[d->i]))
			d->i++;
	}
}

void		width_precision(t_data *d)
{
	width_(d);
	if (d->str[d->i] == '.')
	{
		d->flag |= DOT_;
		d->i++;
		d->flag -= (d->flag & ZERO_);
	}
	precision_(d);
	d->flag & ZERO_ && d->flag & LEFT_ ? d->flag -= (d->flag & ZERO_) : 0;
}

void		specifier_(t_data *d)
{
	d->str[d->i] == 's' || d->str[d->i] == 'S' ? d->specif |= S_ : 0;
	d->str[d->i] == 'c' || d->str[d->i] == 'C' ? d->specif |= C_ : 0;
	d->str[d->i] == 'p' || d->str[d->i] == 'P' ? d->specif |= P_ : 0;
	d->str[d->i] == 'i' || d->str[d->i] == 'd' || d->str[d->i] == 'I' ||
		d->str[d->i] == 'D' ? d->specif |= DI_ : 0;
	d->str[d->i] == 'o' || d->str[d->i] == 'O' ? d->specif |= O_ : 0;
	d->str[d->i] == 'u' || d->str[d->i] == 'U' ? d->specif |= U_ : 0;
	d->str[d->i] == 'x' ? d->specif |= X_ : 0;
	d->str[d->i] == 'X' ? d->specif |= X_X : 0;
	d->str[d->i] == 'b' || d->str[d->i] == 'B' ? d->specif |= B_ : 0;
	d->str[d->i] == '%' ? d->specif |= MOD_ : 0;
	d->specif ? d->i++ : 0;
}
