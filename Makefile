RED	=\033[0;31m
BLUE	=\033[0;34m
WHITE	=\033[0;37m
YELLOW	=\033[0;33m

CC		= cc
RM		= rm -rf
NAME		= cub3D
CFLAGS		= -Wall -Wextra -Werror
LMLX_LINUX	= -lXext -lX11 -lm -lz
MLX_LINUX	= minilibx-linux/libmlx.a $(LMLX_LINUX)

SOURCES =	parsing/parsing.c \
	   parsing/open_file.c \
	   parsing/read_element.c \
	   parsing/read_map.c \
	   parsing/read_file.c \
	   parsing/test_map.c \
	   parsing/test_file.c \
	   parsing/error.c \
	   minilibft/ft_bzero.c \
	   minilibft/ft_calloc.c \
	   minilibft/ft_gnl.c \
	   minilibft/ft_isspace.c \
	   minilibft/ft_memset.c \
	   minilibft/ft_memcpy.c \
	   minilibft/ft_split.c \
	   minilibft/ft_strdup.c \
	   minilibft/ft_strjoin.c \
	   minilibft/ft_strlen.c \
	   minilibft/ft_strncmp.c \
	   minilibft/ft_strrchr.c \
	   minilibft/ft_strlcpy.c \
	   main.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@echo "$(YELLOW)>>>>> Minilibx Library Compiling <<<<<$(WHITE)"
		@make -sC ./minilibx-linux/
		@echo "$(YELLOW)>>>> Cub3d Compiling <<<<<$(WHITE)"
		@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LINUX) -o $(NAME)
		@echo "$(BLUE)>>>>> Done <<<<<$(WHITE)"

clean:
		@$(RM) $(OBJECTS)
		@make clean -sC ./minilibx-linux/
		@echo "$(RED)>>>>> Deleted <<<<<$(WHITE)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)>>>>> Full Deleted <<<<<$(WHITE)"

re: fclean all

norm:
	@norminette $(SOURCES)

.PHONY: all clean fclean re 
