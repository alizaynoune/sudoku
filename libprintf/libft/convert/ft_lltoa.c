/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:19:37 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:21:07 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa(long long int n)
{
	unsigned long long	nb;
	int					len;
	char				*str;

	len = ft_intlen(n);
	nb = n < 0 ? n * -1 : n;
	n == 0 ? len = 1 : 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	n < 0 ? str[0] = '-' : 0;
	n == 0 ? str[0] = '0' : 0;
	return (str);
}
