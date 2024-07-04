/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:43:31 by xjose             #+#    #+#             */
/*   Updated: 2024/07/04 03:15:43 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd, char *buffer)
{
	char	tmp_buffer[BUFFER_SIZE + 1];
	int		read_size;

	read_size = 0;
	while (read_size < BUFFER_SIZE)
	{
		tmp_buffer[read_size] = '\0';
		read_size++;
	}
	read_size = 1;
	while (!ft_strchr(tmp_buffer, '\n') && read_size != 0)
	{
		read_size = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && buffer == NULL))
			return (NULL);
		tmp_buffer[read_size] = '\0';
		if (buffer == NULL)
			buffer = ft_strdup(tmp_buffer);
		else
			buffer = ft_strjoin(buffer, tmp_buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i += 1;
	line = ft_substr(buffer, 0, i);
	next_line = ft_substr(buffer, i, ft_strlen(buffer) - 1);
	free(buffer);
	buffer = next_line;
	return (line);
}
