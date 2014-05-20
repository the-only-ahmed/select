/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:15:17 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/12 08:15:19 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		print_spaces(t_lst *e)
{
	int		length;
	int		i;

	if (e->pointed == 1)
		soul("us");
	if (e->selected == 1)
		soul("mr");
	ft_printf("%s", e->str);
	soul("me");
	length = ft_strlen(e->str);
	i = ((e->max_column / 10) - length);
	while (i > 0)
	{
		ft_printf(" ");
		i--;
	}
}

static void		print_cols(t_lst *option)
{
	int		i;
	int		n;
	t_lst	*tmp;

	n = 0;
	while (n < option->max_line - 1)
	{
		i = n;
		tmp = option;
		while (i < option->ac)
		{
			if ((i == n) || (i % (n + option->max_line - 1) == 0))
				print_spaces(tmp);
			i++;
			tmp = tmp->next;
		}
		ft_printf("\n");
		option = option->next;
		n++;
	}
}

void	affiche(t_lst *option)
{
	int		i;

	i = 0;
	option = option->deb;
	soul("cl");
	if (option->ac <= option->max_line)
	{
		while (i < option->ac)
		{
			if (option->pointed == 1)
				soul("us");
			if (option->selected == 1)
				soul("mr");
			ft_printf("%s", option->str);
			soul("me");
			ft_printf("\n");
			option = option->next;
			i++;
		}
	}
	else
		print_cols(option);
}

void	print_choice(t_lst *option)
{
	int		i;

	i = 0;
	option = option->deb;
	soul("cl");
	while (i < option->ac)
	{
		if (option->selected == 1)
			ft_printf("%s ", option->str);
		option = option->next;
		i++;
	}
	ft_printf("\n");
}
