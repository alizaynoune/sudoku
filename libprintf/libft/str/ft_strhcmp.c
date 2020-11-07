/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:26:31 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/16 16:33:08 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		alpha_(char s1, char s2)
{
	s1 = s1 >= 'A' && s1 <= 'Z' ? s1 + 32 : s1;
	s2 = s2 >= 'A' && s2 <= 'Z' ? s2 + 32 : s2;
	return (s1 - s2);
}

int		alpha_helper(char s1, char s2)
{
	s1 += (s1 >= 'A' && s1 <= 'Z') ? 32 : -32;
	s2 += (s2 >= 'A' && s2 <= 'Z') ? 32 : -32;
	return (s1 - s2);
}

int		type_(char s1, char s2)
{
	if (!s1 || !s2)
		return (s1 - s2);
	if (ft_isalnum(s1) && !ft_isalnum(s2))
		return (1);
	if (!ft_isalnum(s1) && ft_isalnum(s2))
		return (-1);
	if (!ft_isalnum(s1) && !ft_isalnum(s2))
		return (s1 - s2);
	if (ft_isalpha(s1) && ft_isdigit(s2))
		return (1);
	if (ft_isdigit(s1) && ft_isalpha(s2))
		return (-1);
	if (ft_isdigit(s1) && ft_isdigit(s2))
		return (s1 - s2);
	return (s1 - s2);
}

int		ft_strhcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (!ret && (s1[i] || s2[i]))
	{
		ret = (ft_isalpha(s1[i]) && ft_isalpha(s2[i])) ?
			alpha_(s1[i], s2[i]) : type_(s1[i], s2[i]);
		i++;
	}
	if (ret)
		return (ret);
	i = 0;
	while (!ret && (s1[i] || s2[i]))
	{
		ret = (ft_isalpha(s1[i]) && ft_isalpha(s2[i])) ?
		alpha_helper(s1[i], s2[i]) : type_(s1[i], s2[i]);
		i++;
	}
	return (ret);
}
