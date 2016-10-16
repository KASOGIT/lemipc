##
## Makefile for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
## 
## Made by adam soto
## Login   <soto_a@epitech.net>
## 
## Started on  Wed Mar  2 12:54:44 2016 
## Last update Sun Mar 27 19:53:34 2016 Kévin Julien
##

NAME	= lemipc

CFLAGS	= -W -Wall -Wextra -I./include -g3
#LDFLAGS	= 

CC	= gcc

SRC	= main.c \
	  random_gen.c \
	  check_if_alive.c \
	  clear_ipc.c \
	  game.c \
	  get_case.c \
	  init_board.c \
	  init_screen.c \
	  init_env_ipc.c \
	  is_game_alive.c \
	  is_not_rdy.c \
	  player_move.c \
	  put_player.c \
	  rec_msg.c \
	  sem_lock.c \
	  send_msg.c \

OBJ	= $(addprefix src/, $(SRC:.c=.o))

$(NAME):	$(OBJ)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) -O3 -lSDL -lm -lpthread

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

