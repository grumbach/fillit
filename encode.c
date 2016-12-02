/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:29:03 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/02 17:25:13 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	checkpos(char *tetri, int code[6])
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

static char	*codeblock(char *bc, char *buf, char c, int code[6])
{
	int		xyjbm[5];

	xyjbm[0] = code[2];
	xyjbm[1] = code[3];
	xyjbm[2] = 0;
	xyjbm[3] = 0;
	xyjbm[4] = code[4] * code[5];
	while (xyjbm[3] < (xyjbm[4] - 1))
	{
		while (xyjbm[0] < code[0] && xyjbm[3] < (xyjbm[4] - 1))
			checkright(bc, buf, c, xyjbm);
		if (xyjbm[1] < code[1] && xyjbm[3] < (xyjbm[4] - 1))
			checkdown(bc, buf, c, xyjbm);
		while (xyjbm[0] > code[2] && xyjbm[3] < (xyjbm[4] - 1))
			checkleft(bc, buf, c, xyjbm);
		if (xyjbm[1] < code[1] && xyjbm[3] < (xyjbm[4] - 1))
			checkdown(bc, buf, c, xyjbm);
	}
	blockletter(bc, buf, c, xyjbm);
	return (bc);
}

t_tetri		*encode(char *buf, char c)
{
	int		code[6];
	char	*blockcode;
	t_tetri	*tetri;

	checkpos(buf, code);
	if (!(blockcode = (char*)malloc(sizeof(*blockcode) * 14)))
		return (NULL);
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	ft_bzero(blockcode, 14);
	code[4] = 1 + code[0] - code[2];
	code[5] = 1 + code[1] - code[3];
	tetri->x = code[4];
	tetri->y = code[5];
	tetri->blockcode = codeblock(blockcode, buf, c, code);
	return (tetri);
}
