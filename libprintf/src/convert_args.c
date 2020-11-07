/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:07:10 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 18:09:58 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	string_(t_data *d, char *str)
{
	size_t	l;
	size_t	i;

	!str && (d->wid_pre->precision >= 6 ||\
			!(d->flag & DOT_)) ? str = "(null)" : 0;
	!str ? str = "" : 0;
	l = ft_strlen(str);
	l = l > d->wid_pre->precision && (d->flag & DOT_) ?\
		d->wid_pre->precision : l;
	i = 0;
	!(d->flag & LEFT_) && l < d->wid_pre->width ?\
		loop_char(d, ' ', d->wid_pre->width - l) : 0;
	while (i < l && ++d->ret)
		write(d->fd, &str[i++], 1);
	(d->flag & LEFT_) && l < d->wid_pre->width ?\
		loop_char(d, ' ', d->wid_pre->width - l) : 0;
}

void	char_(t_data *d, int c)
{
	!(d->flag & LEFT_) ? loop_char(d, ' ', d->wid_pre->width - 1) : 0;
	write(d->fd, &c, 1);
	d->ret++;
	(d->flag & LEFT_) ? loop_char(d, ' ', d->wid_pre->width - 1) : 0;
}

char	*unsigned_str_(t_data *d, unsigned long long int value)
{
	char					*str;
	int						i;
	unsigned long long int	nbr;

	i = 0;
	nbr = value;
	while ((nbr /= 10))
		i++;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (i + 2))))
		exit_error_(d);
	while (i >= 0)
	{
		str[i--] = (value % 10) + '0';
		value /= 10;
	}
	return (str);
}

char	*base_str_(t_data *d, unsigned long long int v_, char *s_, size_t base)
{
	unsigned long long int	nbr;
	char					*str;
	int						i;

	i = 0;
	nbr = v_;
	while ((nbr /= base))
		i++;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (i + 2))))
		exit_error_(d);
	while (i >= 0)
	{
		str[i] = s_[v_ % base];
		v_ /= base;
		i--;
	}
	return (str);
}
