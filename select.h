/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:56:07 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/06 17:56:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include <libft.h>
# include <signal.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

# define DEL line[0] == 127 || (line[0] == 27 && line[1] == 91 && line[2] == 51\
				&& line[3] == 126)
# define POINTED (line[0] == 27 && line[1] == 91 && line[2] == 66)\
					|| (line[0] == 32 && (*option)->selected)

typedef struct		s_lst
{
	char			*str;
	struct s_lst	*next;
	struct s_lst	*prev;
	struct s_lst	*deb;
	int				selected;
	int				pointed;
	int				ac;
	int				max_line;
	int				max_column;
}					t_lst;

t_lst	*assign(int ac, char **av);
void	ft_signal();
void	init_terminal_data ();
void	ft_select(int i);
char	*soul(char *str);
void	affiche(t_lst *option);
void	work(t_lst *option);
t_lst	*delete_arg(t_lst *option);
void	print_choice(t_lst *option);
t_lst	*get_instance();
void	leave();
void	diminue(t_lst **option);

#endif /* SELECT_H */
