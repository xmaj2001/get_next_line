/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:40:12 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 15:02:14 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	size_t	len;

	len = ft_strlen(s1);
	str_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_dup)
		return (NULL);
	len = -1;
	while (s1[++len])
		str_dup[len] = s1[len];
	str_dup[len] = '\0';
	return (str_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	idx;
	size_t	x;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (join == NULL)
		return (NULL);
	idx = -1;
	x = 0;
	if (s1)
		while (s1[++idx] != '\0')
			join[idx] = s1[idx];
	while (s2[x] != '\0')
		join[idx++] = s2[x++];
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (join);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	tmp_len;
	size_t	i;

	if (!s || !len)
		return (NULL);
	tmp_len = ft_strlen(s);
	if (start >= tmp_len)
		len = 0;
	if (len > tmp_len - start)
		len = tmp_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		++start;
		++i;
	}
	substr[i] = '\0';
	return (substr);
}
