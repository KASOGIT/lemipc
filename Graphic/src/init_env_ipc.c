/*
** init_env_ipc.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 13:38:57 2016 
** Last update Sun Mar 27 23:17:03 2016 
*/

#include "lemipc.h"

int	init_sem(key_t key)
{
  int	sem_id;

  if ((sem_id = semget(key, 1, SHM_R | SHM_W)) == -1)
    {
      sem_id = semget(key, 1, IPC_CREAT | SHM_R | SHM_W);
      semctl(sem_id, 0, SETVAL, 1);
    }
  return (sem_id);
}

int	init_msgq(key_t key)
{
  int	msg_id;

  if ((msg_id = msgget(key, SHM_R | SHM_W)) == -1)
    {
      msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
    }
  return (msg_id);
}

void	init_player_env(t_info *info, t_player *player)
{
  info->sem_id = init_sem(info->key);
  info->msg_id = init_msgq(info->key);
  if ((info->shm_id = shmget(info->key, SIZE_MAP, SHM_R | SHM_W)) == -1)
    {
      info->shm_id = shmget(info->key, SIZE_MAP, IPC_CREAT | SHM_R | SHM_W);
      if ((info->board = (t_case *)shmat(info->shm_id, NULL, SHM_R | SHM_W))
	  == (void *)-1)
	fatal_err("Can't attach segment");
      info->board = init_board(info->board);
      lock_sem(info);
      info->board = put_player_on_board(info, player, SUPERVISOR);
      unlock_sem(info);
    }
  else
    {
      if ((info->board = (t_case *)shmat(info->shm_id, NULL, SHM_R | SHM_W))
	  == (void *)-1)
	fatal_err("Can't attach segment");
      lock_sem(info);
      info->board = put_player_on_board(info, player, PLAYER);
      unlock_sem(info);
    }
}
