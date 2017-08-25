CPPFLAGS += -W -Wall -g -std=gnu++11

flexer.yy.cpp : flexer.flex
	flex -o flexer.yy.cpp  flexer.flex


bin/c_lexer : flexer.yy.cpp source1.cpp
	g++ $(CPPFLAGS) -o bin/c_lexer flexer.yy.cpp source1.cpp
