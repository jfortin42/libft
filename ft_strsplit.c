/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:25:56 by jfortin           #+#    #+#             */
/*   Updated: 2016/03/09 13:49:23 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_cntw(char const *s, char c)
{
	unsigned int w;

	w = 0;
	while (s && *s)
	{
		while (*s == c)
			++s;
		if (*s)
			++w;
		while (*s && *s != c)
			++s;
	}
	return (w);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	char const		*tmp;
	unsigned int	i;

	i = ft_cntw(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	i = 0;
	while (s && *s)
	{
		while (*s == c)
			++s;
		tmp = s;
		while (*s && *s != c)
			++s;
		if (tmp < s)
			tab[i++] = ft_strsub(tmp, 0, s - tmp);
	}
	return (tab);
}
