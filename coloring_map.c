/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coloring_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chgaroux <chgaroux@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/29 13:58:58 by chgaroux     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 16:13:55 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void	print_colored_char(char c, char *color)
{
	ft_putstr(color);
	ft_putchar(c);
	ft_putchar(' ');
	ft_putstr(INIT);
}

static void	print_color(char *s)
{
	while (*s)
	{
		if (*s == 'A' || *s == 'F' || *s == 'K' || *s == 'P' || *s == 'U' ||
				*s == 'Z')
			print_colored_char(*s, RED);
		else if (*s == 'B' || *s == 'G' || *s == 'L' || *s == 'Q' || *s == 'V')
			print_colored_char(*s, GREEN);
		else if (*s == 'C' || *s == 'H' || *s == 'M' || *s == 'R' || *s == 'W')
			print_colored_char(*s, BLUE);
		else if (*s == 'D' || *s == 'I' || *s == 'N' || *s == 'S' || *s == 'Y')
			print_colored_char(*s, YELLOW);
		else if (*s != '\n')
			print_colored_char(*s, NULL);
		else
			ft_putchar('\n');
		s++;
	}
	ft_putchar('\n');
}

void		print_fillit_colored(t_piece *tetro, int dim)
{
	int		i;
	char	**canvas;

	i = 0;
	if (!(canvas = (char **)malloc(sizeof(char *) * dim)))
		return ;
	if (set_canvas(canvas, dim) == -1)
		return ;
	fill_canvas(canvas, tetro, 'A');
	while (i < dim)
	{
		print_color(canvas[i]);
		i++;
	}
	while (i--)
		free(canvas[i]);
	free(canvas);
}
