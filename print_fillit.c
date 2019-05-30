/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_fillit.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 10:19:13 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:16:57 by chgaroux    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		set_canvas(char **output, int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		if (!(output[i] = (char *)malloc(sizeof(char) * (dim + 1))))
			return (-1);
		while (j < dim)
		{
			output[i][j] = '.';
			j++;
		}
		output[i][dim] = '\0';
		i++;
	}
	return (0);
}

void	fill_canvas(char **output, t_piece *tetro, int letter)
{
	int i;
	int j;
	int shift;

	while (tetro)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			shift = 64;
			while (shift > 0)
			{
				if (((tetro->tetri[i] >> --shift) & 1))
					output[i + tetro->downo][j] = letter;
				j++;
			}
			i++;
		}
		tetro = tetro->next;
		letter++;
	}
}

void	print_fillit(t_piece *tetro, int dim)
{
	int		i;
	char	**output;

	if (!(output = (char **)malloc(sizeof(char *) * dim)))
		return ;
	set_canvas(output, dim);
	fill_canvas(output, tetro, 65);
	i = 0;
	while (i < dim)
	{
		ft_putendl(output[i]);
		i++;
	}
	while (i--)
		free(output[i]);
	free(output);
}
