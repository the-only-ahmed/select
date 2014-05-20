/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:21:08 by lsirigna          #+#    #+#             */
/*   Updated: 2014/01/06 21:25:56 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	diminue(t_lst **option)
{
	int		i;
	int		length;
	t_lst	*tmp;

	i = 0;
	tmp = *option;
	length = tmp->ac;
	tmp = tmp->deb;
	while (i <= length)
	{
		tmp->ac = length - 1;
		tmp = tmp->next;
		i++;
	}
}

static void		ft_ser(int c)
{
	if (c == 28)
		soul("cl");
	if (c == 28 || 24)
		ft_select(8);
}

static void		resize()
{
	t_lst			*option;
	struct winsize	win_struct;

	option = ((t_lst *)get_instance());
	ioctl(0, TIOCGWINSZ, &win_struct);
	option->max_line = win_struct.ws_row;
	option->max_column = win_struct.ws_col;
	affiche(option);
}

void		ft_signal()
{
	signal(SIGCONT, ft_ser);
	signal(SIGWINCH, resize);
}
