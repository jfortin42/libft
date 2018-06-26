/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:25 by jfortin           #+#    #+#             */
/*   Updated: 2018/06/26 19:06:04 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>

void		*ft_unloadfile(t_file *file)
{
	if (file && file->data && munmap(file->data, file->size) == -1)
	{
		perror("error munmap\n");
		exit(1);
	}
	file->size = 0;
	file->data = NULL;
	free(file);
	return (NULL);
}

static void	error(const char *message, const char *path_file)
{
	ft_putstr_fd(message, 2);
	ft_putendl_fd(path_file, 2);
	perror(NULL);
}

t_file		*ft_loadfile(const char *path_file)
{
	int			fd;
	struct stat	st;
	t_file		*file;

	if ((fd = ft_open(path_file, O_RDONLY)) == -1)
		return (NULL);
	if (fstat(fd, &st) == -1)
	{
		error("error fstat of :", path_file);
		close(fd);
		return (NULL);
	}
	file = (t_file *)ft_prot_malloc(sizeof(t_file));
	file->size = st.st_size + 1;
	file->data = mmap(NULL, file->size, PROT_READ | PROT_WRITE, MAP_PRIVATE
	, fd, 0);
	close(fd);
	if (file->data == MAP_FAILED)
	{
		error("error mmap of ", path_file);
		free(file);
		return (NULL);
	}
	file->data[file->size - 1] = '\0';
	return (file);
}
