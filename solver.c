/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/17 01:39:28 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:16:22 by chgaroux    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			trial(t_piece *tetro, uint64_t *map)
{
	int	i;

	i = 0;
	if (tetro)
	{
		while (i < 4)
		{
			if ((map[tetro->downo + i]) & tetro->tetri[i])
				return (0);
			i++;
		}
	}
	place_piece(map, tetro);
	return (1);
}

int			solver(t_piece *tetro, uint64_t *map, int dim)
{
	if (tetro == NULL)
		return (1);
	if (tetro->downo >= dim)
		return (0);
	if (trial(tetro, map))
	{
		if (solver(tetro->next, map, dim))
			return (1);
		else
		{
			remove_piece(map, tetro);
			reset_pieces(tetro->next);
		}
	}
	if (solver(shift_tetro(tetro, dim), map, dim))
		return (1);
	return (0);
}

int			fillit(t_piece *start, int dim, uint64_t *map, int print_color)
{
	map = reset_map(map, dim);
	if (solver(start, map, dim) == 1)
	{
		if (print_color)
			print_fillit_colored(start, dim);
		else
			print_fillit(start, dim);
		return (1);
	}
	reset_pieces(start);
	fillit(start, dim + 1, map, print_color);
	return (0);
}
