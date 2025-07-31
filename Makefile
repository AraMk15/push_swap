NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./src/
SRCSLIST = push_swap.c \
			free_stack.c \
			operat_a.c \
			operat_b.c \
			parse_input.c \
			sort_small.c \
			sort_three.c \
			sort_large.c \
			utils_1.c \
			utils_2.c \
			utils_3.c
SRCS = $(addprefix $(SRCSDIR), $(SRCSLIST))

OBJSDIR = ./obj/
OBJSLIST = $(SRCS:.c=.o)
OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJSDIR)%.o, $(SRCS))

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) -r ${OBJSDIR}
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
