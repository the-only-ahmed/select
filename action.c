/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 23:39:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/06 23:40:09 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_lst	*get_instance()
{
	static t_lst	*tmp = NULL;

	if (!tmp)
	{
		tmp = (t_lst*)malloc(sizeof(t_lst));
	}
	return (tmp);
}

void	leave()
{
	soul("cl");
	soul("ve");
	exit(0);
}

static void		touch(t_lst **option, char *line)
{
	if (POINTED)
	{
		(*option)->pointed = 0;
		(*option) = (*option)->next;
		(*option)->pointed = 1;
	}
	affiche(*option);
	if (line[0] == 27 && line[1] == 91 && line[2] == 65)
	{
		(*option)->pointed = 0;
		(*option) = (*option)->prev;
		(*option)->pointed = 1;
	}
	affiche(*option);
	if (DEL)
		(*option) = delete_arg(*option);
	affiche(*option);
}

void		work(t_lst *option)
{
	char	*line;

	affiche(option);
	line = (char*)malloc(4);
	while (read(0, line, 4))
	{
		if (line[0] == 10)
			break;
		if ((line[0] == 27 && line[1] == 0))
		{
			soul("ve");
			exit(0);
		}
		affiche(option);
		if (line[0] == 32)
		{
			if (option->selected)
				option->selected = 0;
			else
				option->selected = 1;
		}
		affiche(option);
		touch(&option, line);
		ft_bzero(line, 4);
	}
}
