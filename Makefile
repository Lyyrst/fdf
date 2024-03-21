# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 09:30:01 by kbutor-b          #+#    #+#              #
#    Updated: 2024/03/05 11:01:18 by kbutor-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADERS = src/fdf.h 

LIBFT = libft/libft.a

MLX = MacroLibX/libmlx.so

CFILES = src/main.c \
			src/make_array.c \
			src/fill_array.c \
			src/utils.c \
			src/event.c \
			src/image.c \
			src/get_struct.c \
			src/event_utils.c

OFILES = $(CFILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(MLX) $(LIBFT) $(NAME)

$(MLX) :
	$(MAKE) -C MacroLibX all

$(LIBFT) :
	$(MAKE) -C libft all

$(NAME): $(OFILES)
	$(CC) $(OFILES) $(MLX) $(LIBFT) -o $(NAME) -lSDL2 -lm

clean :
	$(MAKE) -C libft clean
	$(MAKE) -C MacroLibX clean
	rm -rf $(OFILES)

fclean : clean
	$(MAKE) -C libft fclean
	$(MAKE) -C MacroLibX fclean
	rm -rf $(NAME)

re : fclean all

.PHONY :
	all clean fclean re
