NAME = cube3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -Iinclude -Ilibs/MLX42-master/include -I/usr/include/GLFW
CFLAGSSAN = -fsanitize=address -g3
# CFLAGS += -fsanitize=address -g3

MLX42_DIR = libs/MLX42-master/build
MLX42_LIB = $(MLX42_DIR)/libmlx42.a
MLX42_FLAGS = -lglfw -pthread -lm -ldl

INCLUDE_FILES = cube3d.h structs.h defines.h
INCLUDES = $(addprefix include/, $(INCLUDE_FILES))

CUBE3D_FILES = \
	main.c init.c debug.c cleanup.c \
	handle_keys.c handle_mouse.c \
	ui_animation.c ui_load_frames.c \
	map_setup.c map_parse.c map_parse_utils.c \
	map_validate.c map_validate_utils.c map_floodfill.c map_players.c \
	rc_setup.c rc_render.c rc_draw.c counter.c

GET_NEXT_LINE_FILES = \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

LIBFT_FILES = \
	ft_atoi.c ft_itoa.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strchr.c ft_strncmp.c ft_strdup.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
	ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strjoin.c ft_striteri.c ft_strtrim.c

# Add path prefixes
CUBE3D_SRC = $(addprefix src/, $(CUBE3D_FILES))
GET_NEXT_LINE_SRC = $(addprefix src/, $(GET_NEXT_LINE_FILES))
LIBFT_SRC = $(addprefix src/libft/, $(LIBFT_FILES))
SRC = $(CUBE3D_SRC) $(GET_NEXT_LINE_SRC) $(LIBFT_SRC)

OBJ_DIR = objs
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Tell make where to find .c sources
vpath %.c src src/get_next_line src/libft

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# debug tests
test: re
	@./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

valgrind: re
	valgrind ./$(NAME) $(filter-out $@,$(MAKECMDGOALS)) > valgrind_out.txt 2>&1
	grep -A20 "definitely lost" valgrind_out.txt > valgrind_out_def.txt
	@cat valgrind_out_def.txt

valgrind+: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		./$(NAME) $(filter-out $@,$(MAKECMDGOALS)) > valgrind_out.txt 2>&1
	grep -A20 "definitely lost" valgrind_out.txt > valgrind_out_def.txt
	@cat valgrind_out_def.txt

sani: re
	$(CC) $(CFILES) $(CFLAGS) $(CFLAGSSAN) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)
	@./$(NAME) $(filter-out $@,$(MAKECMDGOALS))


# install tools
winstall:
	sudo apt-get update
	sudo apt-get install -y cmake libgl-dev libglx-dev libglu-dev mesa-common-dev \
		libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
	sudo apt-get install libglfw3-dev
	sudo apt-get install build-essential
	sudo apt-get install libc6-dev
	sudo apt update
	sudo apt install libglfw3-dev

libs:
	@echo "Cleaning MLX42..."
	@rm -rf libs/MLX42-master
	@echo "Cloning MLX42 from GitHub..."
	@git clone https://github.com/codam-coding-college/MLX42.git libs/MLX42-master
	@mkdir -p libs/MLX42-master/build
	@cd libs/MLX42-master && cmake -B build && cmake --build build --parallel
	@rm -rf libs/MLX42-master/build/.github

.PHONY: all clean fclean re winstall libs test valgrind sani
