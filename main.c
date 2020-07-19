/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <gdougal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:30:56 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/19 17:11:31 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	char *line;
	int fd = open("file", O_RDONLY);
	 get_next_line(fd, &line);
	 printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return 0;
}