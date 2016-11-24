/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkblock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:35:24 by kneth             #+#    #+#             */
/*   Updated: 2016/11/25 00:17:28 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			countfriends(char *tetri, int i)
{
	int	friends;

	friends = 0;
	if (tetri[i + 1] == '#')
		friends++;
	if (tetri[i - 1] == '#')
		friends++;
	if (tetri[(i - 5 > 0 ? i - 5 : 4)] == '#')
		friends++;
	if (tetri[(i + 5 < 19 ? i + 5 : 4)] == '#')
		friends++;
	return (friends);
}

static int	blockchecker(char *tetri)
{
	int	i;
	int	blocks;
	int	friends;

	i = 0;
	blocks = 0;
	friends = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			friends += countfriends(tetri, i);
			blocks++;
		}
		i++;
	}
	if (blocks != 4 || friends < 6)
		return (0);
	return (1);
}

int			checkblock(char *tetri, int ret)
{
	int	i;
	int line;

	i = 0;
	line = 0;
	if (ret != 21 && ret != 20)
		return (0);
printf("hey!\n");
	if (ft_strlen(tetri) != ret)
		return (0);
printf("hey!\n");

	while (i < 20)
	{
		while (tetri[i] == '.' || tetri[i] == '#')
			i++;
		if ((i - 4) % 5 != 0 || tetri[i] != '\n')
			return (0);
		line++;
		i++;
	}
	if ((tetri[i] != '\n' && tetri[i] != '\0') || line != 4)
		return (0);
		printf("hey!\n");

	if (!(blockchecker(tetri)))
		return (0);
		printf("hey!\n");

	return (1);
}
