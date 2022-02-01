# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 10:55:45 by acarle-m          #+#    #+#              #
#    Updated: 2022/02/01 11:57:03 by acarle-m         ###   ########.fr        #
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

BONUSDIR		=	bonussrcs/

HEADERDIR		=	include/

HEADER			=	${HEADERDIR}fractol.h

OBJS			=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

BONUS_OBJS		=	$(SRCSBONUS:$(SRCSBONUSDIR)%.c=$(BONUS_OBJSDIR)%.o)

SRCS			= 	$(wildcard $(SRCSDIR)*.c)

SRCSBONUS		=	$(wildcard $(SRCSBONUSDIR)*.c)

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX			=	mlx_linux
	GCL			=	git clone https://github.com/42Paris/minilibx-linux.git smlx_linux
	CC1			=	$(CC) $(OBJS) -Lmlx_linux mlx_linux/libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	CC2			=	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -Iinclude -O3 -c $< -o $@
else
	INCLUDES	=	-I include -I mlx
	LIBS		=	-L mlx -l mlx
	MLX			=	mlx
	FRAMEWORKS	=	-framework OpenGL -framework Appkit
	GCL			=	
	CC1			=	$(CC) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEWORKS)
	CC2			=	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
endif


##############################################################
####################### MAKE RULES ###########################
##############################################################

$(NAME)		:	$(OBJS)
			make -C $(MLX)
			mkdir -p $(BUILDDIR)
			$(CC1)

#$(NAME_BONUS)	:	$(BONUS_OBJS)
#			make -C $(MLX)
#			mkdir -p $(BUILDDIR)
#			$(CC) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBS) $(FRAMEWORKS)

$(OBJS)		:	$(OBJSDIR)%.o		:	$(SRCSDIR)%.c $(HEADER)
			mkdir -p $(OBJSDIR)
			$(CC2)

#$(BONUS_OBJS)	:	$(BONUS_OBJSDIR)%.o	:	$(SRCSBONUSDIR)%.c $(HEADER)
#			mkdir -p $(BONUS_OBJSDIR)
#			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all			:	mandatory #bonus
				$(GCL)

mandatory	:	$(NAME)

#bonus		:	$(NAME_BONUS)

clean		:
			rm -rf $(OBJSDIR)

fclean		:	clean
			make clean -C mlx
			rm -rf $(BUILDDIR)

re		:	fclean all
