/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:40 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/30 20:26:01 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*auxupdater(char *aux)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	temp = malloc((ft_strlen_gnl(aux) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (aux[i])
	{
		temp[i] = aux[i];
		i++;
	}
	free(aux);
	j = -1;
	while (temp[++j] != '\n' && temp[j]);
	aux = malloc(sizeof(char) * (i - j + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while(temp[j])
		aux[i++] = temp[j++];
	aux[i] = '\0';
	free(temp);
	return (aux);
}

char	*save_line(char *aux)
{
	size_t	i;
	char 	*line;

	i = 0;
	if (aux == NULL)
		return (NULL);
	while (aux[i++] != '\n' && aux[i]);
	line = malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);	
	while (aux[i])
	{	
		if (aux[i] != '\n')
			line[i] = aux[i];
		else
		{
			line[i++] = '\n';
			line[i] = '\0';
			return (line);
		}
		i++;
	}
	return (line);
}

char	*read_line(int fd, char *aux)
{
	char	*buffer;
	int	i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
	while (!ft_strchr_gnl(buffer, '\n') && i > 0)
	{	
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		aux = ft_strjoin_gnl(aux, buffer);
		if (aux == NULL)
		{	
			free (aux);
			free (buffer);
			return (NULL);
		}
		free (buffer);
	}
		return (aux);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		aux = read_line(fd, aux);
	if (aux == NULL)
	{
		free(aux);
		return (NULL);
	}
	else
	{
		line = save_line(aux);
		aux = auxupdater(aux);
		free(aux);
		return (line);
	}
}
