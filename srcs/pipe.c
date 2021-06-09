/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:29:38 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 17:46:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void open_pipe(t_cmd *cmd)
{
    t_cmd *tmp;
    
    tmp = cmd;
    while (tmp)
    {
        if (tmp->next)
            pipe(tmp->pipe);
        tmp = tmp->next;
    }
}

void close_pipe(t_cmd *cmd)
{
    t_cmd *tmp;
    
    tmp = cmd;
    while (tmp)
    {
        if (tmp->next)
        {
            close(tmp->pipe[0]);
            close(tmp->pipe[1]);
        }
        tmp = tmp->next;
    }
}

void    setup_pipe(t_cmd *cmd)
{
    if (cmd->next)
        dup2(cmd->pipe[1], 1);
    if (cmd->prev)
        dup2(cmd->prev->pipe[0], 0);
}