##
## Makefile for bistro in /home/bougon_p/rendu/Piscine_C_bistromathique
## 
## Made by Pierre Bougon
## Login   <bougon_p@epitech.net>
## 
## Started on  Thu Oct 29 14:45:48 2015 Pierre Bougon
## Last update Sun Nov 29 04:06:11 2015 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)my_ls.c \
	$(SRCP)my_ls_tri.c \
	$(SRCP)my_ls_show.c \
	$(SRCP)my_ls_options.c \
	$(SRCP)my_over_nine.c \
	$(SRCP)my_colors.c \
	$(SRCP)my_next_file.c \
	$(SRCP)macroes.c \
	$(SRCP)lasts.c \
	$(SRCP)functions.c

OBJS    = $(SRC:.c=.o)

NAME    = my_ls

CC      = gcc

CFLAGS  = -W -Wall -ansi -pedantic -g

LDFLAGS = -lmy -L./lib/

RM      = rm -f

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
