/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:16:59 by mac               #+#    #+#             */
/*   Updated: 2021/06/12 14:07:48 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*p;

	p = malloc(sizeof(t_pipex));
	if (!p)
		return (1);
	if (ac != 5)
	{
		ft_putendl_fd(": usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	p->env = env;
	p->cmd = NULL;
	p->fin = av[1];
	p->fout = av[ac - 1];
	p->in = 0;
	p->out = 0;
	get_cmd(ac, av, p);
	open_pipe(p->cmd);
	execute(p);
	close_pipe(p->cmd);
	waitpid(p->pid, &(p->status), 0);
	p->status = WEXITSTATUS(p->status);
	while (wait(NULL) > 0)
		;
	return (p->status);
}
