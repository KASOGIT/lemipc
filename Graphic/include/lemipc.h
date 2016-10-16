/*
** lemipc.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc/include
** 
** Made by adam soto
** Login   <soto_a@epitech.net>
** 
** Started on  Tue Mar 15 16:46:54 2016 
** Last update Sun Mar 27 22:41:55 2016 
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <SDL/SDL.h>

# define WIDTH		25
# define HEIGHT		25
# define SIZE_MAP	WIDTH * HEIGHT * sizeof(struct s_case)
# define ID_NEW_P	1
# define ID_DEAD	2
# define ID_MOVE	3

typedef struct	s_case
{
  int		x;
  int		y;
  int		nteam;
}		t_case;

typedef enum	e_type_player
  {
    SUPERVISOR,
    PLAYER
  }		t_type_player;

typedef struct	s_info
{
  t_case	*board;
  key_t		key;
  int		shm_id;
  int		sem_id;
  int		msg_id;
}		t_info;

typedef struct	s_player
{
  t_type_player	type;
  int		pos;
  int		nteam;
  int		x;
  int		y;
}		t_player;

typedef struct	s_cond
{
  int		sup_alive;
  int		ok;
}		t_cond;

typedef struct	s_sub_new_p
{
  int		nteam;
  int		x;
  int		y;
}		t_sub_new_p;

typedef struct	s_msg_new_p
{
  long		mtype;
  t_sub_new_p	new_p;
}		t_msg_new_p;

typedef struct	s_msg_dead
{
  long		mtype;
  int		nteam;
}		t_msg_dead;

typedef struct	s_sub_move
{
  int		nteam;
  int		x_prev;
  int		y_prev;
  int		x_new;
  int		y_new;
}		t_sub_move;

typedef struct	s_msg_move
{
  long		mtype;
  t_sub_move	move;
}		t_msg_move;

typedef struct s_surface
{
  uint32_t              color;
  SDL_Surface           *rect;
  int                   team;
  struct s_surface      *next;
}               t_surface;

typedef struct s_graph
{
  SDL_Surface   *screen;
  t_surface     *surface;
}               t_graph;

void	init_rand();
int	rand_gen(int min, int max);
void	rec_msg_new_p(int msg_id, t_graph *graph, t_info *info, t_surface *surface);
void	rec_msg_move(int msg_id, t_graph *graph, t_info *info, t_surface *surface);
void	rec_msg_dead(int msg_id, t_graph *graph, t_info *info, t_surface *surface);
void	rec_msg(int msg_id, t_graph *graph, t_info *info, t_surface *surface);
void	send_msg_dead(int msg_id, int nteam);
void	send_msg_move(int msg_id, t_player *player, int n_x, int n_y);
void	send_msg_newp(int msg_id, t_player *player);
void	lock_sem(t_info *info);
void	unlock_sem(t_info *info);
void	clear_sem(int sem_id);
void	clear_msgq(int msg_id);
void	clear_shm(t_info *info);
void	clear_ipc(t_info *info);
void	init_player_env(t_info *info, t_player *player);
int	init_msgq(key_t key);
int	init_sem(key_t key);
int	check_if_alive(t_info *info, t_player *player);
void	player_move(t_info *info, t_player *player);
void	player_rand_move(t_info *info, t_player *player);
void	game(t_info *info, t_player *player);
t_case	*init_board(t_case *board);
t_case	*put_player_on_board(t_info *info, t_player *player, t_type_player type);
int	is_not_rdy(t_case *board, t_player *player);
int	is_game_alive(t_case *board, int *nteam);
int	get_case(int x, int y);
int	*get_near_case(t_player *player);
void	fatal_err(const char *msg);
t_surface    *init_screen(t_graph *graph, t_surface *surface);
void    print_color(t_surface *surface);
void    aff_graph(t_info *info, t_graph *graph, t_surface *surface);


#endif
