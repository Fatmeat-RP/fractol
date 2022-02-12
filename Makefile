# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 10:55:45 by acarle-m          #+#    #+#              #
#    Updated: 2022/02/12 19:52:46 by acarle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILDDIR)fractol

BONUS_NAME		=	$(BUILDDIR)fractol_bonus

OBJSDIR			=	objs/

BONUS_OBJSDIR	=	bonus_objs/

BUILDDIR		=	build/

SRCSDIR			=	srcs/

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

BONUSDIR		=	bonus_srcs/

HEADERDIR		=	include/

HEADER			=	${HEADERDIR}fractol.h ${HEADERDIR}ft_fprintf.h

OBJS			=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

BONUS_OBJS		=	$(SRCSBONUS:$(BONUSDIR)%.c=$(BONUS_OBJSDIR)%.o)

SRCS			= 	$(wildcard $(SRCSDIR)*.c)

SRCSBONUS		=	$(wildcard $(BONUSDIR)*.c)

INCLUDES		=	-I include -I mlx

LIBS			=	-L mlx -l mlx

MLX				=	mlx

FRAMEWORKS		=	-framework OpenGL -framework Appkit

##############################################################
####################### MAKE RULES ###########################
##############################################################

all			:	mandatory bonus

mandatory	:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX)
			mkdir -p $(BUILDDIR)
			$(CC) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEWORKS)

$(OBJS)		:	$(OBJSDIR)%.o		:	$(SRCSDIR)%.c $(HEADER)
			mkdir -p $(OBJSDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus		:	$(BONUS_NAME)

$(BONUS_NAME)	:	$(BONUS_OBJS)
			make -C $(MLX)
			mkdir -p $(BUILDDIR)
			$(CC) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBS) $(FRAMEWORKS)

$(BONUS_OBJS)	:	$(BONUS_OBJSDIR)%.o	:	$(BONUSDIR)%.c $(HEADER)
			mkdir -p $(BONUS_OBJSDIR)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean		:
			rm -rf $(OBJSDIR)
			rm -rf $(BONUS_OBJSDIR)

fclean		:	clean
			make clean -C mlx
			rm -rf $(BUILDDIR)

re			:	fclean all
