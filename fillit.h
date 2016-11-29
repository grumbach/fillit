/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:17:24 by kneth             #+#    #+#             */
/*   Updated: 2016/11/29 22:07:07 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>

int		checkblock(char *tetri, int ret);
t_list	*readnstore(int fd);
char	*fillit(t_list *blocks);
char	**square(int size);
void	place(char **square, char *blockcode, int y, int x);
void	erase(char **square, char *blockcode, int y, int x);

#endif
