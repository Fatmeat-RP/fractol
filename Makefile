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

NAME		=	$(BUILDDIR)fractol

BONUS_NAME	=	$(BUILDDIR)fractol_bonus

OBJSDIR		=	objs/

BUILDDIR	=	build/

SRCSDIR		=	srcs/

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror

BONUSDIR	=	bonussrcs/

LIBS		=	-L mlx -l mlx

HEADERDIR	=	include/

HEADER		=	${HEADERDIR}fractol.h

OBJS		=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

BONUS_OBJS	=	$(SRCSBONUS:$(SRCSBONUSDIR)%.c=$(OBJSDIR)%.o)

SRCS		= 	$(wildcard $(SRCSDIR)*.c)

SRCSBONUS	=	$(wildcard $(SRCSBONUSDIR)*.c)

FRAMEWORKS	=	-framework OpenGL -framework Appkit

INCLUDES	=	-I include -I mlx

##############################################################
####################### MAKE RULES ###########################
##############################################################


${NAME}	:	${OBJS}
			make -C mlx
			mkdir -p $(BUILDDIR)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEWORKS)

bonus	:	$(BONUS_OBJS)
			make -C mlx
			$(CC) $(FLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIB_FLAG) $(MLX_FLAGS)

${OBJS}	:	${OBJSDIR}%.o	:	${SRCSDIR}%.c ${HEADER}
			mkdir -p $(OBJSDIR)
			$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all		:	$(NAME)

clean	:
			rm -rf $(OBJSDIR)

fclean	:	clean
			make clean -C mlx
			rm -rf $(BUILDDIR)

re		:	fclean all