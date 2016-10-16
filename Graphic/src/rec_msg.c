/*
** rec_msg.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 13:22:47 2016 
** Last update Sun Mar 27 21:28:06 2016 Kévin Julien
*/

#include "lemipc.h"

void		rec_msg_new_p(int msg_id, t_graph *graph, t_info *info, t_surface *surface)
{
  t_msg_new_p	msg;

  if (msgrcv(msg_id, &msg, sizeof(msg), ID_NEW_P, IPC_NOWAIT) > 0)
    {
      aff_graph(info, graph, surface);
      printf("New player team: %d enters the arena at pos (%d, %d)\n",
	     msg.new_p.nteam, msg.new_p.x, msg.new_p.y);
    }
}

void		rec_msg_dead(int msg_id, t_graph *graph, t_info *info, t_surface *surface)
{
  t_msg_dead	msg;

  if (msgrcv(msg_id, &msg, sizeof(msg), ID_DEAD, IPC_NOWAIT) > 0)
    {
      aff_graph(info, graph, surface);
      printf("Player from team: %d has just died\n", msg.nteam);
    }
}

void		rec_msg_move(int msg_id, t_graph *graph, t_info *info, t_surface *surface)
{
  t_msg_move	msg;

  if (msgrcv(msg_id, &msg, sizeof(msg), ID_MOVE, IPC_NOWAIT) > 0)
    {
      aff_graph(info, graph, surface);
      printf("Player from team: %d move from (%d, %d) to (%d, %d)\n",
	     msg.move.nteam, msg.move.x_prev, msg.move.y_prev,
	     msg.move.x_new, msg.move.y_new);
    }
}

void	rec_msg(int msg_id, t_graph *graph, t_info *info, t_surface *surface)
{
  aff_graph(info, graph, surface);
  rec_msg_new_p(msg_id, graph, info, surface);
  rec_msg_move(msg_id, graph, info, surface);
  rec_msg_dead(msg_id, graph, info, surface);
}
