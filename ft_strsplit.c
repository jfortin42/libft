/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:25:56 by jfortin           #+#    #+#             */
/*   Updated: 2015/11/24 10:40:19 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntw(char const *s, char c)
{
	unsigned int	i;
	unsigned int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] != c && s[i])
			i++;
	}
	return (w);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntw(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] == c)
		i++;
	j = i;
	while (s[i] != c && s[i])
		i++;
	if (i < j)
	{
		tab[k] = ft_strndup(s + i, j - i);
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
