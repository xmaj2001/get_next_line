/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:52:14 by xjose             #+#    #+#             */
/*   Updated: 2024/07/09 15:07:09 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	size_t	i;

	i = 0;
	fd = open("./text", 0);
	fd2 = open("./text2", 0);
	while (i < 3)
	{
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
		i++;
	}
	return (0);
}
