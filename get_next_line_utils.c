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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == (char)c)
				return (&s[i]);	
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*caja;
	size_t	len1y2;

	len1y2 = ft_strlen(s1) + ft_strlen(s2) + 1;
	caja = malloc((len1y2) * sizeof(char));
	if (!caja)
		return (NULL);
	ft_strlcpy((char *)caja, s1, len1y2);
	ft_strlcat((char *)caja, s2, len1y2);
	if (!caja)
	{
		return (NULL);
		free (caja);
	}
	else
	{
		caja[len1y2 - 1] = '\0';
		return (caja);
	}
free (caja);
return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	id;
	size_t	is;
	size_t	len;

	len = ft_strlen(dst);
	id = 0;
	is = 0;
	while (dst[id] != '\0')
			id++;
	if (dstsize != 0 && dstsize >= len)
	{
		while (src[is] && is + 1 < dstsize - len)
		{
			dst[id] = src[is];
			id++;
			is++;
		}
		dst[id] = '\0';
		return (len + ft_strlen(src));
	}	
	else
		return (dstsize + ft_strlen(src));
}