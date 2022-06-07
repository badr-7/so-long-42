NAME = so_long

HEADER = so_long.h

CC = gcc

FLAGS = -Wextra -Wall -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

MAKE = make -C

SRC =	ft_map.c\
		ft_map2.c\
		ft_map_dep.c\
		main.c\
		ft_images.c\
		moves.c\
		moves2.c\

OBJ = ${SRC:.c=.o}


${NAME}: ${OBJ} cmp_libft 
	 	${CC} ${FLAGS} ${MLX_FLAGS} ${OBJ} libft/libft.a -o $(NAME)

cmp_libft:
	@$(MAKE) libft

clean:
	${RM} ${OBJ}

fclean:
	${RM} ${OBJ} ${NAME}