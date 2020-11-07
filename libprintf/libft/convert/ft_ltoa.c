/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:20:18 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:29:09 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoa(long int n)
{
	int				len;
	unsigned long	nb;
	char			*str;

	len = ft_intlen(n);
	len == 0 ? len = 1 : 0;
	nb = n < 0 ? n * -1 : n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	n < 0 ? str[0] = '-' : 0;
	n == 0 ? str[0] = '0' : 0;
	return (str);
}
