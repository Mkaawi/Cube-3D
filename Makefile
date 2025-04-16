NAME	= moraba3
CFLAGS = -Wextra -Wall -Werror 

LIBMLX	= /Users/$(USER)/MLX42
LIBFT = libft.a

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= 	main.c \
			parsing/parsing.c \
			parsing/parse_map.c \
			parsing/fill_map.c \
			parsing/split_info.c \
			parsing/utils.c   \
			parsing/utils2.c   \
			parsing/utils3.c   \
			raycasting/textures.c \
			raycasting/ray_main.c \
			raycasting/player.c \
			raycasting/map.c \
			raycasting/utils.c \
			raycasting/rays.c \
			raycasting/raycaster.c \
			get_next_line/get_next_line.c \
			
OBJS	= ${SRCS:.c=.o}

all: libmlx $(LIBFT) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c cube.h g_header.h
	@$(CC) $(CFLAGS)  -o $@ -c $< $(HEADERS)

$(LIBFT):
	cd ./libft && make

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) ./libft/$(LIBFT) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	cd ./libft && make clean

fclean: clean
	@rm -rf $(NAME)
	cd ./libft && make fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx