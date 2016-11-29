/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:24:56 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/29 23:37:20 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//must '\0' terminate every square[]!!
// X,Yolaladolala separate X , Y, struct!
// struct
// 	->X
// 	->Y
// 	->blockcode

//check if can place block here
static int		check(char *blockcode, char **square, int y, int x)
{
	return (0);
}

//fix 5 parrams
int				solve(t_list blocks, int y, int x, int sq_size, char **square)
{
	if (blocks == NULL)//reached end of list? YEAH!! :D
		return (1);
	if (sq_size - x < blocks->content->X)//room in X?
		return (solve(blocks, y + 1, 0, sq_size, square));//nope? go down
	if (sq_size - y < blocks->content->Y)//room in Y?
		return (-1);//no more room down there give up bro
	if (!check(blocks->content->blockcode, square, y, x))//check if can place block
		return (solve(blocks, y, x + 1, sq_size, square));//check at x+1
	place(square, blocks->content->blockcode, y, x);//place coz ok!
	if (solve(blocks->next->blockcode, y, x, sq_size, square) == -1)//backtrackloop
	{
		erase(square, blocks->content->blockcode, y, x);//rm if error
		return (solve(blocks, y, x, sq_size, square));//try again with cur block
	}
	return (0);//shows me if I'm stupid today, I certainly am sometimes!
}

char			*fillit(t_list *blocks)
{
	int		sq_size;
	char	**sq;

	sq_size = 2 * ft_sqrt(ft_lstsize(blocks));
	if (!(sq = square(sq_size)))
		return (NULL);
	while (solve(blocks, 0, 0, sq_size, square) == -1)
	{
		sq_size++;
		sq = square(sq_size);
	}
	return ("success!\n");
}
