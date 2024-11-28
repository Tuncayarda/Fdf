NAME = fdf
CC = cc
MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Wextra -Werror
LIBFT = libs/libft/libft.a
GNL = libs/get_next_line/get_next_line.a
PRINTF = libs/ft_printf/libftprintf.a
MINILIBX = libs/minilibx-linux/libmlx_Linux.a

SRCS = srcs/checkFile.c \
		srcs/close.c \
		srcs/confMap.c \
		srcs/control.c \
		srcs/control1.c \
		srcs/drawMap.c \
		srcs/drawUtils.c \
		srcs/drawUtils1.c \
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

OBJS = $(SRCS:.c=.o)

WIDTH = 1920
HEIGHT = 1080

all: default 

default: CFLAGS += -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT)
default: $(NAME)

2k: WIDTH = 2560
2k: HEIGHT = 1440
2k: CFLAGS += -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT)
2k: $(NAME)

4k: WIDTH = 3840
4k: HEIGHT = 2160
4k: CFLAGS += -D WIDTH=$(WIDTH) -D HEIGHT=$(HEIGHT)
4k: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(PRINTF) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) \
	$(LIBFT) \
	$(PRINTF) \
	$(GNL) \
	-L./libs/minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
	@make clean
	@echo DONE!

%.o: %.c
	@$(CC) $(CFLAGS) -c \
	-I./inc \
	-I./libs/libft \
	-I./libs/ft_printf \
	-I./libs/get_next_line \
	-I./libs/minilibx-linux $< -o $@

$(LIBFT):
	@make -sC libs/libft

$(GNL):
	@make -sC libs/get_next_line

$(PRINTF):
	@make -sC libs/ft_printf

$(MINILIBX):
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux
	@make -sC libs/minilibx-linux 1> /dev/null 2> /dev/null

clean:
	@make fclean -sC libs/libft
	@make fclean -sC libs/get_next_line
	@make fclean -sC libs/ft_printf
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME) libs/minilibx-linux

re: fclean all

update_libs:
	@git submodule update --init --recursive --remote

git_push: update_libs
	@git add .
	@read -p "Enter commit message: " message; \
	git commit -m "$$message"
	@git push

.PHONY: all clean fclean re update_libs git_push
