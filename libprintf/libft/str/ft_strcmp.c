/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:22:53 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 19:58:14 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t chk;

	chk = 0;
	while (((t_char *)s1)[chk] == ((t_char *)s2)[chk]
			&& ((t_char *)s1)[chk] != '\0' && ((t_char *)s2)[chk] != '\0')
		chk++;
	return (((t_char *)s1)[chk] - ((t_char *)s2)[chk]);
}
