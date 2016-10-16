/*
** put_player.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:37:26 2016 
** Last update Sat Mar 26 16:36:46 2016 
*/

#include "lemipc.h"

static int	is_full(t_case *board)
{
  int		i;

  i = 0;
  while (i < (WIDTH * HEIGHT))
    {
      if (board[i].nteam == 0)
	return (0);
      i++;
    }
  return (1);
}

t_case	*put_player_on_board(t_info *info, t_player *player,
			     t_type_player type)
{
  int	rand_pos;

  if (is_full(info->board))
    fatal_err("No enough place on board");
  rand_pos = rand_gen(0, (WIDTH * HEIGHT - 1));
  while (info->board[rand_pos].nteam != 0)
    {
      rand_pos = rand_gen(0, WIDTH * HEIGHT - 1);
    }
  info->board[rand_pos].nteam = player->nteam;
  player->type = type;
  player->pos = rand_pos;
  player->x = info->board[player->pos].x;
  player->y = info->board[player->pos].y;
  return (info->board);
}
