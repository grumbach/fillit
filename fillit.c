/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:24:56 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/29 21:37:46 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check(t_list blocks)
{
	return (0);
}

int				solve(t_list blocks, int x, int y, int sq_size)
{
	if (blocks->next == NULL)
		return (1);
	if (!check(blocks))
		return (0);
	return (0);
}

char			*fillit(t_list *blocks)
{
	int	sq_size;

	sq_size = 2 * ft_sqrt(ft_lstsize(blocks));
	solve(blocks, x, y, sq_size);
	return ("success!\n");
}
