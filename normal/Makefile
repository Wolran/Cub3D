# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:35:41 by vmuller           #+#    #+#              #
#    Updated: 2023/11/09 00:33:35 by vmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cube3d

# directories
SRCDIR	=	./srcs
INCDIR	=	-I ./inc
OBJDIR	=	./obj

# src / includes / obj files
SRC		=	main.c \
			 \
			game/init.c \
			game/destroy.c \
			 \
			camera.c \
			raycaster.c \
			cast_ray.c \
			 \
			parsing/map.c \
			parsing/elements.c \
			parsing/file.c \
			parsing/to_map.c \
			parsing/closed.c \
			parsing/utils.c \
			parsing/color_tint.c \
			 \
			map/getter.c \
			map/iterate.c \
			map/manager.c \
			map/setter.c \
			
			
INC		=	camera.h \
			map.h \
			raycaster.h \
			game.h \
			camera.h \
			parsing.h \
			cast_ray.h \

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

DEPENDS := $(patsubst %.o,%.d,$(OBJ))


# compiler
CC		= cc
CFLAGS	= -MMD -MP -Wall -Wextra -Werror

# engine library
ENGINE		= ../engine/
ENGINE_LIB	= $(addprefix $(ENGINE),libengine.a)
ENGINE_INC	= -I ../engine/inc
ENGINE_LNK	= -l Xext -l X11 -l Xfixes -L ../engine -l engine -l m

all: obj $(ENGINE_LIB) $(NAME)

raw: CFLAGS += -O0
raw: obj $(ENGINE_LIB) $(NAME)

fast: CFLAGS += -Ofast -mtune=corei7-avx
fast: obj $(ENGINE_LIB) $(NAME)

debug: CFLAGS += -gdwarf-4
debug: obj $(ENGINE_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

.print:
	@> $@
	@echo "\e[1;36mCompiling...\e[0m"

$(NAME): $(OBJ)
	@echo "\e[1;35mLinking...\e[0m"
	@$(CC) -o $(NAME) $+ $(ENGINE_LNK)
	@echo "\e[1;32m➤" $@ "created succesfully !\e[0m"

$(OBJDIR)/%.o: $(SRCDIR)/%.c .print
	@echo "\e[0;36m ↳\e[0;36m" $<"\e[0m"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCDIR) $(ENGINE_INC) -c $< -o $@

temp:
	@echo "\e[1;36mCompiling...\e[0m";

$(ENGINE_LIB):
	@make -C $(ENGINE)

clean:
	rm -rf $(OBJDIR)
	make -C $(ENGINE) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(ENGINE) fclean

re: fclean all

.PHONY: all clean fclean re

-include $(DEPENDS)
