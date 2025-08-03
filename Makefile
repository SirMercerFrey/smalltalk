# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 15:38:53 by mcharret          #+#    #+#              #
#    Updated: 2025/08/03 15:38:59 by mcharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= server client
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
OBJ_DIR		= obj

SRC_SERVER	= server.c global.c utils.c
SRC_CLIENT	= client.c utils.c

OBJ_SERVER	= $(SRC_SERVER:%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT	= $(SRC_CLIENT:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all server client clean fclean re
