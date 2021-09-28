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

FRACTOL_SRC = cmplx_math.c main.c mandelbrot_base.c julia_base.c graphic.c control.c burning_ship.c
BONUS_SRC = cmplx_math.c main.c mandelbrot.c burning_ship.c julia.c graphic.c control.c
FRACTOL_INC = fractol.h

SRC = $(addprefix $(SRC_DIR), $(FRACTOL_SRC))
SRC_BONUS = $(addprefix $(SRC_DIR), $(BONUS_SRC))
INC = $(addprefix $(INC_DIR), $(FRACTOL_INC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) -lpthread
	@echo "fractol is ready to use"

# $(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
# 	$(CC) $(OBJ) $(LIBFT) -o  $@ -g -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o : %.c $(INC)
	$(CC) $(FLAGS) -g -I$(INC_DIR) -I$(LIBMLX_DIR) -c $< -o $@

# %.o: %.c
# 	$(CC) -I$(INC_DIR) -Imlx_linux -O3 -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus: $(LIBFT) $(LIBMLX) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o fractol $(LDFLAGS) -lpthread
	@echo "fractol is ready to use"



.PHONY : all re fclean clean bonus
