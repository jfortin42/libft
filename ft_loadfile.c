/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:25 by jfortin           #+#    #+#             */
/*   Updated: 2018/03/30 18:10:44 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>

static char		*file;
static size_t	size;

void		ft_unloadfile()
{
	if (munmap(file, size) == -1)
	{
		perror("error munmap\n");
		exit(1);
	}
}

static void	error(const char *message, const char *path_file)
{
	ft_putstr_fd(message, 2);
	ft_putendl_fd(path_file, 2);
	perror(NULL);
}

char		*ft_loadfile(const char *path_file)
{
	int			fd;
	struct stat	st;;

	if ((fd = ft_open(path_file, O_RDONLY)) == -1)
		return (NULL);
	if (fstat(fd, &st) == -1)
	{
		error("error fstat of :", path_file);
		close(fd);
		return (NULL);
	}
	size = st.st_size + 1;
	file = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (file == MAP_FAILED)
	{
		error("error mmap of ", path_file);
		return (NULL);
	}
	file[size - 1] = '\0';
	return (file);
}
