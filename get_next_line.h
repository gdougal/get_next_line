/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdougal <gdougal@student.21-school.ru      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:24:37 by gdougal           #+#    #+#             */
/*   Updated: 2020/07/19 12:24:45 by gdougal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				key;
	void			*content;
	struct s_list	*next;
}					t_list;

int                 get_next_line(int fd, char **line);
char	            *ft_strchr(const char *s, int c);
size_t	            ft_strlen(const char *s);
char	            *ft_strjoin(char const *s1, char const *s2);
char                *ft_strdup(const char *s);

#endif
