/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                                                                                                      +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:21:36 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/26 17:21:39 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
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
	char	*caja;
	int		len1y2;
	int		i;
	int		j;

	len1y2 = ft_strlen_gnl(aux) + ft_strlen_gnl(buffer) + 1;
	caja = malloc((len1y2) * sizeof(char));
	if (!caja)
		return (NULL);
	i = 0;
	if (aux)
	{
		while (aux[i++])
			caja[i] = aux[i];
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
