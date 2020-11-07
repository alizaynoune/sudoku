/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:17:47 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:17:52 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll_all(char *str)
{
	size_t	i;

	i = ft_skip_char(str, "\t ");
	str[i] == '-' || str[i] == '+' ? i += 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	i += ft_skip_char(&str[i], "\t ");
	if (str[i])
		return (0);
	return (ft_atoll(str));
}
