/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:29:21 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 19:03:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void get_cmd(int ac, char **av, t_pipex *p)
{
    int i;
    char *path;
    char **arg;
    
    i = 2;
    while (av[i] && (i < ac - 1))
    {
        arg = ft_split(av[i], ' '); 
        path = ft_strdup(get_path(arg[0], p->env));
        ft_cmd_add_back(&(p->cmd), ft_cmd_new(path, arg));
        i++;
    }
}

void setup_red(t_pipex *p)
{
    if (!p->cmd->prev)
        p->cmd->in = open(p->fin, O_RDONLY, S_IRWXU);
    if (!p->cmd->next)
        p->cmd->out = open(p->fout, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (p->cmd->in < 0 || p->cmd->out< 0)
    {
        perror("Error");
        exit(1);
    }
    if (p->cmd->in)
        dup2(p->cmd->in, 0);
    if (p->cmd->out)
        dup2(p->cmd->out, 1);
}

void execute(t_pipex *p)
{
    t_cmd *cmd;

    cmd = p->cmd;
    while (cmd)
    {
        if ((p->pid = fork()) == -1)
        {
            perror("Error");
            exit(1);
        }
        if (!p->pid)
        {
            setup_pipe(cmd);
            setup_red(p);
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