# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 16:04:15 by opavliuk          #+#    #+#              #
#    Updated: 2018/05/14 13:31:16 by opavliuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 
CFLAGS=-Wall -Werror -Wextra
SRC=./filler.c \
	./check_input.c \
	./work_with_figure.c
	
OBJ=$(SRC:.c=.o)
LIB = libft/libft.a
VISRC= ./visualsrc/visualizer.c \
		./visualsrc/drawing_net.c \
		./visualsrc/drawing_game.c \
		./visualsrc/check_file.c
NAME=opavliuk.filler
VISNAME = visualizer

all: $(NAME)

%.o: fillsrc/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I fillsrc/

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	$(CC) $(VISRC) $(LIB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(VISNAME) -I /usr/local/include 
	@ printf "\e[37;1m[\e[33;1mlibft.a \e[37;1mis \e[32;1mREADY!\e[37;1m]\e[0m\n"
	@ printf "\e[37;1m[Player \e[31;1mopavliuk.filler \e[37;1mis \e[32;1mREADY FOR GAME!\e[37;1m]\e[0m\n"
	@ printf "\e[37;1m[\e[31;1mV\e[33;1mi\e[31;1ms\e[33;1mu\e[31;1ma\e[33;1ml\e[31;1mi\e[33;1mz\e[31;1me\e[33;1mr \e[31;1m \e[37;1mis \e[32;1mREADY TO SHOW!\e[37;1m]\e[0m\n"

$(LIB):
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfiller/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mCLEAN!\e[37;1m]\e[0m\n"

fclean: clean
	rm -f $(NAME) $(VISNAME)
	make fclean -C libft/
	@ printf "\e[37;1m[Directories \e[33;1mfiller/ \e[37;1m&& \e[33;1mlibft/ \e[37;1mis \e[32;1mFCLEAN!\e[37;1m]\e[0m\n"

re: fclean all

.PHONY: all, clean, fclean, re