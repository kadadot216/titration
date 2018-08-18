##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for bsq
##

CC		=	gcc
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h
LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	
			
LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
LDFLAGS		=	-L./$(LIB_DIR)
LIBFLAG		=	# -l$(LIB_NAMEDIR)

NAME		=	109titration
MAIN		=	src/main.c
SRC		=	src/file.c	\
			src/calc.c	\
			src/parsing.c	\
			src/debug.c	\
			src/titration.c
			
OBJ		=	$(SRC:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	tests/redirect.c		\
			tests/t_read_file.c		\
			tests/helpers/print_2nd_derivative.c		\
			tests/t_calc_derivative.c	\
			tests/t_print_file.c

TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	tests/main.c
GDB_NAME	=	gdb.out

.PHONY: tclean gclean fclean lclean lfclean

all:	$(NAME)

lib:	libmy libmyhds

libmyhds:
	@mkdir -p $(LIB_DIR)/$(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

libmy:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

libre: libfclean lib

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LDFLAGS) $(LIBFLAG)

re: fclean all

clean: libclean
	$(RM) $(OBJ)

cclean:	clean
	$(RM) $(NAME)

gdb:	gclean
	$(DBCC) $(CFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC) $(LIB_SRC)

gclean:
	$(RM) $(GDB_NAME)

testmake:
	$(CC) $(CFLAGS) -I./tests -o $(TEST_NAME) $(TEST_SRC) $(SRC) \
		$(TEST_FLAGS)
	./$(TEST_NAME)

tests_run: testmake

tclean:
	$(RM) *.gc*
	$(RM) $(TEST_NAME)

fclean: tclean cclean libclean gclean libfclean
