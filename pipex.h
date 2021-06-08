/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:46 by mac               #+#    #+#             */
/*   Updated: 2021/06/08 00:47:20 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <errno.h>

typedef struct s_cmd
{
    char *path;
    char **arg;
    int pipe[2];
    int in;
    int out;
    struct s_cmd *next;
    struct s_cmd *prev;
} t_cmd;

typedef struct s_pipex
{
    char **env;
    t_cmd *cmd;
    pid_t pid;
    int fin;
    int fout;
} t_pipex;


void get_cmd(char **av, t_pipex *p);






void	ft_putendl_fd(char *s, int fd);

#endif