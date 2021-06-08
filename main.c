/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:16:59 by mac               #+#    #+#             */
/*   Updated: 2021/06/08 00:58:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **env)
{
    t_pipex *p;
    
    if (ac != 5)
    {
        ft_putendl_fd(": usage: ./pipex file1 cmd1 cmd2 file2", 2);
        exit(1);
    }
    p->cmd = NULL;
    p->fin = av[1];
    p->fout = av[ac - 1];
    get_cmd(av, p);
    open_pipe(p->cmd);
    execute(p->cmd);
    close_pipe(p->cmd);
	waitpid(p->pid, 0, 0);
	while (wait(NULL) > 0)
		;
    return (0);
}