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
    size_t  i;
    size_t  BUFFER_SIZE = 6;

    i = 0;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    else
        read(fd, buffer, BUFFER_SIZE);
        aux = ft_strjoin_gnl(aux, buffer);
    if (buffer)
    {
        while (!ft_strchr_gnl(buffer, '\n') || !ft_strchr_gnl(buffer, '\0'))
            read(fd, buffer, BUFFER_SIZE);
            printf("Contenido del buffer: %s/n", buffer);
            aux = ft_strjoin_gnl(aux, buffer);
            printf("Contenido de aux: %s/n", aux);          
    }
    else
    {
        free (buffer);
        return (NULL);
    }
    
    
    free (buffer);
    return (aux);
}

char    *save_line(char *aux, char *line)
{
    size_t  i;

    i = 0;
    if (aux[i] == '\0')
        return (NULL);
    else
    {
        while (aux[i] == !ft_strchr_gnl(aux, '\n') + 1 || !ft_strchr_gnl(aux, '\0'))
            {
                aux[i] = line[i];
                aux[i] = '\0';
                i++;
            }
        line[i] = '\0';
    }
    return (line);
}

char    *get_next_line(int fd)
{
    static char *aux;
    char        *line;
    size_t      i;

    i = 0;
    if (fd < 0)
        return (NULL);
    else
        read_line(fd, aux);
    if (aux[i] != 0)    
    {
        printf("Contenido de aux: %s\n", aux);
        save_line(aux, line);
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
    printf("gnl: %s/n", gnl);
    close(fd);
    return (0);
}
