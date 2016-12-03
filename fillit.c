/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:24:56 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/03 11:44:17 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			tetri_free(void *content, size_t size)
{
	if (size == sizeof(t_tetri))
	{
		free(((t_tetri*)(content))->blockcode);
		free(content);
	}
	content = NULL;
}

void			sq_free(char **sq, int sq_size)
{
	int		i;

	i = 0;
	while (i < sq_size)
	{
		if (sq[i])
			free(sq[i]);
		i++;
	}
	if (sq)
		free(sq);
	sq = NULL;
}

static int		check(char *blockcode, char **square, int y, int x)
{
	int		i;

	i = 0;
	if (ft_isalpha(blockcode[i]) && ft_isalpha(square[y][x]))
		return (0);
	while (blockcode[i] != '\0')
	{
		if (blockcode[i] == 'r' || blockcode[i] == 'l' || blockcode[i] == 'd')
		{
			if (blockcode[i] == 'r')
				x++;
			else if (blockcode[i] == 'l')
				x--;
			else if (blockcode[i] == 'd')
				y++;
			i++;
			if (ft_isalpha(blockcode[i]) && ft_isalpha(square[y][x]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int		solve(t_list *blocks, int y, int x, char **square)
{
	if (blocks == NULL)
		return (1);
	if ((int)ft_strlen(square[0]) < y + ((t_tetri*)(blocks->content))->y)
		return (-1);
	if ((int)ft_strlen(square[0]) < x + ((t_tetri*)(blocks->content))->x)
		return (solve(blocks, y + 1, 0, square));
	if (!(check(((t_tetri*)(blocks->content))->blockcode, square, y, x)))
		return (solve(blocks, y, x + 1, square));
	place(square, ((t_tetri*)(blocks->content))->blockcode, y, x);
	if (solve(blocks->next, 0, 0, square) == -1)
	{
		erase(square, ((t_tetri*)(blocks->content))->blockcode, y, x);
		return (solve(blocks, y, x + 1, square));
	}
	return (0);
}

char			**fillit(t_list *blocks)
{
	int		sq_size;
	char	**sq;

	sq_size = (ft_sqrt(ft_lstsize(blocks) * 4));
	if (sq_size < 3)
		sq_size = 3;
	if (!(sq = square(sq_size)))
		return (NULL);
	while (solve(blocks, 0, 0, sq) == -1)
	{
		sq_free(sq, sq_size);
		sq_size++;
		sq = square(sq_size);
	}
	ft_lstdel(&blocks, &tetri_free);
	return (sq);
}
