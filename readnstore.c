/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnstore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:01:49 by kneth             #+#    #+#             */
/*   Updated: 2016/11/29 15:03:45 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

#define BUF_SIZE 21

t_list			*readnstore(int fd)
{
	int			ret;
	int			i;
	char		buf[BUF_SIZE + 1];
	t_list		*blocks;
	t_list		*firstblock;

	i = 0;
	firstblock = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(checkblock(buf, ret)))
			return (NULL);
		else
		{
			i++;
			blocks = ft_lstnew(encode(buf, 'A' + i), BUF_SIZE);
			if (blocks == NULL)
				return (NULL);
			if (firstblock == NULL)
				firstblock = blocks;
			blocks = blocks->next;
		}
	}
	return (firstblock);
}
