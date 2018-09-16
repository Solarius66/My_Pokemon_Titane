##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Lib 2.0
##

LIB_PATH	=	../../include
SRC_PATH	=	./src

SRC	=	$(SRC_PATH)/epi_putstr.c\
		$(SRC_PATH)/epi_puterr.c\
		$(SRC_PATH)/epi_atoi.c\
		$(SRC_PATH)/epi_strlen.c\
		$(SRC_PATH)/epi_fusion_str.c\
		$(SRC_PATH)/epi_compare_str.c\
		$(SRC_PATH)/epi_clear_malloc.c\
		$(SRC_PATH)/epi_count_words.c\
		$(SRC_PATH)/epi_wtoa.c\
		$(SRC_PATH)/epi_putnbr.c\
		$(SRC_PATH)/epi_itoa.c\
		$(SRC_PATH)/epi_putfloat.c\
		$(SRC_PATH)/epi_printf.c\
		$(SRC_PATH)/epi_malloc.c\
		$(SRC_PATH)/epi_nmatch.c\
		$(SRC_PATH)/epi_re_malloc.c\
		$(SRC_PATH)/epi_replace_charac.c\
		$(SRC_PATH)/epi_putnbr_base.c\
		$(SRC_PATH)/epi_putnbr_dec.c\
		$(SRC_PATH)/epi_clone_army.c\
		$(SRC_PATH)/epi_printf_flags.c\
		$(SRC_PATH)/epi_create_array.c\
		$(SRC_PATH)/epi_does_start_with.c\
		$(SRC_PATH)/epi_split_many.c\
		$(SRC_PATH)/epi_dadd.c\
		$(SRC_PATH)/epi_stradd.c\
		$(SRC_PATH)/epi_putf.c\
		$(SRC_PATH)/epi_free.c\
		$(SRC_PATH)/epi_mprintf.c\
		$(SRC_PATH)/epi_putf_flags.c\
		$(SRC_PATH)/epi_split_nb.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libepi.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	test -d $(LIB_PATH) || mkdir $(LIB_PATH)
	cp internal.h $(LIB_PATH)/
	mv $(LIB_PATH)/internal.h $(LIB_PATH)/epilib.h

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)
	test -d $(LIB_PATH) && rm -f $(LIB_PATH)/epilib.h

re:	fclean all
