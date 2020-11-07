/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:14:17 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 18:15:12 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	put_flag_(t_data *d, char c)
{
	d->flag & PLUS_ ? write(d->fd, "+", 1) : 0;
	d->flag & SPACE_ ? write(d->fd, " ", 1) : 0;
	c == '-' ? write(d->fd, "-", 1) : 0;
	d->ret++;
}

void	put_hash_(t_data *d)
{
	(d->specif & X_) || (d->specif & P_) ? put_str_(d, "0x") : 0;
	(d->specif & X_X) ? put_str_(d, "0X") : 0;
}

void	fix_len_decimal_(t_data *d, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	str[0] == '-' ? len-- : 0;
	d->wid_pre->precision -= d->wid_pre->precision > len ?\
				len : d->wid_pre->precision;
	d->wid_pre->width -= d->wid_pre->width > (d->wid_pre->precision + len) ?\
						(d->wid_pre->precision + len) : d->wid_pre->width;
}

void	fix_len_octal_(t_data *d, char *str)
{
	size_t		len;

	len = ft_strlen(str);
	d->wid_pre->precision -= d->wid_pre->precision > len ?\
				len : d->wid_pre->precision;
	d->wid_pre->precision && (d->flag & HASH_) ? d->wid_pre->precision-- : 0;
	d->wid_pre->width -= d->wid_pre->width > (d->wid_pre->precision + len)\
						? (d->wid_pre->precision + len) : d->wid_pre->width;
}

void	fix_p_(t_data *d, char **str)
{
	if (*str[0] == '0')
	{
		d->wid_pre->precision = 0;
		d->flag -= (d->flag & ZERO_);
		d->flag -= (d->flag & PLUS_);
		d->flag -= (d->flag & SPACE_);
		*str = "(nil)";
	}
	else
		d->flag |= HASH_;
}
