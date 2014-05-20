/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:56:27 by lsirigna          #+#    #+#             */
/*   Updated: 2013/12/29 20:51:55 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		j++;
	copy = (char*)malloc(sizeof(char) * (j + 1));
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (i <= j)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
