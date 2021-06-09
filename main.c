/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:16:59 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 19:03:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

void print_arg(char **arg)
{
    int i;

    i = 0;
    while(arg[i] && arg)
    {
        printf("arg[%d] |%s|\n",i, arg[i]);
        i++;
    }
}

void    print_cmd(t_cmd *cmd)
{
    t_cmd *tmp = cmd;
    
	if (!tmp)
		printf("NULL\n");
	while (tmp)
	{
		printf("cmd %s\n", tmp->path);
        print_arg(tmp->arg);
		tmp = tmp->next;
	}
}

int main(int ac, char **av, char **env)
{
    t_pipex *p;
    
    if(!(p = malloc(sizeof(t_pipex))))
        return 1;
    if (ac != 5)
    {
        ft_putendl_fd(": usage: ./pipex file1 cmd1 cmd2 file2", 2);
        exit(1);
    }
    p->env = env;
    p->cmd = NULL;
    p->fin = av[1];
    p->fout = av[ac - 1];
    get_cmd(ac, av, p);
    // print_cmd(p->cmd);
    open_pipe(p->cmd);
    execute(p);
    close_pipe(p->cmd);
	waitpid(p->pid, 0, 0);
	while (wait(NULL) > 0)
		;
    return (0);
}