/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:43:11 by lsirigna          #+#    #+#             */
/*   Updated: 2013/11/27 18:49:05 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	numb;
	int	ispos;

	numb = 0;
	i = 0;
	ispos = 1;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ispos = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		numb *= 10;
		numb += (str[i] - 48);
		i++;
	}
	return (numb *= ispos);
}
