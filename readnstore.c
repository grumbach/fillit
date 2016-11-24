/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnstore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:01:49 by kneth             #+#    #+#             */
/*   Updated: 2016/11/25 00:10:48 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

#define BUF_SIZE 21

t_list	*readnstore(int fd)
{
	int			ret;
	int			n;
	char		buf[BUF_SIZE + 1];
	t_list		*blocks;

	n = 0;
	blocks = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(checkblock(buf, ret)))
			return (NULL);
		else
		{
			blocks = ft_lstnew(buf, (BUF_SIZE + 1));
			blocks = blocks->next;
			n++;
		}
	}
	return (blocks);
}
