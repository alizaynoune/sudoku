/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:18:00 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:19:01 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(char *str)
{
	unsigned long long	sum;
	short				sing;
	size_t				i;

	sum = 0;
	if (!str)
		return (0);
	i = ft_skip_char(str, "\t ");
	sing = str[i] == '-' ? -1 : 1;
	str[i] == '-' || str[i] == '+' ? i += 1 : 0;
	while (ft_isdigit(str[i]) && sum < LLONG_MAX)
		sum = (sum * 10) + (str[i++] - '0');
	if (sum > LONG_MAX && sing == 1)
		return (LONG_MAX);
	if (sum > LONG_MAX)
		return (LONG_MIN);
	return (sum * sing);
}
