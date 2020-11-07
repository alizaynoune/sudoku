/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdynamic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:25:23 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/16 16:25:25 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdynamic(void *src, size_t len)
{
	void	*fresh;

	if (!(fresh = (void *)malloc((sizeof(void *)) * (len * 2))))
		return (NULL);
	fresh = ft_memcpy(fresh, src, len);
	ft_memset(fresh + len, 0, len);
	return (fresh);
}
