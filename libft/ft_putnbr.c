/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:34:09 by lsirigna          #+#    #+#             */
/*   Updated: 2013/11/21 18:47:32 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	rev;

	rev = 0;
	if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	while (n > 0)
	{
		rev = rev * 10;
		rev = rev + (n % 10);
		n = n / 10;
	}
	while (rev > 0)
	{
		n = rev % 10;
		ft_putchar(n + 48);
		rev = rev / 10;
	}
}
