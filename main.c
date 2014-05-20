/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:56:52 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/10 02:07:20 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		main(int ac, char **av)
{
	t_lst	*option;

	if (ac == 1)
		return (0);
	option = assign(ac, av);
	affiche(option);
	ft_select(0);
	work(option);
	print_choice(option);
	ft_select(0);
	return (0);
}
