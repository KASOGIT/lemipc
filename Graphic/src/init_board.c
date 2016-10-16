/*
** init_board.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:35:17 2016 
** Last update Mon Mar 21 14:35:41 2016 
*/

#include "lemipc.h"

t_case	*init_board(t_case *board)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  while (i < (WIDTH * HEIGHT))
    {
      board[i].x = x;
      board[i].y = y;
      board[i].nteam = 0;
      x++;
      if (x == WIDTH)
	{
	  y++;
	  x = 0;
	}
      i++;
    }
  return (board);
}
