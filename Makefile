# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klin <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 12:25:55 by klin              #+#    #+#              #
#    Updated: 2018/05/24 18:15:27 by klin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = gcc
FLAG = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

LIBFTDIR = ./libft

SRC = main.c rot.c\
	  camera.c\
	  color.c\
	  light.c\
	  color1.c\
	  init.c\
	  obj.c sphere.c plan.c cone.c cylindre.c\
	  free.c\
	  vector.c vector1.c vector2.c \
	  draw.c\
	  ray.c\
	  read_scene.c read_scene1.c\
	  util.c util1.c\
	  key_hook.c key_hook2.c

OBJ = $(SRC:.c=.o)

HEAD = rtv1.h
GCH = $(HEAD:.h=.h.gch)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(FLAG) -c $(SRC) $(HEAD)
	$(CC) -o $(NAME) $(OBJ) $(LIBFTDIR)/libft.a $(MLX)

clean :
	rm -f $(OBJ) $(GCH)
	make clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME) $(LIBFTDIR)/libft.a

re : fclean all

.PHONY: all clean fclean re
