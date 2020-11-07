/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:10:14 by alzaynou          #+#    #+#             */
/*   Updated: 2020/11/07 14:42:07 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = 0;
	if (size >= 1)
		if (!(ptr = (void *)malloc(sizeof(void) * size)))
			return (NULL);
	(size > 0) ? ft_memset(ptr, 0, sizeof(void) * size) : 0;
	return (ptr);
}
