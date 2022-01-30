# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 10:55:45 by acarle-m          #+#    #+#              #
#    Updated: 2022/01/29 15:15:05 by acarle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	$(BUILDDIR)fractol

BONUS_NAME		=	$(BUILDDIR)fractol_bonus

OBJSDIR			=	objs/

BONUS_OBJSDIR	=	bonus_objs/

BUILDDIR			=	build/

SRCSDIR			=	srcs/

CC					=	gcc

CFLAGS			=	-Wall -Wextra -Werror

BONUSDIR			=	bonussrcs/


HEADERDIR		=	include/

HEADER			=	${HEADERDIR}fractol.h

OBJS				=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

BONUS_OBJS		=	$(SRCSBONUS:$(SRCSBONUSDIR)%.c=$(BONUS_OBJSDIR)%.o)

SRCS				= 	$(wildcard $(SRCSDIR)*.c)

SRCSBONUS		=	$(wildcard $(SRCSBONUSDIR)*.c)

FRAMEWORKS		=	-framework OpenGL -framework Appkit


UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	INCLUDES			=	-I include -I mlx_linux
	LIBS				=	-L mlx_linux -l mlx_linux
else
	INCLUDES			=	-I include -I mlx
	LIBS				=	-L mlx -l mlx
endif


##############################################################
####################### MAKE RULES ###########################
##############################################################

${NAME}			:	${OBJS}
						make -C mlx
						mkdir -p $(BUILDDIR)
						$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEWORKS)

$(NAME_BONUS)	:	$(BONUS_OBJS)
						make -C mlx
						mkdir -p $(BUILDDIR)
						$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIB_FLAG) $(MLX_FLAGS)

${OBJS}			:	${OBJSDIR}%.o	:	${SRCSDIR}%.c ${HEADER}
						mkdir -p $(OBJSDIR)
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

${BONUS_OBJS}	:	${BONUS_OBJSDIR}%.o	:	${SRCSBONUSDIR}%.c ${HEADER}
						mkdir -p $(BONUS_OBJSDIR)
						$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all				:	mandatory bonus

mandatory		:	$(NAME)

bonus				:	$(NAME_BONUS)

clean				:
						rm -rf $(OBJSDIR)

fclean			:	clean
						make clean -C mlx
						rm -rf $(BUILDDIR)

re					:	fclean all