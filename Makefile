NAME = cub3D

CC = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L.. -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

SRC = main.c draw.c draw2.c draw3.c func.c parse1.c parse2.c parse3.c screenshot.c

LIBFT_DIR = libft
LIBS = libft/libft.a

OBJS = $(SRC:.c=.o)

HEADER = cub3d.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBS) $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(SRC) $(FLAGS2) $(LIBS) -o cub3D

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
