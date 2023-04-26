/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:40 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/26 17:16:59 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *read_line(int fd, char *aux)
{   char    *buffer;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    if (fd > 0)
        read(fd, buffer, BUFFER_SIZE);
    while (!ft_strchr(buffer, '\n'))
        read(fd, buffer, BUFFER_SIZE);
    //buffer[ft_strlen(buffer)] = '\0';
    printf("%s/n", buffer);
    
    return (aux);
}
char    *get_next_line(int fd)
{
    static char *aux;

    if (fd < -1)
        return (NULL, "No existe fd");
    else
        read_line(fd, aux);
    return (aux);
}

int main(void)
{
    int fd;
    char    *gnl;
    
    fd = open("myfd.txt", O_RDONLY);
    printf("File descriptor asignado: %d\n", fd);
    gnl = get_next_line(fd);
    printf("%s/n", gnl);
    close(fd);
    return (0);
}
