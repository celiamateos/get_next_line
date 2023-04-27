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
    buffer[ft_strlen(buffer)] = '\0';
    printf("%s/n", buffer);
    free (buffer);
    
    return (aux);
}

char    *save_line(int fd, char *aux, char *line)
{
    size_t  i;

    i = 0;
    while (!ft_strchr(aux, '\n'))
        {
            aux[i] = line[i];
            line[i] = '\0';
            i++;
        }
    return (line);
}

char    *get_next_line(int fd)
{
    static char *aux;
    char        *line;
    size_t      i;

    i = 0;
    if (fd < -1)
        return (NULL, "No existe fd");
    else
//            while (no haya terminado de leer todo el fd)
        read_line(fd, aux);
    if (aux[i] != 0)    
    {
        save_line(fd, aux, line);
        return (line);
    }
    return (0);
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
