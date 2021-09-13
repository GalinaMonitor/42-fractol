NAME = fractol
CC = gcc

FLAGS = -Wall -Werror -Wextra
LDFLAGS = -L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -framework OpenGL -framework Appkit -O3

DIR_LIB = lib
DIR_SRC = src
DIR_INC = include

LIBMLX =	$(addprefix $(LIBMLX_DIR), libmlx.a)

DIR_LIBFT = lib/libft
NAME_LIBFT = libft.a
LIBMLX_DIR = ./mlx/
LIBFT = $(addprefix $(DIR_LIBFT), $(NAME_LIBFT))
FRACTOL_SRC = fractol.c
FRACTOL_INC = fractol.h

SOURCES = $(addprefix $(DIR_SRC), $(FRACTOL_SRC))
INCLUDES = $(addprefix $(DIR_INC), $(FRACTOL_INC))

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJECTS)
	@$(CC) $< -o $(NAME)
	@echo "fractol.a is ready to use"

%.o : %.c $(HEADER)
	@$(CC) $(OBJECTS) -o $< -o $@ $(LDFLAGS)

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	$(MAKE) clean -C $(DIR_LIBFT)

fclean:
	$(MAKE) fclean -C $(DIR_LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY : all re fclean clean
