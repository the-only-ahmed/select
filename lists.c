/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:17:11 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/12 08:17:12 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static t_lst	*create_list(char *str, int ac, t_lst *tmp2)
{
	t_lst	*tmp;
	struct winsize	win_struct;

	if (tmp2)
		tmp = (t_lst*)malloc(sizeof(t_lst));
	else
		tmp = get_instance();
	tmp->str = ft_strdup(str);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->deb = NULL;
	tmp->selected = 0;
	tmp->pointed = 0;
	tmp->ac = ac - 1;
	ioctl(0, TIOCGWINSZ, &win_struct);
	tmp->max_line = win_struct.ws_row;
	tmp->max_column = win_struct.ws_col;
	return (tmp);
}

static t_lst	*init(t_lst *tmp)
{
	t_lst	*tmp2;

	tmp2 = tmp;
	tmp2->deb = tmp;
	tmp2->pointed = 1;
	return (tmp2);
}

t_lst			*assign(int ac, char **av)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;

	i = 1;
	tmp2 = NULL;
	while (i < ac)
	{
		tmp = create_list(av[i], ac, tmp2);
		if (!tmp2)
			tmp2 = init(tmp);
		else
		{
			tmp2->next = tmp;
			tmp2->next->prev = tmp2;
			tmp->deb = tmp2->deb;
			tmp2 = tmp2->next;
		}
		i++;
		if (i < ac)
			tmp = tmp->next;
	}
	tmp->deb->prev = tmp;
	tmp->next = tmp->deb;
	return (tmp->deb);
}

static t_lst	*change_deb(t_lst *option)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	if (option == option->deb)
	{
		tmp = option->next;
		while (i < option->ac)
		{
			option->deb = tmp;
			option = option->next;
			i++;
		}
	}
	return (option->deb);
}

t_lst			*delete_arg(t_lst *option)
{
	t_lst	*tmp;

	tmp = option;
	change_deb(option);
	diminue(&option);
	if (tmp->next == tmp->deb && tmp->prev != tmp->deb)
	{
		option = tmp->prev;
		tmp->prev->pointed = 1;
	}
	else
	{
		option = tmp->next;
		tmp->next->pointed = 1;
	}
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp = NULL;
	free(tmp);
	if (option->ac == 0)
		leave();
	return (option);
}
