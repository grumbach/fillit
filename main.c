/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:21:12 by kneth             #+#    #+#             */
/*   Updated: 2016/12/02 23:26:32 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

static int	ft_errors(int error)
{
	if (error == 0)
		ft_putstr_fd("usage: ./fillit input_file\n", 2);
	else if (error == 1)
		ft_putstr_fd("open() error\n", 2);
	else if (error == 2)
		ft_putstr_fd("error\n", 1);
	else if (error == 3)
		ft_putstr_fd("close() error\n", 2);
	return (0);
}

void		disp_table(char **table)
{
	int		i;
	int		len;

	i = 0;
	len = strlen(table[0]);
	while (i < len)
	{
		ft_putstr(table[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char **av)
{
	int		fd;
	t_list	*blocks;

	if (ac != 2)
		return (ft_errors(0));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_errors(1));
	blocks = readnstore(fd);
	if (blocks == NULL)
		return (ft_errors(2));
	if (close(fd) == -1)
		return (ft_errors(3));
	disp_table(fillit(blocks));
	return (0);
}
