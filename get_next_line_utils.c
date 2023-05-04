/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:46:41 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/03 19:28:52 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{	
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *aux, char *buffer)
{
	int		lencaja;
	char	*caja;
	size_t	i;
	size_t	j;

	lencaja = ft_strlen_gnl(aux) + ft_strlen_gnl(buffer);
	caja = malloc((lencaja + 1) * sizeof(char));
	if (!caja)
		return (NULL);
	i = 0;
	if (aux && aux[0] != '\0')
	{
		while (aux[i] != '\0')
		{
			caja[i] = aux[i];
			i++;
		}
	}
	j = 0;
	if (buffer)
	{
		while (buffer[j])
			caja[i++] = buffer[j++];
		caja[i] = '\0';
	}
	if (buffer == NULL)
	{
		free(caja);
		return (NULL);
	}
	return (caja);
}
