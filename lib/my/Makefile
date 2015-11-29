##
## Makefile for my Makefile in /home/brout_m/rendu/Piscine_C_J10/lib
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Fri Oct  9 09:57:50 2015 marc brout
## Last update Sat Nov 28 22:24:04 2015 marc brout
##

SRC	= my_getnbr.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putstr_err.c \
	my_revstr.c \
	my_strcmp.c \
	my_strlen.c \
	my_printf.c \
	my_printfcsspb.c \
	my_printfdiouxx.c \
	my_strdup.c \
	my_strcat_err.c \
	my_printfmetc.c

LIBPATH	= ../

HPATH	= ../../include/

OBJ	= $(SRC:.c=.o)

LIB	= libmy.a

HEAD	= my.h

CC	= cc

RM	= rm -f

NAME	= $(LIB)

all: $(LIB)

$(LIB): $(OBJ)
	@ar rc $(LIB) $(OBJ)
	@ranlib $(LIB)
	@cp $(LIB) $(LIBPATH)
	@cp $(HEAD) $(HPATH)

$(HEAD):
	cp $(HEAD) $(HPATH)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(LIB)
	@$(RM) $(LIBPATH)$(LIB)
	@$(RM) $(HPATH)$(HEAD)

re: fclean all clean
