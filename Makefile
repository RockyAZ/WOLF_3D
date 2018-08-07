#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 17:30:31 by azaporoz          #+#    #+#              #
#    Updated: 2018/07/23 17:30:31 by azaporoz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SOURCE = main.c \
			additional.c \
			error.c \
			reader.c \
			prepare.c \
			ray_casting.c \
			keys.c \
			draw_line.c \
			action.c
 # SOURCE = texture.c 

GLFW_INC = -I ./include/
GLFW_LIB = ./GLFW/libglfw3.a

GLEW_INC = -I ./include/
GLEW_LIB = ./GLEW/libGLEW.a

SOIL_INC = -I ./inclide/
SOIL_LIB = ./include/libSOIL.a


LIBFT_INC = -I ./libft/
LIBFT_LIB = ./libft/libft.a

FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

all:
	@gcc  -o $(NAME) $(SOURCE) $(GLFW_INC) $(GLFW_LIB) $(GLEW_INC) $(GLEW_LIB) $(SOIL_INC) $(SOIL_LIB) $(LIBFT_LIB) $(LIBFT_INC) $(FRAMEWORKS)

	@printf "\033[0;31m\
卐卐卐卐卐卐卐卐卐▄▄卐卐卐卐卐卐卐卐卐卐\n\
卐卐卐卐卐卐卐▄▀卐卐▀▄卐卐卐卐卐卐卐卐卐\n\
卐卐卐卐卐卐▄▀卐卐卐▄▀█卐卐卐卐卐卐卐卐卐\n\
卐卐卐卐卐▄▀卐卐卐▄▀░▄▀░▄▀▄▄卐卐卐卐卐卐\n\
卐卐卐卐▄▀卐卐卐▄▀░▄▀░▄▀卐卐▀▄卐卐卐卐卐\n\
卐卐卐卐█▀▄卐卐卐▀█░▄▀卐卐卐卐▀▄卐卐卐卐\n\
卐卐▄▀▄░▀▄░▀▄卐卐卐▀卐卐卐▄█▄卐卐▀▄卐卐\n\
卐▄▀卐卐▀▄░▀▄░▀▄卐卐卐卐▄▀░█░▀▄卐卐▀▄卐\n\
卐█▀▄卐卐卐▀▄░█▀卐卐卐卐▀█░▀▄░▀▄░▄▀█卐\n\
卐▀▄░▀▄卐卐卐▀卐卐卐▄█▄卐卐卐▀▄░▀▄░█░▄▀\n\
卐卐▀▄░▀▄卐卐卐卐▄▀░█░▀▄卐卐卐▀▄░▀█▀卐卐\n\
卐卐卐▀▄░▀▄░▄▀░▄▀░█▀卐卐卐▄▀█卐卐卐卐卐\n\
卐卐卐卐▀▄░█░▄▀░▄▀卐卐卐▄▀░▄▀卐卐卐卐卐\n\
卐卐卐卐卐▀█▀░▄▀卐卐卐▄▀░▄▀卐卐卐卐卐卐\n\
卐卐卐卐卐卐卐卐█▀▄░▄▀░▄▀卐卐卐卐卐卐卐\n\
卐卐卐卐卐卐卐卐▀▄░█░▄▀卐卐卐卐卐卐卐卐\n\
卐卐卐卐卐卐卐卐卐▀█▀卐卐卐卐卐卐卐卐卐\n"