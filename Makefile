all:
	g++ main.cpp Game.h Game.cpp Field.h Field.cpp Unit.h Unit.cpp UnitAI.h UnitAI.cpp getch.h -o xo && ./xo