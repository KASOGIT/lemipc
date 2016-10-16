/*
** game.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:31:07 2016 
** Last update Sun Mar 27 23:16:29 2016 
*/

#include "lemipc.h"

void		*thread_func(void *data)
{
  t_info	*info;
  t_surface	*surface;
  t_graph	*graph;

  surface = NULL;
  if ((graph = malloc(sizeof(t_graph))) == NULL)
    exit(EXIT_FAILURE);
  info = (t_info *)data;
  surface = init_screen(graph, surface);
  while (42)
    {
      aff_graph(info, graph, surface);
    }
  return (NULL);
}

static int	player_routine(t_info *info, t_player *player, t_cond *cond)
{
  int		nteam;

  lock_sem(info);
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
  usleep(100000);
  unlock_sem(info);
  return (nteam);
}

void		game(t_info *info, t_player *player)
{
  t_cond	cond;
  int		nteam;
  pthread_t	id;

  nteam = -1;
  if (player->type == SUPERVISOR)
    pthread_create(&id, NULL, &thread_func, info);
  while (is_not_rdy(info->board, player));
  cond.ok = 1;
  cond.sup_alive = 0;
  if (player->type == SUPERVISOR)
    cond.sup_alive = 1;
  send_msg_newp(info->msg_id, player);
  while (cond.ok || cond.sup_alive)
    nteam = player_routine(info, player, &cond);
  if (player->type == SUPERVISOR)
    {
      sleep(1);
      pthread_cancel(id);
      printf("TEAM: %d WIN THIS ROUND\n", nteam);
      clear_ipc(info);
    }
}
