# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: widrye <widrye@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/29 07:11:21 by widrye       #+#   ##    ##    #+#        #
#    Updated: 2019/01/30 14:05:49 by chgaroux    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit

CC = gcc

CCFLAGS += -Wall -Wextra -Werror -c -g

INC = fillit.h

OBJ = $(SRC:.c=.o)

SRC = ft_power.c ft_putchar.c ft_putendl.c ft_putstr.c ft_sqrt.c \
	  ft_strlen.c main.c manimap.c manippieces.c print_fillit.c \
	  solver.c str_to_bits.c parse_file.c ft_strcmp.c coloring_map.c

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	@$(CC) -o $(NAME) $(OBJ)

%.o: ./%.c
	$(CC) $(CCFLAGS) -I $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
