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

t_list	*ft_lstnew(int key, void *content)
{
	t_list	*lst;

	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lst->key = key;
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	get_next_line(int fd, char **line)
{
	char            r_tmp[BUFFER_SIZE + 1];
	static t_list   *rms;
	int             res_read;
	char            *start;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	start = NULL;
	*line = ft_strdup("");
	if(rms->content)
		*line = ft_strjoin(*line, rms->content);
	while(!start && (res_read = read(fd, r_tmp, BUFFER_SIZE)))
	{
		r_tmp[res_read] = '\0';
		if((start = ft_strchr(r_tmp, '\n')))
		{
			*start = '\0';
			rms = ft_lstnew(fd, ft_strdup(start + 1));
		}
		*line = ft_strjoin(*line, r_tmp);
	}
	return (0);
}