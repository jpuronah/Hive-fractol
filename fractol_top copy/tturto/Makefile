# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 08:17:31 by tturto            #+#    #+#              #
#    Updated: 2022/10/15 18:04:27 by jpuronah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDES =	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBFT = make -C ./libft/
LIBFTA = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SOURCES =	main.c initialize_min_max_iter.c key_events.c \
			colour.c c_julia.c \
			mandelbrot.c julia.c tricorn.c \
			mouse_zoom.c mouse_events_julia.c \

LINKSHOME = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): 
	@ $(LIBFT)
	@ gcc -c $(FLAGS) $(SOURCES)	
	@ gcc -o $(NAME) $(OBJECTS) $(LIBFTA) $(LINKSHOME) 
	@echo "Compilation has been completed"

clean:
	@ rm -f $(OBJECTS)
	@ $(LIBFT) clean
	@ echo "'clean' has been completed"

fclean: clean
	@ rm -f $(NAME)
	@ $(LIBFT) fclean
	@ echo "'fclean' has been completed"

re: fclean all
