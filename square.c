/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:30:53 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/29 23:13:14 by agrumbac         ###   ########.fr       */
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
		i++;
	}
	return (sq);
}

void	place(char **square, char *blockcode, int y, int x)
{
	int		i;

	i = 0;
	while (ft_isdigit(blockcode[i]))
		i++;
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
	while (ft_isdigit(blockcode[i]))
		i++;
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
				square[y][x] = '.';
		}
		i++;
	}
}
