/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:21:12 by kneth             #+#    #+#             */
/*   Updated: 2016/11/25 00:21:18 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_list	*blocks;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("open() errror\n", 2);
		return (-1);
	}
	blocks = readnstore(fd);
	if (blocks == NULL)
	{
		ft_putstr("invalid file\n");
		return (-1);
	}
	if (close(fd) == -1)
	{
		ft_putstr_fd("close() errror\n", 2);
		return (-1);
	}
	ft_putstr(fillit(blocks));
	return (0);
}
