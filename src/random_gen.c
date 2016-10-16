/*
** random_gen.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Mar 15 18:37:41 2016 
** Last update Sat Mar 26 16:18:33 2016 
*/

#include "lemipc.h"

void	init_rand()
{
  srand((unsigned int)time(NULL));
}

int	rand_gen(int min, int max)
{
  float	random;
  float	range;

  random = ((float)rand()) / (float)RAND_MAX;
  range = (max + 1) - min;
  return ((int)((random * range) + min));
}
