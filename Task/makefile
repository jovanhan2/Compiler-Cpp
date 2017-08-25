CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I CW2-Parser/include


CW2-Parser/src/maths_parser.tab.cpp CW2-Parser/src/maths_parser.tab.hpp : CW2-Parser/src/maths_parser.y
	bison -v -d CW2-Parser/src/maths_parser.y -o CW2-Parser/src/maths_parser.tab.cpp

CW2-Parser/src/maths_lexer.yy.cpp : CW2-Parser/src/maths_lexer.flex CW2-Parser/src/maths_parser.tab.hpp
	flex -o CW2-Parser/src/maths_lexer.yy.cpp  CW2-Parser/src/maths_lexer.flex

bin/c_compiler : CW2-Parser/src/print_canonical.o CW2-Parser/src/maths_parser.tab.o CW2-Parser/src/maths_lexer.yy.o CW2-Parser/src/maths_parser.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_parser $^


clean :
	rm CW2-Parser/src/*.o
	rm bin/*
	rm CW2-Parser/src/*.tab.cpp
	rm CW2-Parser/src/*.yy.cpp
