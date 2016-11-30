/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:30:53 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/30 18:40:38 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**square(int size)
{
	int		i;
	char	**sq;

	i = 0;
	if (!(sq = (char**)malloc(sizeof(*sq) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(sq[i] = malloc(sizeof(*sq) * size + 1)))
			return (NULL);
		sq[i][size] = '\0';
		i++;
	}
	return (sq);
}

void	place(char **square, char *blockcode, int y, int x)
{
	int		i;

	i = 0;
	if (ft_isalpha(blockcode[i]))
		square[y][x] = blockcode[i];
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
				square[y][x] = blockcode[i];
		}
		i++;
	}
}

void	erase(char **square, char *blockcode, int y, int x)
{
	int		i;

	i = 0;
	if (ft_isalpha(blockcode[i]))
		square[y][x] = '.';
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
				square[y][x] = '.';
		}
		i++;
	}
}
