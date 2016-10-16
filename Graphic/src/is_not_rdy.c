/*
** is_not_rdy.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:40:33 2016 
** Last update Mon Mar 21 14:41:03 2016 
*/

#include "lemipc.h"

int	is_not_rdy(t_case *board, t_player *player)
{
  int	i;
  int	mates;
  int	enemies;

  i = 0;
  mates = 1;
  enemies = 0;
  while (i < (WIDTH * HEIGHT))
    {
      if (board[i].x != player->x && board[i].y != player->y
	  && board[i].nteam == player->nteam)
	mates++;
      else if (board[i].nteam != 0 && board[i].nteam != player->nteam)
	enemies++;
      i++;
    }
  if ((mates > 1 && enemies >= 1) || (enemies > 1 && mates >= 1))
    return (0);
  else
    return (1);
}
