SRC_BINARY_DIR	=	./src/
SRC_BINARY		=	$(SRC_BINARY_DIR)main.cpp				\
					$(SRC_BINARY_DIR)test.cpp

OBJ_BINARY		=	$(SRC_BINARY:.cpp=.o)
