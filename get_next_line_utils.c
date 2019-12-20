/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <amoujane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:41:01 by amoujane          #+#    #+#             */
/*   Updated: 2019/12/19 18:41:07 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (i <= len)
		{
			str[i] = s1[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*r;
	char	*p;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(&s[start]);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	lens = (lens <= len) ? lens : len;
	str = (char*)malloc(sizeof(char) * (lens + 1));
	if (!str)
		return (NULL);
	r = str;
	p = (char*)(s + start);
	if (str)
	{
		while (lens-- && *p)
		{
			*(str++) = *(p++);
		}
		*str = '\0';
	}
	return (r);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	int		j;
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!str)
		return (NULL);
	while (++i < (int)ls1)
		str[i] = s1[i];
	j = 0;
	while (i < (int)(ls1 + ls2))
	{
		str[i++] = s2[j++];
	}
	str[ls1 + ls2] = '\0';
	return (str);
}

int			index_of(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
