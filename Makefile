CXX = g++
SHELL = CMD
FLAGS = -Wall -g -O3
OUTPUT = main.exe
SRC = graham_scan.cpp main.cpp
RM = del
CLS = cls


run: build
	@$(CLS)
	@main.exe < points.txt > result.txt
	@python draw.py

show:
	@$(CLS)
	@python draw.py

build: $(SRC)
	@$(CXX) $(FLAGS) $(SRC) -o $(OUTPUT)