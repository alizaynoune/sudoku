/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:10:14 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/27 11:56:23 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = 0;
	if (size >= 1)
	{
		if (!(ptr = malloc(size)))
			return (NULL);
		ft_memset(ptr, 0, size);
	}
	return (ptr);
}
