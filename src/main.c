/*
** main.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Tue Mar 15 01:48:06 2016 
** Last update Sun Mar 27 23:12:06 2016 
*/

#include "lemipc.h"

void	usage()
{
  fprintf(stderr, "Usage: ./lemipc PATH TEAM_NUMBER\n");
  exit(EXIT_FAILURE);
}

void	fatal_err(const char *msg)
{
  fprintf(stderr, "Error: %s\n", msg);
  exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
  t_info	info;
  t_player	player;

  if (ac != 3 || (player.nteam = atoi(av[2])) < 1)
    usage();
  if ((info.key = ftok(av[1], 0)) == -1)
    fatal_err("ftok fail");
  init_rand();
  init_player_env(&info, &player);
  game(&info, &player);
  return (0);
}
