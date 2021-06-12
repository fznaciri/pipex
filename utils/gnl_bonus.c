/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:46:58 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/12 14:47:08 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_checkerror(int fd, char **buff)
{
	if (!(BUFFER_SIZE >= 1) || (read(fd, *buff, 0) < 0))
		return (NULL);
	return (*buff);
}

int	ft_readline(int fd, char **str)
{
	char	*tmp;
	char	*buff;
	int		n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || (!ft_checkerror(fd, &buff)))
	{
		free(buff);
		return (-1);
	}
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		buff[n] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buff);
	return (n);
}

static void	newline_found(char **line, char **str, char **s)
{
	char	*tmp;

	*line = ft_strndup(*str, *s - *str);
	tmp = *str;
	*str = ft_strdup(*s + 1);
	free(tmp);
}

int	gnl(int fd, char **line)
{
	static char	*str;
	char		*s;
	int			n;

	n = ft_readline(fd, &str);
	if ((n < 0) || !line)
		return (-1);
	s = ft_strchr(str, '\n');
	if (s)
	{
		newline_found(line, &str, &s);
		return (1);
	}
	if (!n && str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
