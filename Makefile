# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 11:39:06 by juasanto          #+#    #+#              #
#    Updated: 2020/10/02 11:29:18 by juasanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Formato basico de MakeFile
#objetivo: dependencias
#		instrucciones

SRCS = main.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
RM = rm -f

NAME = GNL.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
