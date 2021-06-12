/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:29:38 by mac               #+#    #+#             */
/*   Updated: 2021/06/12 15:09:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_pipe(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->next)
			pipe(((t_cmd *)tmp->data)->pipe);
		tmp = tmp->next;
	}
}

void	close_pipe(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->next)
		{
			close(((t_cmd *)tmp->data)->pipe[0]);
			close(((t_cmd *)tmp->data)->pipe[1]);
		}
		tmp = tmp->next;
	}
}

void	setup_pipe(t_list *cmd)
{
	if (cmd->next)
	{
		dup2(((t_cmd *)cmd->data)->pipe[1], 1);
		close(((t_cmd *)cmd->data)->pipe[1]);
		close(((t_cmd *)cmd->data)->pipe[0]);
	}
	if (cmd->prev)
	{
		dup2(((t_cmd *)cmd->prev->data)->pipe[0], 0);
		close(((t_cmd *)cmd->prev->data)->pipe[0]);
		close(((t_cmd *)cmd->prev->data)->pipe[1]);
	}
}
