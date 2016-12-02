/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:17:24 by kneth             #+#    #+#             */
/*   Updated: 2016/12/02 18:58:30 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>

typedef struct		s_tetri
{
	int				y;
	int				x;
	char			*blockcode;
}					t_tetri;

int					checkblock(char *tetri, int ret);
t_list				*readnstore(int fd);
t_tetri				*encode(char *buf, char c);
int					blockletter(char *blockcode, char *buf, char c, \
						int xyjbm[5]);
void				checkright(char *blockcode, char *buf, char c, \
						int xyjbm[5]);
void				checkleft(char *blockcode, char *buf, char c, int xyjbm[5]);
void				checkdown(char *blockcode, char *buf, char c, int xyjbm[5]);
char				**fillit(t_list *blocks);
char				**square(int size);
void				place(char **square, char *blockcode, int y, int x);
void				erase(char **square, char *blockcode, int y, int x);

void		disp_table(char **table);

#endif
