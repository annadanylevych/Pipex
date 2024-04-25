SRCS =	main.c family.c find_command.c exit.c 

SRCS_BONUS = main_bonus.c

OBJS = $(SRCS:.c=.o)

LIBFTDIR = lib/

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

HEADER = pipex.h

%.o:%.c	$(HEADER) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) make_libs
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

make_libs:
	$(MAKE) -C $(LIBFTDIR)

bonus: 
	

clean:
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFTDIR) fclean

re: clean $(NAME)