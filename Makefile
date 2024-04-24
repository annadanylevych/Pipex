SRCS =	main.c family.c find_command.c exit.c split_quotes.c utils.c

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

clean:
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFTDIR) fclean