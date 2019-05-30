/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: widrye <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 19:44:22 by widrye       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 02:27:02 by widrye      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int rt;

	rt = 0;
	if (n < 0)
		return (0);
	while (rt <= n / 2)
	{
		if (rt > 46430)
			return (0);
		if (n == rt * rt)
			return (rt);
		else if (n < rt * rt)
			return (rt - 1);
		else
			rt++;
	}
	return (0);
}
