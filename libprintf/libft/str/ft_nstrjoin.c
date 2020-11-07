/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:26:11 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/16 16:26:15 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_nstrjoin(size_t n, ...)
{
	char		*fresh;
	char		*ptr;
	va_list		ap;

	va_start(ap, n);
	if (!n || !(fresh = ft_strdup(va_arg(ap, char *))))
		return (NULL);
	while (--n)
	{
		ptr = fresh;
		if (!(fresh = ft_strjoin(fresh, va_arg(ap, char *))))
		{
			free(fresh);
			return (NULL);
		}
		free(ptr);
	}
	va_end(ap);
	return (fresh);
}
