/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 20:40:24 by jfortin           #+#    #+#             */
/*   Updated: 2018/03/30 18:10:58 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_prot_malloc(size_t size)
{
	void	*out;

	if ((out = malloc(size)) == NULL)
	{
		ft_putendl_fd("error malloc", 2);
		perror(NULL);
		exit(1);
	}
	return (out);
}

void	*ft_prot_realloc(void *ptr, size_t size)
{
	void	*out;

	if ((out = realloc(ptr, size)) == NULL)
	{
		ft_putendl_fd("error realloc", 2);
		perror(NULL);
		free(ptr);
		exit(1);
	}
	return (out);
}
