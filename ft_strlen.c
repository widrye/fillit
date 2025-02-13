/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:45:27 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 00:38:28 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}
