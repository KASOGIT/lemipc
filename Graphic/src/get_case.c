/*
** get_case.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Mon Mar 21 14:43:47 2016 
** Last update Mon Mar 21 15:22:26 2016 
*/

#include "lemipc.h"

int	*get_near_case(t_player *player)
{
  int	*c;

  if ((c = malloc(sizeof(int) * 8)) == NULL)
    abort();
  c[0] = get_case(player->x + 1, player->y);
  c[1] = get_case(player->x - 1, player->y);
  c[2] = get_case(player->x, player->y + 1);
  c[3] = get_case(player->x, player->y - 1);
  c[4] = get_case(player->x + 1, player->y + 1);
  c[5] = get_case(player->x + 1, player->y - 1);
  c[6] = get_case(player->x - 1, player->y + 1);
  c[7] = get_case(player->x - 1, player->y - 1);
  return (c);
}

int	get_case(int x, int y)
{
  int	pos;

  pos = y * HEIGHT + x;
  if (pos < 0 || pos > (HEIGHT * WIDTH - 1))
    return (-1);
  return (pos);
}
