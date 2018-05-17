#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:46:32 by sadamant          #+#    #+#              #
#    Updated: 2018/03/14 21:43:54 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIBWOLF = libwolf.a

SUBLIB1_DIR = libft
SUBLIB2_DIR = minilibx_macos

SUBLIB1 = libft/libft.a
SUBLIB2 = minilibx_macos/libmlx.a
SUBLIBS = $(SUBLIB1) $(SUBLIB2)

LIB = -L. -lwolf -L libft/ -lft -L minilibx_macos/ -lmlx

LIBNAME1 = libft.a
LIBNAME2 = libmlx.a

SRC = main.c image.c setup.c parse.c error.c keypress.c cast.c draw.c \
	render.c circle.c xpm.c mlx_helpers.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -c -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDES = -I libft/includes -I minilibx_macos/

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(INCLUDES)

libft:
	@$(MAKE) -C $(SUBLIB1_DIR)

minilibx:
	@$(MAKE) -C $(SUBLIB2_DIR)

$(NAME): libft minilibx $(OBJ)
	@ar -rc $(LIBWOLF) $(OBJ)
	@$(CC) $(LIB) $(FRAMEWORK) -o $(NAME)

clean:
	@$(MAKE) clean -C $(SUBLIB1_DIR)
	@$(MAKE) clean -C $(SUBLIB2_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(SUBLIB1_DIR)
	@$(MAKE) fclean -C $(SUBLIB2_DIR)
	@rm -rf $(NAME)
	@rm -rf $(LIBWOLF)

re: fclean all

pr:
	@rm -rf $(NAME)
	@$(CC) $(FLAGS) $(SRC) $(LIBS) $(INCLUDES) -o $(NAME)

.PHONY: all libs clean fclean re pr libft minilibx
