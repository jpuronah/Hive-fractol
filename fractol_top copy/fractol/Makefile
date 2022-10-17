# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:44:35 by jpuronah          #+#    #+#              #
#    Updated: 2022/10/15 22:00:25 by jpuronah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SOURCES = main.c graphics.c image.c keyboard.c \
projection1_mandelbrot.c projection2_julia.c projection3.c 
OBJECTIVES = $(SOURCES:.c=.o)
LIBFT = ./libft/
CFLAGS = -Wall -Wextra -Werror 
MLX = -L /usr/local/lib -lmlx -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit
LINKSHOME = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc -c $(CFLAGS) $(SOURCES)
	gcc $(OBJECTIVES) $(CFLAGS) -o $(NAME) $(MLX) -Llibft -lft $(LINKSHOME)

nf:
	gcc -c $(CFLAGS) $(SOURCES)
	gcc $(OBJECTIVES) $(CFLAGS) -o $(NAME) $(MLX) -Llibft -lft $(LINKSHOME)
	/bin/rm -f $(OBJECTIVES)
	make -C $(LIBFT) clean

clean:
	/bin/rm -f $(OBJECTIVES)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
