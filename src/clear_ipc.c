/*
** clear_ipc.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 13:35:38 2016 
** Last update Mon Mar 21 13:36:09 2016 
*/

#include "lemipc.h"

void	clear_sem(int sem_id)
{
  semctl(sem_id, 0, IPC_RMID);
}

void	clear_msgq(int msg_id)
{
  msgctl(msg_id, IPC_RMID, 0);
}

void	clear_shm(t_info *info)
{
  shmctl(info->shm_id, IPC_RMID, 0);
  shmdt(info->board);
}

void	clear_ipc(t_info *info)
{
  clear_sem(info->sem_id);
  clear_msgq(info->msg_id);
  clear_shm(info);
}
