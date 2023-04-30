/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:11:03 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/29 21:19:19 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*gnl;

	fd = open("my_first_fd.txt", O_RDONLY);
	while ((gnl = get_next_line(fd)))
	{
		printf("gnl: %s\n", gnl);
		free(gnl);
	}
	close(fd);
	return (0);
}
