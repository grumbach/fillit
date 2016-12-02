/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:03:31 by kneth             #+#    #+#             */
/*   Updated: 2016/12/02 17:15:53 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			blockletter(char *blockcode, char *buf, char c, int xyjbm[5])
{
	if (buf[(xyjbm[0] + 5 * xyjbm[1])] == '.')
	{
		blockcode[xyjbm[2]] = '.';
		xyjbm[2]++;
		return (1);
	}
	else if (buf[(xyjbm[0] + 5 * xyjbm[1])] == '#')
	{
		blockcode[xyjbm[2]] = c;
		xyjbm[2]++;
		return (1);
	}
	return (-1);
}

void		checkright(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'r';
	xyjbm[0]++;
}

void		checkleft(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'l';
	xyjbm[0]--;
}

void		checkdown(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'd';
	xyjbm[1]++;
}
