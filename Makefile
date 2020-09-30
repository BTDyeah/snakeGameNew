snake: main.cpp Snake.cpp Fruit.cpp
	g++ -O0 -g3 -o snake main.cpp Snake.cpp Snake.h Fruit.cpp Fruit.h -lsfml-graphics -lsfml-window -lsfml-system -lm
