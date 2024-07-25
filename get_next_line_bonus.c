/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hk <hk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 01:43:31 by xjose             #+#    #+#             */
/*   Updated: 2024/07/25 12:44:27 by hk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_new_buffer(char *buffer, int fd)
{
	char *tmp_buffer;
	int rz;

	rz = 0;
	tmp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rz < BUFFER_SIZE + 1)
		tmp_buffer[rz++] = '\0';
	rz = 1;
	while (!ft_strchr(tmp_buffer, '\n') && rz != 0)
	{
		rz = read(fd, tmp_buffer, BUFFER_SIZE);
		if (rz < 0 || (rz == 0 && buffer == NULL))
		{
			free(tmp_buffer);
			return (NULL);
		}
		tmp_buffer[rz] = '\0';
		if (buffer == NULL)
			buffer = ft_strdup(tmp_buffer);
		else
			buffer = ft_strjoin(buffer, tmp_buffer);
	}
	free(tmp_buffer);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer[1024];
	char *the_line;
	char *rest_line;
	int i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = get_new_buffer(buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	i = 0;
	while (buffer[fd][i] != '\n' && buffer[fd][i])
		i++;
	if (buffer[fd][i] == '\n')
		i += 1;
	the_line = ft_substr(buffer[fd], 0, i);
	rest_line = ft_substr(buffer[fd], i, ft_strlen(buffer[fd]) - i);
	free(buffer[fd]);
	buffer[fd] = rest_line;
	return (the_line);
}
