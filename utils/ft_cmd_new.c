/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:33:52 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 18:39:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_cmd	*ft_cmd_new(char *path, char **arg)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	new->path = path;
    new->arg = arg;
    new->pipe[0] = -1;
    new->pipe[1] = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}