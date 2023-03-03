/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:23:45 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/01 07:05:46 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	leaks(void)
{
	system("leaks -q --list a.out");
}

int	main(void)
{
	int		fd;
	int		counter;
	char	*filename;
	char	*line;

	counter = 0;
	filename = "file.txt";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("ERROR\n"), -1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("################\n");
		printf("%s", line);
		printf("################\n");
		free(line);
		line = get_next_line(fd);
		counter++;
	}
	close(fd);
	free(line);
	atexit(leaks);
}
