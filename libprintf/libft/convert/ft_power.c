/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:19:56 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:27:19 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nbr, int power)
{
	int		sum;

	sum = nbr;
	if (power == 0)
		return (1);
	while (--power > 0)
		sum *= nbr;
	return (sum);
}
