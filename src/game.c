/*
** game.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:31:07 2016 
** Last update Sun Mar 27 23:11:26 2016 
*/

#include "lemipc.h"

static int	player_routine(t_info *info, t_player *player, t_cond *cond)
{
  int		nteam;

  lock_sem(info);
  if (player->type == SUPERVISOR)
    rec_msg(info->msg_id);
  if ((cond->ok = is_game_alive(info->board, &nteam)))
    {
      if ((cond->ok = check_if_alive(info, player)) != 0)
	player_move(info, player);
      else
	{
	  info->board[player->pos].nteam = 0;
	  send_msg_dead(info->msg_id, player->nteam);
	}
    }
  else
    cond->sup_alive = 0;
  usleep(10000);
  unlock_sem(info);
  return (nteam);
}

void		game(t_info *info, t_player *player)
{
  t_cond	cond;
  int		nteam;

  nteam = -1;
  while (is_not_rdy(info->board, player));
  cond.ok = 1;
  cond.sup_alive = 0;
  if (player->type == SUPERVISOR)
    cond.sup_alive = 1;
  send_msg_newp(info->msg_id, player);
  usleep(10000);
  while (cond.ok || cond.sup_alive)
    nteam = player_routine(info, player, &cond);
  if (player->type == SUPERVISOR)
    {
      printf("TEAM: %d WIN THIS ROUND\n", nteam);
      clear_ipc(info);
    }
}
