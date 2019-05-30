/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manimap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:31:00 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 12:39:35 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

uint64_t	get_tzone(int dim)
{
	uint64_t	tzone;

	tzone = ft_power(2, dim) - 1;
	tzone <<= (64 - dim);
	return (~tzone);
}

uint64_t	*reset_map(uint64_t *map, int dim)
{
	int			i;
	uint64_t	tzone;

	i = 0;
	tzone = get_tzone(dim);
	while (i < 32)
	{
		map[i] = 0;
		if (i < dim)
			map[i] = tzone;
		else if (i >= dim)
			map[i] = ~0;
		i++;
	}
	return (map);
}

void		remove_piece(uint64_t *map, t_piece *tetro)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[tetro->downo + i] ^= tetro->tetri[i];
		i++;
	}
}

void		place_piece(uint64_t *map, t_piece *tetro)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[tetro->downo + i] |= tetro->tetri[i];
		i++;
	}
}
