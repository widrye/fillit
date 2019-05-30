/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_to_bits.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 19:42:05 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 17:03:48 by chgaroux    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		split_2d(t_piece *tetro)
{
	tetro->tetri[0] = tetro->b_piece & 0xf000;
	tetro->tetri[0] <<= 48;
	tetro->tetri[1] = tetro->b_piece & 0x0f00;
	tetro->tetri[1] <<= 52;
	tetro->tetri[2] = tetro->b_piece & 0x00f0;
	tetro->tetri[2] <<= 56;
	tetro->tetri[3] = tetro->b_piece & 0x000f;
	tetro->tetri[3] <<= 60;
}

uint16_t	topleft(uint16_t piece)
{
	if (!(piece & 0xfff0))
		piece <<= 12;
	else if (!(piece & 0xff00))
		piece <<= 8;
	else if (!(piece & 0xf000))
		piece <<= 4;
	if (!(piece & 0xeeee))
		piece <<= 3;
	else if (!(piece & 0xcccc))
		piece <<= 2;
	else if (!(piece & 0x8888))
		piece <<= 1;
	return (piece);
}

void		str_to_bits(t_piece *tetro, char *piece)
{
	int i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] != '\n')
			tetro->b_piece <<= 1;
		if (piece[i] == '#')
			tetro->b_piece |= 1;
		i++;
	}
	tetro->b_piece = topleft(tetro->b_piece);
	split_2d(tetro);
}
