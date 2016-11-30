/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:24:56 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/30 22:33:42 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			tetri_free(void *content, size_t size)
{
	if (size == sizeof(t_tetri))
	{
		free(content->blockcode);
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
	if (ft_isalpha(blockcode[i]))
		if (ft_isalpha(square[x][y]))
			return (0);
	while (blockcode[i] != '\0')
	{
		if (blockcode[i] == 'd' || blockcode[i] == 'l' || blockcode[i] == 'd')
		{
			if (blockcode[i] == 'r')
				x++;
			else if (blockcode[i] == 'l')
				x--;
			else if (blockcode[i] == 'd')
				y++;
			i++;
			if (ft_isalpha(blockcode[i]))
				if (ft_isalpha(square[x][y]))
					return (0);
		}
		i++;
	}
	return (1);
}

//fix 5 parrams

static int		solve(t_list blocks, int y, int x, int sq_size, char **square)
{
	if (blocks == NULL)//reached end of list? YEAH!! :D
		return (1);
	if (sq_size - x < blocks->content->x)//room in X?
		return (solve(blocks, y + 1, 0, sq_size, square));//nope? go down
	if (sq_size - y < blocks->content->y)//room in Y?
		return (-1);//no more room down there give up bro
	if (!check(blocks->content->blockcode, square, y, x))//check if can place block
		return (solve(blocks, y, x + 1, sq_size, square));//check at x+1
	place(square, blocks->content->blockcode, y, x);//place coz ok!
	if (solve(blocks->next, y, x, sq_size, square) == -1)//backtrackloop
	{
		erase(square, blocks->content->blockcode, y, x);//rm if error
		return (solve(blocks, y, x, sq_size, square));//try again with cur block
	}
	return (0);//shows me if I'm stupid today, I certainly am sometimes!
}

char			**fillit(t_list *blocks)
{
	int		sq_size;
	char	**sq;

	sq_size = 2 * ft_sqrt(ft_lstsize(blocks));
	if (!(sq = square(sq_size)))
		return (NULL);
	while (solve(blocks, 0, 0, sq_size, square) == -1)
	{
		sq_free(sq, sq_size);
		sq_size++;
		sq = square(sq_size);
	}
	ft_lstdel(&blocks, &tetri_free);
	return (sq);
}
