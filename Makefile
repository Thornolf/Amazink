include source.mk

BINARY				=	amazink

CC					=	g++

RM					=	@rm -vf

CXXFLAGS			=	-fPIC -W -Wall -Wextra -Werror -I./inc/

DEBUG				?=	no

ifeq					($(DEBUG), yes)
CFLAGS				=	-g -ggdb3
CXXFLAGS			+=	-g -ggdb3
endif

all:					 $(BINARY)

$(BINARY):				$(OBJ_BINARY)
						$(CC) $(OBJ_BINARY) -o $(BINARY)

clean:
						$(RM) $(OBJ_BINARY)

fclean:					clean
						$(RM) $(BINARY)
