/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:10:35 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 18:13:06 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	decimal_(t_data *d)
{
	char	*str;

	str = NULL;
	!(d->length) ? str = ft_itoa(va_arg(d->ap, int)) : 0;
	(d->length & L_) ? str = ft_ltoa(va_arg(d->ap, long int)) : 0;
	(d->length & LL_) ? str = ft_lltoa(va_arg(d->ap, long long int)) : 0;
	(d->length & H_) ? str = ft_itoa((short int)(va_arg(d->ap, int))) : 0;
	(d->length & HH_) ? str = ft_itoa((char)(va_arg(d->ap, int))) : 0;
	!str ? exit_error_(d) : 0;
	put_decimal_(d, str);
}

void	unsigned_(t_data *d)
{
	char	*str;

	!(d->length) ? str = unsigned_str_(d, va_arg(d->ap, unsigned int)) : 0;
	(d->length & L_) ? str = unsigned_str_(d,\
			va_arg(d->ap, unsigned long int)) : 0;
	(d->length & LL_) ? str = unsigned_str_(d, va_arg(d->ap,\
				unsigned long long int)) : 0;
	(d->length & H_) ? str = unsigned_str_(d,\
			(unsigned short int)(va_arg(d->ap, unsigned int))) : 0;
	(d->length & HH_) ? str = unsigned_str_(d,\
			(unsigned char)(va_arg(d->ap, unsigned int))) : 0;
	put_decimal_(d, str);
}

void	helper_hexa_(t_data *d)
{
	char	*str;

	str = "0123456789ABCDEF";
	!(d->length) ? put_hexa_(d,\
			base_str_(d, va_arg(d->ap, unsigned int), str, 16)) : 0;
	(d->length & L_) ? put_hexa_(d, base_str_(d,\
				va_arg(d->ap, unsigned long int), str, 16)) : 0;
	(d->length & LL_) ? put_hexa_(d, base_str_(d, va_arg(d->ap,\
					unsigned long long int), str, 16)) : 0;
	(d->length & H_) ? put_hexa_(d, base_str_(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), str, 16)) : 0;
	(d->length & HH_) ? put_hexa_(d, base_str_(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), str, 16)) : 0;
}

void	hexa_(t_data *d)
{
	char	*str;

	str = "0123456789abcdef";
	d->specif & P_ ? put_hexa_(d, base_str_(d, va_arg(d->ap,\
					unsigned long long int), str, 16)) : 0;
	if (d->specif & X_)
	{
		!(d->length) ? put_hexa_(d, base_str_(d, va_arg(d->ap,\
						unsigned int), str, 16)) : 0;
		(d->length & L_) ? put_hexa_(d, base_str_(d, va_arg(d->ap,\
					unsigned long int), str, 16)) : 0;
		(d->length & LL_) ? put_hexa_(d, base_str_(d,\
			va_arg(d->ap, unsigned long long int), str, 16)) : 0;
		(d->length & H_) ? put_hexa_(d, base_str_(d,\
		(unsigned short int)(va_arg(d->ap, unsigned int)), str, 16)) : 0;
		(d->length & HH_) ? put_hexa_(d, base_str_(d,\
		(unsigned char)(va_arg(d->ap, unsigned int)), str, 16)) : 0;
	}
	else if (d->specif & X_X)
		helper_hexa_(d);
}

void	get_arg(t_data *d)
{
	(d->specif & MOD_) ? loop_char(d, '%', 1) : 0;
	(d->specif & S_) ? string_(d, va_arg(d->ap, char *)) : 0;
	(d->specif & C_) ? char_(d, va_arg(d->ap, int)) : 0;
	(d->specif & DI_) ? decimal_(d) : 0;
	(d->specif & U_) ? unsigned_(d) : 0;
	(d->specif & X_) || (d->specif & X_X) || (d->specif & P_) ? hexa_(d) : 0;
	(d->specif & O_) ? octal_(d) : 0;
	(d->specif & B_) ? binary_(d) : 0;
	reset_data(d);
}
