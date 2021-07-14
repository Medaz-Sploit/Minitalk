# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 16:40:17 by mazoukni          #+#    #+#              #
#    Updated: 2021/07/14 08:27:43 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = gcc $(FLAGS)
FLAGS = -Wall -Werror -Wextra
SRV_SRC = utils.c server.c
SRV_SRC_BONUS = server_bonus.c
CLNT_SRC = utils.c client.c
CLNT_SRC_BONUS = client_bonus.c 
OBJ_SRV_SRC = $(SRV_SRC:.c=.o)
OBJ_SRV_SRC_BONUS = $(SRV_SRC_BONUS:.c=.o)
OBJ_CLNT_SRC = $(CLNT_SRC:.c=.o)
OBJ_CLNT_SRC_BONUS = $(CLNT_SRC_BONUS:.c=.o)
LIB = -I minitalk.h

all: $(NAME)

$(NAME): fclean $(OBJ_CLNT_SRC) $(OBJ_SRV_SRC)
	@$(CC) $(CLNT_SRC) $(LIB) libft/libft.a -o client
	@$(CC) $(SRV_SRC) $(LIB) libft/libft.a -o server

clean:
	@rm -f $(OBJ_SRV_SRC) $(OBJ_CLNT_SRC)

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

bonus: fclean $(OBJ_CLNT_SRC_BONUS) $(OBJ_SRV_SRC_BONUS)
	@$(CC) $(CLNT_SRC_BONUS) $(LIB) libft/libft.a -o client
	@$(CC) $(SRV_SRC_BONUS) $(LIB) libft/libft.a -o server
