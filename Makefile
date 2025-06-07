# Basic setup
NAME = cube3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -Iinclude -Ilibs/MLX42-master/include -I/usr/include/GLFW
CFLAGSSAN = -fsanitize=address -g

# Directory variables
MLX42_DIR = libs/MLX42-master/build
MLX42_LIB = $(MLX42_DIR)/libmlx42.a
GLFW_LIB = $(MLX42_DIR)/_deps/glfw-build/src/libglfw3.a
MLX42_FLAGS = -lglfw -pthread -lm -ldl

# Source Files
CFILES = $(CUBE3D_FILES) $(GET_NEXT_LINE_FILES) $(LIBFT_FILES)
OBJS = $(CFILES:.c=.o)

CUBE3D_FILES = 			src/main.c \
						src/init.c \
						src/debug.c \
						src/cleanup.c \
						src/map_setup.c \
						src/map_parse.c \
						src/map_parse_utils.c \
						src/map_validate.c \
						src/map_validate_utils.c \
						src/map_floodfill.c

GET_NEXT_LINE_FILES = 	src/get_next_line/get_next_line.c\
						src/get_next_line/get_next_line_utils.c

LIBFT_FILES =			src/libft/ft_atoi.c\
						src/libft/ft_itoa.c\
						src/libft/ft_bzero.c\
						src/libft/ft_calloc.c\
						src/libft/ft_isalnum.c\
						src/libft/ft_isalpha.c\
						src/libft/ft_isascii.c\
						src/libft/ft_isdigit.c\
						src/libft/ft_isprint.c\
						src/libft/ft_memchr.c\
						src/libft/ft_memcmp.c\
						src/libft/ft_memcpy.c\
						src/libft/ft_memmove.c\
						src/libft/ft_memset.c\
						src/libft/ft_strchr.c\
						src/libft/ft_strncmp.c\
						src/libft/ft_strdup.c\
						src/libft/ft_strlcat.c\
						src/libft/ft_strlcpy.c\
						src/libft/ft_strlen.c\
						src/libft/ft_strnstr.c\
						src/libft/ft_strrchr.c\
						src/libft/ft_substr.c\
						src/libft/ft_tolower.c\
						src/libft/ft_toupper.c\
						src/libft/ft_putchar_fd.c\
						src/libft/ft_putendl_fd.c\
						src/libft/ft_putnbr_fd.c\
						src/libft/ft_putstr_fd.c\
						src/libft/ft_split.c\
						src/libft/ft_strjoin.c\
						src/libft/ft_striteri.c\
						src/libft/ft_strtrim.c\


# Build rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

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
