# Lib
NAME = libft.a

# CC
CC = cc

# Files
CFILES = ft_atoi.c\
ft_itoa.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_strchr.c\
ft_strncmp.c\
ft_strdup.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strnstr.c\
ft_strrchr.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_itoa.c\
ft_memchr.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strdup.c\
ft_strmapi.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c

# Dir
HEADER_DIR = /

# Files .c to .o
OBJS = $(CFILES:.c=.o)

# Flags
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	echo "compiling $(NAME) creating files"
	ar rcs $(NAME) $(OBJS)
	
clean:
	echo "Removing OBJECTS"
	rm -f $(OBJS)

fclean: clean
	echo "REMOVING $(NAME)"
	rm -f $(NAME)

re: fclean all