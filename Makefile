# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 11:57:48 by aanouari          #+#    #+#              #
#    Updated: 2023/03/22 02:49:40 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC	= client

NAMES	= server

SRCSVR	=	server.c

SRCCLT	=	client.c

LIBFT=	libft


NO_COLOR    =	\033[0m
GREEN		=	\033[0;1;92m
RED			=	\033[0;1;91m
BLUE		=	\33[0;1;94m


OBJSVR = $(SRCSVR:.c=.o)
OBJCLT = $(SRCCLT:.c=.o)


SOURCES = $(wildcard $(LIBFT)/*.c)


CC = cc


CFLAGS = -Wall -Wextra -Werror


RM = rm -rf


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RED)\r LOADING...$(NO_COLOR)"


all: $(NAMEC) $(NAMES)


$(NAMEC): $(OBJCLT) $(SOURCES)
	@$(CC) $(OBJCLT) $(SOURCES) -o $(NAMEC)
	@printf "$(GREEN)\r SERVER SUCCESSFULLY MADE!!\n$(NO_COLOR)"


$(NAMES): $(OBJSVR) $(SOURCES)
	@$(CC) $(OBJSVR) $(SOURCES) -o $(NAMES)
	@printf "$(GREEN)\r CLIENT IS READY!!\n$(NO_COLOR)"


clean:
	@$(RM) $(OBJSVR) $(OBJCLT)
	@printf "$(BLUE)\r Done Cleaning!!\n$(NO_COLOR)"


fclean:	clean
	@$(RM) $(NAMEC) $(NAMES)


re:				fclean all