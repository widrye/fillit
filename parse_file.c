/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 19:29:25 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 15:56:59 by chgaroux    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		print_error(t_piece *tetro)
{
	ft_putendl("error");
	if (tetro)
		free_list(tetro);
	exit(0);
}

int			valid_piece(char *s)
{
	int		i;
	int		n;
	int		nb_ct;

	i = 0;
	n = 0;
	nb_ct = 0;
	while (i <= 20)
	{
		if (s[i] && s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
		{
			nb_ct += (i > 0 && s[i - 1] == '#') + (i > 4 && s[i - 5] == '#') +
				(i < 19 && s[i + 1] == '#') +
				(i < 14 && s[i + 5] == '#');
			n++;
		}
		if (s[i] == '\n' && ((i + 1) % 5))
			return (0);
		i++;
	}
	if (n != 4 || (nb_ct < 6 || nb_ct > 8))
		return (0);
	return (1);
}

void		init_link(t_piece *tetro)
{
	int i;

	i = 0;
	tetro->righto = 0;
	tetro->downo = 0;
	tetro->b_piece = 0;
	while (i++ < 4)
		tetro->tetri[i] = 0;
	tetro->next = NULL;
}

int			parse_file(int fd, t_piece *tetro, int npiece)
{
	char	buf[21];
	int		len;
	int		len_at_end;

	len_at_end = 0;
	while (npiece++ < 26 && (len = read(fd, buf, 21)))
	{
		if ((len != 20 && len != 21) || (len == 21 && buf[20] != '\n'))
			return (0);
		buf[20] = '\0';
		if (!valid_piece(buf))
			return (0);
		len_at_end = len;
		if (tetro->b_piece)
		{
			if (!(tetro->next = (t_piece *)malloc(sizeof(t_piece))))
				return (-1);
			tetro = tetro->next;
			init_link(tetro);
		}
		fill_list(tetro, buf);
	}
	if (len_at_end > 20 || len_at_end == 0)
		return (0);
	return (npiece);
}
