/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hk <hk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:52:14 by xjose             #+#    #+#             */
/*   Updated: 2024/07/25 11:50:44 by hk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	//int fd2;
	char *tmp;
	size_t i;

	i = 0;
	fd = open("./text", 0);
	// fd2 = open("./text2", 0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break;
		printf("%s", tmp);
		free(tmp);
		i++;
	}
	return (0);
}
