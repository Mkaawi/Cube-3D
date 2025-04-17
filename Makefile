CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MLXFLAGS = -ldl -lglfw -lm -lpthread -LMLX42/build -lmlx42 -IMLX42/include
CFILES    =   main.c \
            parsing/parsing.c \
            parsing/parse_map.c \
            parsing/fill_map.c \
            parsing/split_info.c \
            parsing/utils.c   \
            parsing/utils2.c   \
            parsing/utils3.c   \
            parsing/utils4.c   \
            raycasting/textures.c \
            raycasting/ray_main.c \
            raycasting/player.c \
            raycasting/map.c \
            raycasting/utils.c \
            raycasting/rays.c \
            raycasting/raycaster.c \
            get_next_line/get_next_line.c \

OFILES = $(CFILES:.c=.o)
LIBFT = libft.a
NAME = cube

all: libx $(LIBFT) $(NAME)

libx: 
	cd ./MLX42 && cmake -B build && cmake --build build -j4

$(LIBFT):
	cd ./libft && make

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) ./libft/$(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c cube.h g_header.h 
	$(CC) $(CFLAGS) -IMLX42/include -c $< -o $@ 

clean:
	rm -rf $(OFILES) 
	cd ./libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd ./libft && make fclean

re: fclean all
