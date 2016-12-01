/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:29:03 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/01 16:18:21 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	checkpos(char *tetri, int code[4])
{
	int		i;

	i = 0;
	code[0] = 0;
	code[1] = 0;
	code[2] = 5;
	code[3] = 5;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if ((i % 5) > code[0])
				code[0] = (i % 5);
			if ((i / 5) > code[1])
				code[1] = (i / 5);
			if ((i % 5) < code[2])
				code[2] = (i % 5);
			if ((i / 5) < code[3])
				code[3] = (i / 5);
		}
		i++;
	}
}

static int	blockletter(char *blockcode, char *buf, int j, char c, int x, int y)
{
	if (buf[(x + 5 * y)] == '.')
	{
		blockcode[j] = '.';
		return (0);
	}
	else if (buf[(x + 5 * y)] == '#')
	{
		blockcode[j] = c;
		return (1);
	}
}


//fix this
static char	*blockcode(char *blockcode, char *buf, char c, int code[6])
{
	int		x;
	int		y;
	int		j;
	int		blocks;

	j = 0;
	y = code[3];
	x = code[2];
	blocks = 0;
	while (blocks < 4)
	{
		while (x < code[0])
		{
			blocks += blockletter(blockcode, buf, j, c, x, y);
			j++;
			blockcode[j] = 'r';
			x++;
		}
		if (y < code[1])
		{
			blocks += blockletter(blockcode, buf, j, c, x, y);
			j++;
			blockcode[j] = 'd';
			y++;
		}
		while (x > code[2])
		{
			blocks += blockletter(blockcode, buf, j, c, x, y);
			j++;
			blockcode[j] = 'l';
			x--;
		}
	}
	return (blockcode);
}

t_tetri		*encode(char *buf, char c)
{
	int		code[6];
	char	*blockcode;
	t_tetri	*tetri;

	checkpos(tetri, code);
	if (!(blockcode = (char*)malloc(sizeof(*blockcode) * 14)))
		return (NULL);
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	ft_bzero(blockcode);
	tetri->y = 1 + code[1] - code[3];
	tetri->x = 1 + code[0] - code[2];
	tetri->blockcode = codeblock(blockcode, buf, c, code);
	return (tetri);
}
