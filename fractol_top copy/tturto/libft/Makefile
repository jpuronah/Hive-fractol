# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturto <tturto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 12:35:02 by tturto            #+#    #+#              #
#    Updated: 2022/08/23 20:27:38 by tturto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra 

SRCS =	./ft_atoi.c \
		./ft_bzero.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdup.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strstr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_memalloc.c \
		./ft_memdel.c \
		./ft_strnew.c \
		./ft_strdel.c \
		./ft_strclr.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strequ.c \
		./ft_strnequ.c \
		./ft_strsub.c \
		./ft_strjoin.c \
		./ft_strtrim.c \
		./ft_strsplit.c \
		./ft_itoa.c \
		./ft_putchar.c \
		./ft_putstr.c \
		./ft_putendl.c \
		./ft_putnbr.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_nb_strings.c \
		./ft_get_size.c \
		./ft_strndup.c \
		./ft_calloc.c \
		./ft_inthigher.c \
		./ft_sqrt.c \

OBJS = $(SRCS:.c=.o)
  
all: $(NAME)	
	
$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	 
clean:
	@/bin/rm -f *.o

fclean:	clean
	@/bin/rm -f *.a

re:	fclean all
