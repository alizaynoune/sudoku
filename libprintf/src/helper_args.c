/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:13:43 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 18:13:48 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	octal_(t_data *d)
{
	char	*str;

	str = "01234567";
	!(d->length) ? put_octal_(d,\
			base_str_(d, va_arg(d->ap, unsigned int), str, 8)) : 0;
	(d->length & L_) ? put_octal_(d, base_str_(d,\
				va_arg(d->ap, unsigned long int), str, 8)) : 0;
	(d->length & LL_) ? put_octal_(d, base_str_(d,\
			va_arg(d->ap, unsigned long long int), str, 8)) : 0;
	(d->length & H_) ? put_octal_(d, base_str_(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), str, 8)) : 0;
	(d->length & HH_) ? put_octal_(d, base_str_(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), str, 8)) : 0;
}

void	binary_(t_data *d)
{
	char	*str;

	str = "01";
	!(d->length) ? put_decimal_(d, base_str_(d,\
				va_arg(d->ap, unsigned int), str, 2)) : 0;
	(d->length & L_) ? put_decimal_(d, base_str_(d,\
				va_arg(d->ap, unsigned long int), str, 2)) : 0;
	(d->length & LL_) ? put_decimal_(d, base_str_(d, va_arg(d->ap,\
					unsigned long long int), str, 2)) : 0;
	(d->length & H_) ? put_decimal_(d, base_str_(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), str, 2)) : 0;
	(d->length & HH_) ? put_decimal_(d, base_str_(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), str, 2)) : 0;
}
