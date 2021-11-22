SRC = src/Main.cpp src/book.cpp
all: $(SRC)
	g++  -L"C:\Program Files (x86)\libpqxx\lib" -L"C:\Program Files\PostgreSQL\14\lib" $(SRC) -lpq -lpqxx -I"C:\Program Files\PostgreSQL\14\include" -I"C:\Program Files (x86)\libpqxx\include" -o main

	./main