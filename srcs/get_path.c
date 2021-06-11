/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:42:28 by mac               #+#    #+#             */
/*   Updated: 2021/06/11 19:16:50 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char *ft_getenv(char *name, char **env)
{
    int i;
    int j;
    int l;

    i = 0;
    l = ft_strlen(name);
    while (env[i])
    {
        j = 0;
        while (j <= l)
        {
            if (env[i][j] != name[j])
                break ;
            j++;
            if (env[i][j] == '=' && j == l)
                return (env[i] + j + 1);   
        }
        i++;  
    }
    return (NULL);
}


char    *get_path(char *s, char **env)
{
    char **path;
    char *tmp;
    char *f_path;
    int i;

    i = 0;
    
    path = ft_split(ft_getenv("PATH", env), ':');
    while (path[i])
    {
        f_path = ft_strjoin(path[i], "/");
        tmp = f_path;
        f_path = ft_strjoin(tmp, s);
        free(tmp);
        if (open(f_path, O_RDONLY) > 0)
        {
            ft_delete_arg(path);
            
            return f_path;
        }
        free(f_path);
        i++;
    }
    return (s);
}