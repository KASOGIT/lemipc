/*
** player_move.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:21:41 2016 
** Last update Sun Mar 27 23:11:47 2016 
*/

#include "lemipc.h"

void		player_rand_move(t_info *info, t_player *player)
{
  int		*c;
  int		i;
  int		rand_pos;

  i = 0;
  c = get_near_case(player);
  rand_pos = rand_gen(0, 3);
  while (i < 12 && c[rand_pos] == -1)
    {
      i++;
      rand_pos = rand_gen(0, 3);
    }
  if (c[rand_pos] != -1 && info->board[c[rand_pos]].nteam == 0)
    {
      info->board[player->pos].nteam = 0;
      info->board[c[rand_pos]].nteam = player->nteam;
      player->pos = c[rand_pos];
      send_msg_move(info->msg_id, player,
		    info->board[player->pos].x,
		    info->board[player->pos].y);
      player->x = info->board[player->pos].x;
      player->y = info->board[player->pos].y;
    }
  free(c);
}

static int	search_nearest_enemy(t_case *board, t_player *player,
				     int *to_x, int *to_y)
{
  int		i;
  int		dist;
  int		tmp;

  i = 0;
  dist = INT_MAX;
  while (i < (WIDTH * HEIGHT))
    {
      if (i != player->pos && board[i].nteam != 0
	  && board[i].nteam != player->nteam)
	{
	  tmp = abs(board[i].x - player->x) + abs(board[i].y - player->y);
	  if (tmp < dist)
	    {
	      dist = tmp;
	      *to_x = board[i].x;
	      *to_y = board[i].y;
	    }
	}
      i++;
    }
  if (dist != INT_MAX)
    return (1);
  return (0);
}

static void	forward_player(t_info *info, t_player *player, int n_x, int n_y)
{
  int		pos;

  if ((pos = (n_y * HEIGHT + n_x)) < (WIDTH * HEIGHT))
    {
      if (pos != player->pos
	  && info->board[pos].nteam == 0)
	{
	  info->board[pos].nteam = player->nteam;
	  info->board[player->pos].nteam = 0;
	  player->pos = pos;
	  send_msg_move(info->msg_id, player,
			info->board[player->pos].x,
			info->board[player->pos].y);
	  player->x = n_x;
	  player->y = n_y;
	}
      else
      	{
      	  player_rand_move(info, player);
      	}
    }
}

void	player_move(t_info *info, t_player *player)
{
  int	x;
  int	y;
  int	n_x;
  int	n_y;

  if (search_nearest_enemy(info->board, player, &x, &y))
    {
      n_x = player->x;
      n_y = player->y;
      if (x != n_x && y != n_y)
	{
	  if (rand() % 2)
	    n_x += (x < player->x ? -1 : 1);
	  else
	    n_y += (y < player->y ? -1 : 1);
	}
      else
	{
	  if (x != player->x)
	    x += (x < player->x ? -1 : 1);
	  else if (y != player->y)
	    y += (y < player->y ? -1 : 1);
	}
      forward_player(info, player, n_x, n_y);
    }
}
