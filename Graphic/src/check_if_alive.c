/*
** check_if_alive.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:20:11 2016 
** Last update Mon Mar 21 15:25:48 2016 
*/

#include "lemipc.h"

int	check_if_alive(t_info *info, t_player *player)
{
  int	*c;
  int	i;
  int	j;

  i = -1;
  c = get_near_case(player);
  while (++i < 8)
    {
      j = -1;
      while (++j < 8)
	{
	  if (i != j &&
	      c[i] != -1 &&
	      c[j] != -1 &&
	      info->board[c[i]].nteam != 0 &&
	      info->board[c[i]].nteam != player->nteam &&
	      info->board[c[i]].nteam == info->board[c[j]].nteam)
	    {
	      free(c);
	      return (0);
	    }
	}
    }
  free(c);
  return (1);
}
