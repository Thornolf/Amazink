SRC_BINARY_DIR	=	./src/
SRC_BINARY		=	$(SRC_BINARY_DIR)main.cpp				\
				$(SRC_BINARY_DIR)color.cpp				\
				$(SRC_BINARY_DIR)colorChart.cpp				\
				$(SRC_BINARY_DIR)cart.cpp				\
				$(SRC_BINARY_DIR)receipt.cpp				

OBJ_BINARY		=	$(SRC_BINARY:.cpp=.o)
