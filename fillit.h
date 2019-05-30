/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 18:45:47 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 16:12:37 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define INIT			"\033[0m"
# define RED			"\033[0;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define BLUE			"\033[0;34m"

typedef struct		s_piece
{
	int				righto;
	int				downo;
	uint16_t		b_piece;
	uint64_t		tetri[4];
	struct s_piece	*next;
}					t_piece;

int					fillit(t_piece *start, int min_dim, uint64_t *map,
						int print_color);

void				print_fillit_colored(t_piece *tetro, int dim);
void				free_list(t_piece *tetro);
void				fill_list(t_piece *tetro, char *buf);
void				print_error(t_piece *tetro);
void				print_fillit(t_piece *tetro, int dim);
int					ft_power(int n, int power);
void				ft_putchar(char c);
void				str_to_bits(t_piece *tetro, char *buf);
int					parse_file(int fd, t_piece *tetro, int npiece);
void				ft_putendl(const char *s);
void				ft_putstr(const char *str);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				place_piece(uint64_t *map, t_piece *tetro);
void				remove_piece(uint64_t *map, t_piece *tetro);
uint64_t			*reset_map(uint64_t *map, int dim);
void				init_link(t_piece *tetro);
void				reset_pieces(t_piece *tetro);
t_piece				*shift_tetro(t_piece *tetro, int dim);
t_piece				*shift_down(t_piece *tetro, int b);
t_piece				*shift_right(t_piece *tetro, int b);
t_piece				*shift_left(t_piece *tetro, int b);
int					ft_sqrt(int n);
int					set_canvas(char **output, int dim);
void				fill_canvas(char **output, t_piece *tetro, int letter);

#endif
