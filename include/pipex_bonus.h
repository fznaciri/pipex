/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:19:46 by mac               #+#    #+#             */
/*   Updated: 2021/06/12 14:30:28 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define BUFFER_SIZE 32

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_cmd
{
	char	*path;
	char	**arg;
	int		pipe[2];
}			t_cmd;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct s_pipex
{
	char		**env;
	t_list		*cmd;
	pid_t		pid;
	char		*fout;
	char		*stop;
	int			in;
	int			out;
	int			p_in[2];
	int			status;
}			t_pipex;

void			get_cmd(int ac, char **av, t_pipex *p);
char			*ft_getenv(char *name, char **env);
char			*get_path(char *bin, char **env);
void			open_pipe(t_list *cmd);
void			close_pipe(t_list *cmd);
void			setup_pipe(t_list *cmd);
void			setup_red(t_pipex *p, t_list *cmd);
void			execute_bonus(t_pipex *p);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(const char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *data);
void			ft_delete_arg(char **arg);
int				gnl(int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strndup(const char *s1, size_t n);
void			set_in(t_pipex *p);
int				ft_strcmp(const char *s1, const char *s2);

#endif
