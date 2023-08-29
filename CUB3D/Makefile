# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 08:38:50 by akastler          #+#    #+#              #
#    Updated: 2023/08/17 15:18:47 by akastler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c\
	   ./core/utils/init.c\
	   ./core/utils/init2.c\
	   ./core/utils/utils_tab.c\
	   ./core/utils/utils_string.c\
	   ./core/utils/utils_graph.c\
	   ./core/utils/utils_other.c\
	   ./core/verifs/check_file.c \
	   ./core/verifs/check_file2.c \
	   ./core/verifs/flood1.c \
	   ./core/verifs/flood2.c \
	   ./core/graphic/graphic.c \
	   ./core/graphic/move.c \
	   ./core/graphic/move2.c \
	   ./core/graphic/move3.c \
	   ./core/graphic/loop.c \
	   ./core/graphic/raycasting.c \
	   ./core/graphic/build_the_world.c \
	   ./core/graphic/n_s_w_e.c \
	   ./core/graphic/minimap.c \
	   ./core/graphic/texture.c \
	   ./core/graphic/door_and_cursor.c \

SRCS_BONUS = main.c\
	   ./core/utils/init.c\
	   ./core/utils/init2.c\
	   ./core/utils/utils_tab.c\
	   ./core/utils/utils_string.c\
	   ./core/utils/utils_graph.c\
	   ./core/utils/utils_other.c\
	   ./core/verifs/check_file.c \
	   ./core/verifs/check_file2.c \
	   ./core/bonus/verif_bonus.c \
	   ./core/bonus/verif_bonus2.c \
	   ./core/bonus/graphic_bonus.c \
	   ./core/graphic/move.c \
	   ./core/graphic/move2.c \
	   ./core/graphic/move3.c \
	   ./core/graphic/loop.c \
	   ./core/graphic/raycasting.c \
	   ./core/graphic/build_the_world.c \
	   ./core/graphic/n_s_w_e.c \
	   ./core/graphic/minimap.c \
	   ./core/graphic/texture.c \
	   ./core/graphic/door_and_cursor.c \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc -Wall -Wextra -Werror -g3

RM = rm -rf

MLX42 = ./.MLX42/build/libmlx42.a -I include -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

LIBS = ./core/utils/libft/libft.a ./core/utils/get_next_line/gnl.a

.PHONY: all bonus debug clean fclean re fclean_libs clean_libs re_all

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./core/utils/libft/
	@make -C ./core/utils/get_next_line/
	@echo "Libs compileded"
	$(RM) ./core/bonus/verif_bonus.o ./core/bonus/verif_bonus2.o ./core/bonus/graphic_bonus.o
	cd .MLX42 && cmake -B build && cmake --build build -j4
	$(CC) $(OBJS) $(LIBS) $(MLX42) -o $(NAME)
	@echo "cub3D compileded"

bonus: $(OBJS_BONUS)
	@make -C ./core/utils/libft/
	@make -C ./core/utils/get_next_line/
	@echo "Libs compileded"
	cd .MLX42 && cmake -B build && cmake --build build -j4
	$(CC) $(OBJS_BONUS) $(LIBS) $(MLX42) -o $(NAME)
	@echo "cub3D_bonus compileded"
	$(RM) ./core/verifs/flood1.o ./core/verifs/flood2.o ./core/graphic/graphic.o

debug: $(OBJS)
	@make -C ./core/utils/libft/
	@make -C ./core/utils/get_next_line/
	@echo "Libs compileded"
	$(CC) -fsanitize=address $(OBJS) $(LIBS) $(MLX42) -o $(NAME)
	@echo "cub3D compileded (debug mode)"

re: fclean all

re_all: fclean fclean_libs all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "cub3D cleaned"

fclean: clean
	$(RM) $(NAME) $(OBJS_BONUS)
	@echo "cub3D fcleaned"

clean_libs:
	@make clean -C ./core/utils/libft/
	@make clean -C ./core/utils/get_next_line/
	$(RM) .MLX42/build
	@echo "Libs cleaned"

fclean_libs:
	@make fclean -C ./core/utils/libft/
	@make fclean -C ./core/utils/get_next_line/
	$(RM) .MLX42/build
	@echo "Libs fcleaned"
