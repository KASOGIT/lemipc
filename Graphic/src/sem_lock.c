/*
** sem_lock.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 13:32:30 2016 
** Last update Mon Mar 21 13:33:25 2016 
*/

#include "lemipc.h"

void			lock_sem(t_info *info)
{
  static struct sembuf	sb = {0, -1, SEM_UNDO};

  semop(info->sem_id, &sb, 1);
}

void			unlock_sem(t_info *info)
{
  static struct sembuf	sb = {0, 1, 0};

  semop(info->sem_id, &sb, 1);
}
