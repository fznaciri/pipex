/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:46 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 19:01:59 by mac              ###   ########.fr       */
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
    char *fin;
    char *fout;
} t_pipex;


void get_cmd(int ac, char **av, t_pipex *p);
char *ft_getenv(char *name, char **env);
char	*get_path(char *bin, char **env);
void open_pipe(t_cmd *cmd);
void close_pipe(t_cmd *cmd);
void    setup_pipe(t_cmd *cmd);
void setup_red(t_pipex *p);
void execute(t_pipex *p);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_cmd_add_back(t_cmd **alst, t_cmd *new);
t_cmd		*ft_cmd_last(t_cmd *lst);
t_cmd	*ft_cmd_new(char *path, char **arg);

#endif