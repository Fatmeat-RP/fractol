# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 10:55:45 by acarle-m          #+#    #+#              #
#    Updated: 2022/02/14 11:36:58 by acarle-m         ###   ########.fr        #
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

SRCS			=	$(SRCSDIR)color.c				\
					$(SRCSDIR)fractal_operation.c	\
					$(SRCSDIR)fractal_set.c			\
					$(SRCSDIR)ft_fprintf.c			\
					$(SRCSDIR)ft_put.c				\
					$(SRCSDIR)ft_puthex.c			\
					$(SRCSDIR)ft_putp.c				\
					$(SRCSDIR)img_op.c				\
					$(SRCSDIR)input.c				\
					$(SRCSDIR)list.c				\
					$(SRCSDIR)string_operation.c	\
					$(SRCSDIR)utils.c				\
					$(SRCSDIR)win.c

SRCSBONUS		=	$(BONUSDIR)color_bonus.c				\
					$(BONUSDIR)fractal_operation_bonus.c	\
					$(BONUSDIR)fractal_set_bonus.c			\
					$(BONUSDIR)ft_fprintf_bonus.c			\
					$(BONUSDIR)ft_put_bonus.c				\
					$(BONUSDIR)ft_puthex_bonus.c			\
					$(BONUSDIR)ft_putp_bonus.c				\
					$(BONUSDIR)img_op_bonus.c				\
					$(BONUSDIR)input_bonus.c				\
					$(BONUSDIR)list_bonus.c					\
					$(BONUSDIR)string_operation_bonus.c		\
					$(BONUSDIR)utils_bonus.c				\
					$(BONUSDIR)win_bonus.c

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
