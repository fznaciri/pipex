/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_in_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:07:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/12 15:08:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	set_in(t_pipex *p)
{
	char	*line;

	pipe(p->p_in);
	dup2(p->p_in[1], 1);
	write(2, "> ", 2);
	while (gnl(0, &line))
	{
		if (!ft_strcmp(line, p->stop))
			break ;
		ft_putendl_fd(line, 1);
		write(2, "> ", 2);
		free(line);
	}
	free(line);
}
