##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

NAME_TEST	= ../GLaDOS

CC	= gcc

RM	= rm -f

SRC_DIR	= ../src

TEST	=	$(SRC_DIR)/combat_motor/is_effective.c\
		$(SRC_DIR)/combat_motor/combat_main.c\
		$(SRC_DIR)/constructor/attack_constructor.c\
		$(SRC_DIR)/constructor/pokemon_constructor.c\
		./is_effective_test.c\
		./is_effective_test2.c\
		./attack_constructor_test.c\
		./pokemon_tests.c

OBJS_TEST = $(TEST:.c=.o)

CFLAGS = -I ../include -I ../gumiho_lib
CFLAGS += -W -Wall -Wextra -pedantic --coverage

LDFLAGS	= -L../lib/epi/ -lepi -l c_graph_prog -lcriterion -lgcov

all: $(NAME_TEST)

lib:
	(cd ../lib/epi/ && make)

$(NAME_TEST): lib $(OBJS_TEST)
	$(CC) $(OBJS_TEST) -o $(NAME_TEST) $(LDFLAGS)

clean:
	$(RM) $(OBJS_TEST)
	(cd ../lib/epi/ && make clean)

fclean: clean
	$(RM) $(NAME_TEST)
	(cd ../lib/epi/ && make fclean)

re: fclean all
