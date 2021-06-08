/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:37:49 by mac               #+#    #+#             */
/*   Updated: 2021/06/08 00:55:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_cmd(char **av, t_pipex *p)
{
    int i;
    t_cmd *cmd;
    
    i = 2;
    while (av[i])
    {
        cmd->arg = ft_split(av[i], " "); 
        cmd->path = get_path(cmd->arg[0], p->env);
        cmd->pipe[0] = -1;
        cmd->pipe[1] = -1;
        ft_cmd_add_back(&(p->cmd), cmd);
        i++;
    }
}

void open_pipe(t_pipex *p)
{
    t_cmd *tmp;
    
    tmp = p->cmd;
    while (tmp)
    {
        if (tmp->next)
            pipe(tmp->pipe);
        tmp = tmp->next;
    }
}

void close_pipe(t_pipex *p)
{
    t_cmd *tmp;
    
    tmp = p->cmd;
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

void execute(t_pipex *p)
{
    t_cmd *cmd;

    cmd = p->cmd;
    while (cmd)
    {
        if (p->pid = fork() == -1)
        {
            perror("Error");
            exit(1);
        }
        if (!p->pid)
        {
            if (!cmd->prev)
                cmd->in = open(p->fin, O_RDONLY, S_IRWXU);
            if (!cmd->next)
                cmd->out = open(p->fout, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
            if (cmd->in < 0 || cmd->out< 0)
            {
                perror("Error");
                exit(1);
            }
            if (cmd->in)
                dup2(cmd->in, 0);
            if (cmd->out)
                 dup2(cmd->out, 1);
            if (execve(cmd->path, cmd->arg , p->env))
            {
                perror("Error");
                exit(1);
            }
        }
        close(cmd->pipe[1]);
        if (cmd->prev)
            close(cmd->pipe[0]);
        cmd = cmd->next;
    }
}