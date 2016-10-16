##
## Makefile for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_philo
## 
## Made by adam soto
## Login   <soto_a@epitech.net>
## 
## Started on  Wed Mar  2 12:54:44 2016 
## Last update Sun Oct 16 22:22:50 2016 
##

NAME	= lemipc

CFLAGS	= -I./include -O2 -pipe
LDFLAGS	= -lm

CC	= gcc

SRC	= main.c \
	  random_gen.c \
	  check_if_alive.c \
	  clear_ipc.c \
	  game.c \
	  get_case.c \
	  init_board.c \
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
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

