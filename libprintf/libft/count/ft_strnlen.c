/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:31:42 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/15 20:31:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(char *str, char *c)
{
	size_t	len;

	len = 0;
	while (str[len] && !ft_strchr(c, str[len]))
		len++;
	return (len);
}
