/*
** send_msg.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 13:29:23 2016 
** Last update Tue Mar 22 16:24:40 2016 adam soto
*/

#include "lemipc.h"

void		send_msg_dead(int msg_id, int nteam)
{
  t_msg_dead	msg;

  bzero(&msg, sizeof(msg));
  msg.mtype = ID_DEAD;
  msg.nteam = nteam;
  msgsnd(msg_id, &msg, sizeof(int), 0);
}

void		send_msg_move(int msg_id, t_player *player, int n_x, int n_y)
{
  t_msg_move	msg;

  bzero(&msg, sizeof(msg));
  msg.mtype = ID_MOVE;
  msg.move.nteam = player->nteam;
  msg.move.x_prev = player->x;
  msg.move.y_prev = player->y;
  msg.move.x_new = n_x;
  msg.move.y_new = n_y;
  msgsnd(msg_id, &msg, sizeof(t_sub_move), 0);
}

void		send_msg_newp(int msg_id, t_player *player)
{
  t_msg_new_p	msg;

  bzero(&msg, sizeof(msg));
  msg.mtype = ID_NEW_P;
  msg.new_p.nteam = player->nteam;
  msg.new_p.x = player->x;
  msg.new_p.y = player->y;
  msgsnd(msg_id, &msg, sizeof(t_sub_new_p), 0);
}
