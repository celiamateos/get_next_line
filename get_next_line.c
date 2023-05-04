/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:40 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/03 19:01:39 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*auxupdater(char *aux)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	temp = malloc((ft_strlen_gnl(aux) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (aux[i] > 0)
	{
		temp[i] = aux[i];
		i++;
	}
//	printf("temp: %s\n", temp);
	temp[i] = '\0';
	free(aux);
	j = 0;
	while (temp[j++] != '\n' && temp[j]);
	aux = malloc(sizeof(char) * (i - j + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (temp[j])
		aux[i++] = temp[j++];
	aux[i] = '\0';
	free(temp);
	return (aux);
}

char	*save_line(char *aux)
{
	size_t	i;
	char	*line;

	i = 0;
	if (aux == NULL)
		return (NULL);
	while (aux[i] != '\n' && aux[i])
		i++;
	// esto itera bien?
	line = malloc(i * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (aux[i] != '\0')
	{
		if (aux[i] != '\n')
			line[i] = aux[i];
		else
		{
			line[i++] = '\n';
			line[i] = '\0';
//			printf("aux: %s\n", aux);
			return (line);
		}
		i++;
	}
	//esto de debajo no estoy segura
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *aux)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = NULL;
	while (i > 0 && !ft_strchr_gnl(aux, '\n'))
	{	
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
//		printf("buffer: %s\n", buffer);
		if (i == 0)
			return (aux);
		if (i < -1)
		{
			free(buffer);
			return (aux);
		}
		else
		{
			buffer[BUFFER_SIZE] = '\0';
			aux = ft_strjoin_gnl(aux, buffer);
			free(buffer);
		}	
	}
	return (aux);
}
char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_strchr_gnl(aux, '\n'))
		aux = read_line(fd, aux);
	if (aux[0] == '\0' || aux == NULL)
	{
		free(aux);
		return (NULL);
	}
	else
	{
		line = save_line(aux);
		aux = auxupdater(aux);
		return (line);
	}
}
