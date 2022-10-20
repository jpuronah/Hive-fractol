# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpuronah <jpuronah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:44:35 by jpuronah          #+#    #+#              #
#    Updated: 2022/10/19 23:55:17 by jpuronah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCES = main.c graphics.c image.c keyboard.c \
projection1_mandelbrot.c projection2_julia.c projection3.c \
main_help.c mouse.c
OBJECTIVES = $(SOURCES:.c=.o)
DIR_S = srcs
DIR_O = obj
LIBFT = ./libft/
CFLAGS = -Wall -Wextra -Werror 
MLX = -L /usr/local/lib -lmlx -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit
LINKSHOME = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

$(DIR_O) = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@echo "libft compiled"
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/main.o -c $(DIR_S)/main.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/main_help.o -c $(DIR_S)/main_help.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/graphics.o -c $(DIR_S)/graphics.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/image.o -c $(DIR_S)/image.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/keyboard.o -c $(DIR_S)/keyboard.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection1_mandelbrot.o -c $(DIR_S)/projection1_mandelbrot.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection2_julia.o -c $(DIR_S)/projection2_julia.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection3.o -c $(DIR_S)/projection3.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/mouse.o -c $(DIR_S)/mouse.c
	@ar rc $(NAME) $($(DIR_O))

	gcc $($(DIR_O)) $(CFLAGS) -o $(NAME) $(MLX) -Llibft -lft $(FRAMEWORK)
	@echo "fractol COMPILED"

nf: clean
	@/bin/rm -f $(NAME)
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/main.o -c $(DIR_S)/main.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/main_help.o -c $(DIR_S)/main_help.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/graphics.o -c $(DIR_S)/graphics.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/image.o -c $(DIR_S)/image.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/keyboard.o -c $(DIR_S)/keyboard.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection1_mandelbrot.o -c $(DIR_S)/projection1_mandelbrot.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection2_julia.o -c $(DIR_S)/projection2_julia.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/projection3.o -c $(DIR_S)/projection3.c
	@mkdir -p $(DIR_O)
	@gcc -c $(FLAGS) -I includes -o $(DIR_O)/mouse.o -c $(DIR_S)/mouse.c
	@ar rc $(NAME) $($(DIR_O))

	gcc $($(DIR_O)) $(CFLAGS) -o $(NAME) $(MLX) -Llibft -lft $(FRAMEWORK)
	@echo "fractol COMPILED"

clean:
	make -C $(LIBFT) clean
	@rm -f $($(DIR_O))
	@rm -rf $(DIR_O)

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
