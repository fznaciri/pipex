/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:16:01 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/06/12 15:07:48 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	get_cmd(int ac, char **av, t_pipex *p)
{
	int		i;
	char	*path;
	char	**arg;
	t_cmd	*cmd;

	i = 2;
	while (av[i] && (i < ac - 1))
	{
		cmd = malloc(sizeof(t_cmd));
		cmd->arg = ft_split(av[i], ' ');
		cmd->path = get_path(cmd->arg[0], p->env);
		ft_lstadd_back(&(p->cmd), ft_lstnew(cmd));
		i++;
	}
}

void	setup_red(t_pipex *p, t_list *cmd)
{
	if (!cmd->prev)
	{
		dup2(p->p_in[0], 0);
		close(p->p_in[0]);
		close(p->p_in[1]);
	}
	if (!cmd->next)
		p->out = open(p->fout, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (p->out < 0)
	{
		perror("Error");
		exit(1);
	}
	if (!cmd->next && p->out)
		dup2(p->out, 1);
}

static void	check_error(void)
{
	perror("Error");
	exit(127);
}

static void	close_in(t_pipex *p, t_list *cmd)
{
	if (!cmd->prev)
	{
		close(1);
		close(p->p_in[1]);
		close(p->p_in[0]);
	}
}

void	execute_bonus(t_pipex *p)
{
	t_list	*cmd;

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
			if (execve(((t_cmd *)cmd->data)->path,
					((t_cmd *)cmd->data)->arg, p->env))
				check_error();
		}
		close(((t_cmd *)cmd->data)->pipe[1]);
		if (cmd->prev)
			close(((t_cmd *)cmd->prev->data)->pipe[0]);
		close_in(p, cmd);
		cmd = cmd->next;
	}
}
