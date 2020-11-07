/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:49:16 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:04:48 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			chk;
	const t_char	*str1;
	const t_char	*str2;

	chk = 0;
	str1 = (const t_char *)s1;
	str2 = (const t_char *)s2;
	while (chk < n)
	{
		if (str1[chk] != str2[chk])
			return (str1[chk] - str2[chk]);
		chk++;
	}
	return (0);
}
