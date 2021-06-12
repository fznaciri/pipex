/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:16:59 by mac               #+#    #+#             */
/*   Updated: 2021/06/12 15:17:42 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*p;

	p = malloc(sizeof(t_pipex));
	if (!p)
		return (1);
	if (ac < 5)
	{
		ft_putendl_fd(": usage: ./pipex stop cmd1 cmd2 file2", 2);
		exit(1);
	}
	p->env = env;
	p->cmd = NULL;
	p->fout = av[ac - 1];
	p->stop = av[1];
	get_cmd(ac, av, p);
	set_in(p);
	open_pipe(p->cmd);
	execute_bonus(p);
	close_pipe(p->cmd);
	waitpid(p->pid, &(p->status), 0);
	p->status = WEXITSTATUS(p->status);
	while (wait(NULL) > 0)
		;
	return (p->status);
}
