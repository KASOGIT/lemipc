/*
** is_game_alive.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:42:11 2016 
** Last update Sun Mar 27 22:40:22 2016 
*/

#include "lemipc.h"

int	is_game_alive(t_case *board, int *nteam)
{
  int	i;

  *nteam = -1;
  i = 0;
  while (i < (WIDTH * HEIGHT))
    {
      if (board[i].nteam != 0 && *nteam == -1)
	*nteam = board[i].nteam;
      else if (board[i].nteam != 0 && *nteam != -1
	       && *nteam != board[i].nteam)
	return (1);
      i++;
    }
  return (0);
}
