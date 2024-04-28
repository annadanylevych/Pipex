SRCS =	main.c family.c find_command.c exit.c 

SRCS_BONUS = main_bonus.c execution_bonus.c exit_bonus.c 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFTDIR = lib/

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

NAME_BONUS = pipex_bonus

HEADER = pipex.h

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) make_libs
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

make_libs:
	$(MAKE) -C $(LIBFTDIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) make_libs
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFTDIR) -lft -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)  $(NAME_BONUS)
	$(MAKE) -C $(LIBFTDIR) fclean

re: clean $(NAME) $(NAME_BONUS)