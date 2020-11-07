/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:24:16 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:06:09 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t fnd;

	if (!n)
		return (NULL);
	fnd = 0;
	while (fnd < n)
	{
		if (((t_char *)s)[fnd] != (t_char)c)
			fnd++;
		else
			return (&((t_char *)s)[fnd]);
	}
	return (NULL);
}
