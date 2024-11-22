compile: compile_libs compile_fdf reset_libs

std_run: compile
	@./fdf test_maps/42.fdf

test_run: compile
	@./fdf test_maps/test.fdf

run: compile
	@read -p "Enter file dir: " dir; \
	./fdf $$dir

compile_fdf:
	@cc -g srcs/*.c \
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

compile_libs:
	@make -sC libs/libft
	@make -sC libs/ft_printf
	@make -sC libs/get_next_line 
	@make -sC libs/minilibx-linux
	@make clean -sC libs/libft
	@make clean -sC libs/ft_printf
	@make clean -sC libs/get_next_line

valgrind: compile
	@read -p "Enter file dir: " dir; \
	valgrind ./fdf $$dir

update_libs:
	@git submodule update --init --recursive --remote

reset_libs:
	@cd libs/get_next_line && rm -f *.a
	@cd libs/libft && rm -f *.a
	@cd libs/ft_printf && rm -f *.a


git_push: update_libs
	@git add .
	@read -p "Enter commit message: " message; \
    git commit -m "$$message"
	@git push
