NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libs/libft/libft.a
GNL = libs/get_next_line/get_next_line.a
PRINTF = libs/ft_printf/libftprintf.a
MINILIBX = libs/minilibx-linux/libmlx_Linux.a

SRCS = srcs/checkFile.c \
		srcs/close.c \
		srcs/confMap.c \
		srcs/control.c \
		srcs/drawMap.c \
		srcs/drawUtils.c \
		srcs/fdf.c \
		srcs/initStructs.c \
		srcs/mapUtils.c \
		srcs/mapUtils1.c \
		srcs/matrixUtils.c \
		srcs/menu.c \
		srcs/mlxUtils.c \
		srcs/parser.c \
		srcs/resizableArray.c \
		srcs/setInvisibles.c \
		srcs/terminate.c \
		srcs/utils.c

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(SRCS) \
	-I./inc \
	\
	-I./libs/libft \
	-I./libs/ft_printf \
	-I./libs/get_next_line \
	-I./libs/minilibx-linux \
	\
	libs/libft/libft.a \
	libs/ft_printf/libftprintf.a \
	libs/get_next_line/get_next_line.a \
	\
	-L./libs/minilibx-linux \
	-lmlx -lX11 -lXext -lm -o fdf

$(LIBFT):
	@make -sC libs/libft

$(GNL):
	@make -sC libs/get_next_line

$(PRINTF):
	@make -sC libs/ft_printf

$(MINILIBX):
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux  
	@make -sC libs/minilibx-linux

clean:
	@make fclean -sC libs/libft
	@make fclean -sC libs/get_next_line
	@make fclean -sC libs/ft_printf


fclean: clean
	@rm -rf $(NAME) libs/minilibx-linux

re: fclean all

.PHONY: all clean fclean re

update_libs:
	@git submodule update --init --recursive --remote

git_push: update_libs
	@git add .
	@read -p "Enter commit message: " message; \
    git commit -m "$$message"
	@git push
