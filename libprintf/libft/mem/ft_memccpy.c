/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:30:42 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:03:42 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_char	*msrc;
	t_char	*mdst;
	size_t	nb;

	msrc = (t_char *)src;
	mdst = (t_char *)dst;
	nb = 0;
	while (nb < n)
	{
		mdst[nb] = msrc[nb];
		if (msrc[nb] == (t_char)c)
			return (&mdst[nb + 1]);
		nb++;
	}
	return (NULL);
}
