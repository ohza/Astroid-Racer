all: clean lib
	g++ -c main.cpp -o main.o
	g++ -lncurses random_pos.o game_figure.o astroid.o player.o game_flow.o main.o -o main.exe

lib:
	g++ -c random_pos.cpp -o random_pos.o
	g++ -c game_figure.cpp -o game_figure.o
	g++ -c astroid.cpp -o astroid.o
	g++ -c player.cpp -o player.o
	g++ -c game_flow.cpp -o game_flow.o	

run:
	./main.exe
	
clean:
	rm -f *.o *.exe *.swp *.so
