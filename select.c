/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:16:27 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/12 18:29:51 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	init_terminal_data ()
{
	char 	*termtype = getenv("TERM");
	int		success;
	char	*term_buffer;

	term_buffer = (char*)malloc(sizeof(char) * 9999);
	if (termtype == 0)
		ft_printf("Specify a terminal type with `setenv TERM <yourtype>'.\n");
	if ((success = tgetent (term_buffer, termtype)) <= 0)
	{
		if (success < 0)
			ft_printf("Could not access the termcap data base.\n");
		if (success == 0)
			ft_printf("Terminal type `%s' is not defined.\n", termtype);
		exit(0);
	}
}

void	ft_select(int i)
{
	static struct termios	*term;
	struct termios			cpy;

	if (i == 8)
		term = NULL;
	if (term == NULL)
	{
		init_terminal_data();
		ft_signal();
		term = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(STDIN_FILENO, term);
		cpy = *term;
		cpy.c_lflag &= ~(ICANON|ECHO);
		cpy.c_lflag &= ISIG;
		cpy.c_cc[VMIN] = 1;
		cpy.c_cc[VTIME] = 1;
		tcsetattr(STDIN_FILENO, TCSANOW, &cpy);
		soul("vi");
	}
	else
	{
		soul("ve");
		tcsetattr(STDIN_FILENO, TCSANOW, term);
		exit(0);
	}
}

char	*soul(char *str)
{
	char	*ch;

	ch = tgetstr(str, NULL);
	if (ch)
		ft_printf("%s", ch);
	return (ch);
}
