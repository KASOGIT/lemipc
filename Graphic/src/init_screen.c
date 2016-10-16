/*
** init_screen.c for lemipc in /home/julien_k/rendu/lemipc
** 
** Made by Kévin Julien
** Login   <julien_k@epitech.net>
** 
** Started on  Tue Mar 22 16:10:49 2016 Kévin Julien
** Last update Sun Mar 27 23:14:19 2016 
*/

#include "lemipc.h"

void		aff_graph(t_info *info, t_graph *graph, t_surface *surface)
{
  int		i;
  SDL_Rect	pos;
  SDL_Surface	*tmp;

  i = 0;
  tmp = SDL_CreateRGBSurface(SDL_HWSURFACE, 32, 32, 32, 0, 0, 0, 0);
  SDL_FillRect(tmp, NULL, SDL_MapRGB(graph->screen->format, 0, 0, 0));
  while (i < (HEIGHT * WIDTH))
    {
      pos.x = info->board[i].x * 32;
      pos.y = info->board[i].y * 32;
      if (info->board[i].nteam != 0)
        {
          SDL_FillRect(surface->rect, NULL, surface->color
		       * info->board[i].nteam);
          SDL_BlitSurface(surface->rect, NULL, graph->screen, &pos);
        }
      else
        SDL_BlitSurface(tmp, NULL, graph->screen, &pos);
      i++;
    }
  SDL_Flip(graph->screen);
  sleep(1);
}

void		print_color(t_surface *surface)
{
  t_surface	*tmp;

  tmp = surface;
  printf("coucou\n");
  while (tmp != NULL)
    {
      printf("Team -> %d\nColor -> %d\n", tmp->team, tmp->color);
      tmp = tmp->next;
    }
}

t_surface	*add_surface(t_graph *graph, t_surface *surface)
{
  if (surface == NULL)
    {
      if ((surface = malloc(sizeof(t_surface))) == NULL)
	exit(EXIT_FAILURE);
      surface->next = NULL;
      surface->color = SDL_MapRGB(graph->screen->format,
				  (abs(rand()) * surface->team) % 256,
				  (abs(rand()) * surface->team) % 256,
				  (abs(rand()) * surface->team) % 256);
      surface->rect = SDL_CreateRGBSurface(SDL_HWSURFACE,
					   32, 32, 32, 0, 0, 0, 0);
      SDL_FillRect(surface->rect, NULL, surface->color);
    }
  return (surface);
}

t_surface	*init_screen(t_graph *graph, t_surface *surface)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Error init SDL\n");
      exit(EXIT_FAILURE);
    }
  if ((graph->screen = SDL_SetVideoMode(32 * WIDTH, 32 * HEIGHT,
					32, SDL_HWSURFACE)) == NULL)
    {
      printf("Error init screen\n");
      exit(EXIT_FAILURE);
    }
  surface = add_surface(graph, surface);
  sleep(3);
  return (surface);
}
