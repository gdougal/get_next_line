/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <gdougal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:30:51 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/19 11:32:16 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*tail(char **line, char **rms)
{
	char			*tmp;
	char			*start;

	start = NULL;
	if (*rms)
	{
		if ((start = ft_strchr(*rms, '\n')))
		{
			*start = '\0';
			*line = ft_strdup(*rms);
			tmp = *rms;
			*rms = ft_strdup(start + 1);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*rms);
			free(*rms);
			*rms = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (start);
}

int					get_next_line(int fd, char **line)
{
	char			r_tmp[BUFFER_SIZE + 1];
	static char		*rms;
	int				res_read;
	char			*start;
	char			*tmp;

	if (read(fd, r_tmp, 0) < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	start = tail(line, &rms);
	while(!start && (res_read = read(fd, r_tmp, BUFFER_SIZE)))
	{
		r_tmp[res_read] = '\0';
		if((start = ft_strchr(r_tmp, '\n')))
		{
			*start = '\0';
			rms = ft_strdup(start + 1);
		}
		tmp = *line;
		*line = ft_strjoin(*line, r_tmp);
		free(tmp);
	}
	return (res_read || rms ? 1 : 0);
}