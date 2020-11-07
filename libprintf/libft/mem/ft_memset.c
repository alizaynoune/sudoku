/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:39:25 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:07:40 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	nch;
	t_char	*str;

	nch = 0;
	str = (t_char *)b;
	while (nch < len)
		str[nch++] = (t_char)c;
	return ((void *)str);
}
