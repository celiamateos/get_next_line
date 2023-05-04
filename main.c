/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:11:03 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/04 15:30:36 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*gnl;

	fd = open("myfd.txt", O_RDONLY);
//	printf("File descriptor asignado: %d\n", fd);
	if (fd < 0)
		return (0);
/*	while ((gnl = get_next_line(fd)))
	{
		printf("line: %s", gnl);
		free(gnl);
	}*/
	while (1)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
		if (gnl == NULL)
			return (0);
		free(gnl);
	}
	close(fd);
//	system("leaks a.out");
	return (0);
}
