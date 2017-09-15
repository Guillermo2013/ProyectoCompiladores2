TARGET=exemploClase
EXPR_PARSE_SRC = expr_parser.cpp
EXPR_LEXER_SRC = expr_lexer.cpp
SRCFILES = $(EXPR_PARSE_SRC) $(EXPR_LEXER_SRC) ash.cpp Semantico.cpp main.cpp 
OBJ_FILE = ${SRCFILES:.cpp=.o}

.PHONY: clean 

$(TARGET): $(OBJ_FILE)
	g++ -std=c++11 -o $@ $(OBJ_FILE)


$(EXPR_LEXER_SRC) : exemploClase.l
	flex -o $@ $^

$(EXPR_PARSE_SRC) : expr.y
	bison --defines=tokens.h -rall -o  $@ $< 

%.o: %.cpp 
	g++ -std=c++11 -c -o $@ $<

run : $(TARGET)
	g++ -E  exemplo.cpp > archivo.cpp 
	./$(TARGET) archivo.cpp 
clean:
	rm -f exemploClase.c
	rm -f $(TARGET)
	rm -f *.o
	rm -f $(EXPR_LEXER_SRC)
	rm -f $(EXPR_PARSE_SRC)
	
