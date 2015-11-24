##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Tue Nov 24 19:14:36 2015 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)my_ls.c \
	$(SRCP)my_ls_tri.c \
	$(SRCP)my_ls_show.c

OBJS    = $(SRC:.c=.o)

NAME    = my_ls

CC      = gcc

CFLAGS  = -W -Wall -Werror -ansi -pedantic -g

LDFLAGS = -lmy -L./lib/

HDFLAGS = -I ./include/

RM      = rm -f

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(HDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
