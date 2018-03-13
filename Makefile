# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:46:32 by sadamant          #+#    #+#              #
#    Updated: 2018/03/13 13:36:10 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIBNAME1 = libft.a
LIBNAME2 = libmlx.a

SRC = main.c image.c setup.c parse.c error.c keypress.c cast.c wall.c is_num.c \
	  render.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL

LIB1 = -L./$(LIBDIR1) -lft
LIB2 = -L./$(LIBDIR2) -lmlx
LIBMATH = -lm
LIBS = $(LIB1) $(LIB2) $(LIBMATH)
LIBDIR1 = libft/
LIBDIR2 = minilibx_macos/

INCLUDES = -I libft/includes -I minilibx_macos/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBDIR1)
	@$(MAKE) -C $(LIBDIR2)
	$(CC) $(FLAGS) $(SRC) $(LIBS) $(INCLUDES) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBDIR1)
	@$(MAKE) clean -C $(LIBDIR2)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBDIR1)/$(LIBNAME1)

re: fclean all

pr:
	@rm -rf $(NAME)
	$(CC) $(FLAGS) $(SRC) $(LIBS) $(INCLUDES) -o $(NAME)
