/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:29:21 by mac               #+#    #+#             */
/*   Updated: 2021/06/11 15:27:39 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <string.h>
#include <stdio.h>

void get_cmd(int ac, char **av, t_pipex *p)
{
    int i;
    char *path;
    char **arg;
    t_cmd *cmd;
    
    i = 2;
    while (av[i] && (i < ac - 1))
    {
        cmd = malloc(sizeof(t_cmd));
        cmd->arg = ft_split(av[i], ' '); 
        cmd->path = ft_strdup(get_path(cmd->arg[0], p->env));
        ft_lstadd_back(&(p->cmd), ft_lstnew(cmd));
        i++;
    }
}

void setup_red(t_pipex *p, t_list *cmd)
{
    if (!cmd->prev)
        p->in = open(p->fin, O_RDONLY, S_IRWXU);
    if (!cmd->next)
        p->out = open(p->fout, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (p->in < 0 || p->out< 0)
    {
        perror("Error");
        exit(1);
    }
    if (!cmd->prev && p->in)
        dup2(p->in, 0);
    if (!cmd->next && p->out)
        dup2(p->out, 1);
}

void execute(t_pipex *p)
{
    t_list *cmd;

    cmd = p->cmd;
    while (cmd)
    {
        p->pid = fork();
        if (p->pid < 0)
        {
            perror("Error");
            exit(1);
        }
        if (!p->pid)
        {
            setup_red(p, cmd);
            setup_pipe(cmd);
            if (execve(((t_cmd*)cmd->data)->path, ((t_cmd*)cmd->data)->arg , p->env))
            {
                perror("Error");
                exit(1);
            }
        }
        close(((t_cmd*)cmd->data)->pipe[1]);
        if (cmd->prev)
            close(((t_cmd*)cmd->prev->data)->pipe[0]);
        cmd = cmd->next;
    }
}