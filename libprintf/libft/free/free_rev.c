/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:34:13 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:34:18 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_rev(void **tab, int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		tab[len--] = NULL;
	}
	tab != NULL ? free(tab) : 0;
}