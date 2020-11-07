/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:31:55 by alzaynou          #+#    #+#             */
/*   Updated: 2020/10/28 23:15:44 by alzaynou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		helper(size_t **tab, char *str, char *c)
{
	size_t		i;
	size_t		words;
	size_t		len;

	i = 0;
	words = 1;
	while (str[i])
	{
		if ((len = ft_strnlen(&str[i], c)))
		{
			tab[words][0] = i;
			tab[words++][1] = len;
			i += len;
		}
		else
			i++;
	}
}

size_t				**start_end_words(char *str, char *c)
{
	size_t		i;
	size_t		words;
	size_t		**tab;

	i = 0;
	words = count_words(str, c);
	if (!words || !(tab = (size_t **)malloc(sizeof(size_t *) * (words + 1))))
		return (NULL);
	while (i <= words)
		if (!(tab[i++] = (size_t *)malloc(sizeof(size_t) * 2)))
		{
			ft_free_rev((void **)tab, i - 2);
			return (NULL);
		}
	tab[0][0] = words;
	tab[0][1] = words;
	helper(tab, str, c);
	return (tab);
}
