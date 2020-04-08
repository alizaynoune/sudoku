/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:38:06 by alzaynou          #+#    #+#             */
/*   Updated: 2019/12/26 19:19:32 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlen(const char *s)
{
	size_t cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}