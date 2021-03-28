.SILENT:

INCLUDE = -DSFML_STATIC -Iinclude
EXTERNAL = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
NETWORK = -lsfml-network-s -lsfml-system-s -lws2_32 -lwinmm
STANDARD = -static-libgcc -static-libstdc++
FILES = $(wildcard src/*.cpp) # src/main.cpp src/helpers.cpp src/checkers.cpp src/slot.cpp
EXEC = Game


all: build run
build: compile link
compile:
	echo "Compiling CPP files..."
	g++ -c $(FILES) $(INCLUDE)
link:
	echo "Linking libraries..."
	g++ $(wildcard *.o) -o $(EXEC).exe $(STANDARD) -Llib $(EXTERNAL)
run:
	echo "Running $(EXEC).exe..."
	./$(EXEC).exe
pch:
	echo "Making pch..."
	g++ src/pch.hpp $(INCLUDE)
clean:
	echo "Removing .o..."
	rm -f *.o 

.PHONY: misc
misc:
	echo "Creating test/misc file"
	g++ misc/Misc.cpp $(INCLUDE) -o Misc.exe $(STANDARD) -Llib $(NETWORK)
