/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 18:39:29 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 16:02:27 by chgaroux    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_arg(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 3 &&
				(ft_strcmp(av[1], "--color") == 0
				|| ft_strcmp(av[1], "-c") == 0))
		{
			return (1);
		}
		write(2, "usage: ./fillit [-c] file\n", 26);
		exit(0);
	}
	return (0);
}

void		fill_list(t_piece *tetro, char *buf)
{
	while (tetro)
	{
		str_to_bits(tetro, buf);
		tetro = tetro->next;
	}
}

void		free_list(t_piece *tetro)
{
	t_piece *tmp;

	while (tetro)
	{
		tmp = tetro;
		tetro = tetro->next;
		free(tmp);
	}
}

int			main(int ac, char **av)
{
	int			npiece;
	int			fd;
	uint64_t	*map;
	t_piece		*tetro;
	int			print_color;

	print_color = valid_arg(ac, av);
	if ((print_color == 0 && (fd = open(av[1], O_RDONLY)) == -1)
			|| (print_color == 1 && (fd = open(av[2], O_RDONLY)) == -1))
		print_error(NULL);
	if (!(tetro = (t_piece *)malloc(sizeof(t_piece))))
		return (-1);
	init_link(tetro);
	if (!(npiece = parse_file(fd, tetro, 0)))
		print_error(tetro);
	if (!(map = (uint64_t *)malloc(sizeof(uint64_t) * 32)))
	{
		free_list(tetro);
		return (-1);
	}
	map = reset_map(map, (ft_sqrt(npiece * 4) - 1));
	fillit(tetro, (ft_sqrt(npiece * 4) - 1), map, print_color);
	free(map);
	free_list(tetro);
	return (0);
}
