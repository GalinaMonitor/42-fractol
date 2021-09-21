NAME = fractol
CC = gcc

# FLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework Appkit -O3

LIB_DIR = lib/
SRC_DIR = src/
INC_DIR = include/
WORK_DIR = $(addprefix ../, $(NAME))

LIBMLX =	$(addprefix $(LIBMLX_DIR), libmlx.a)
LIBMLX_DIR = mlx/

LIBFT_DIR = lib/libft/libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

FRACTOL_SRC = fractol.c cmplx_math.c main.c mandelbrot.c julia.c graphic.c control.c
FRACTOL_INC = fractol.h

SRC = $(addprefix $(SRC_DIR), $(FRACTOL_SRC))
INC = $(addprefix $(INC_DIR), $(FRACTOL_INC))
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	@echo "fractol is ready to use"

%.o : %.c $(INC)
	$(CC) $(FLAGS) -g -I$(INC_DIR) -I$(LIBMLX_DIR) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY : all re fclean clean
