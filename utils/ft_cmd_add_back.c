/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:06:24 by mac               #+#    #+#             */
/*   Updated: 2021/06/09 17:06:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_cmd_add_back(t_cmd **alst, t_cmd *new)
{
	t_cmd *tmp;

	tmp = *alst;
	if (tmp)
	{
		tmp = ft_cmd_last(tmp);
		tmp->next = new;
		new->prev = tmp;
	}
	else
		*alst = new;
}