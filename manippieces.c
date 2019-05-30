/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   manippieces.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:30:22 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 03:20:26 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*shift_left(t_piece *tetro, int b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetro->tetri[i] <<= b;
		i++;
	}
	tetro->righto -= b;
	return (tetro);
}

t_piece		*shift_right(t_piece *tetro, int b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetro->tetri[i] >>= b;
		i++;
	}
	tetro->righto += b;
	return (tetro);
}

t_piece		*shift_down(t_piece *tetro, int b)
{
	tetro = shift_left(tetro, tetro->righto);
	tetro->downo += b;
	return (tetro);
}

t_piece		*shift_tetro(t_piece *tetro, int dim)
{
	if (tetro->righto + 1 < dim)
		return (shift_right(tetro, 1));
	return (shift_down(tetro, 1));
}

void		reset_pieces(t_piece *tetro)
{
	while (tetro)
	{
		if (tetro->righto)
			tetro = shift_left(tetro, tetro->righto);
		tetro->downo = 0;
		tetro = tetro->next;
	}
}
