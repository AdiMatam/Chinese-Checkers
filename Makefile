.SILENT:

SOURCE = src/main.cpp src/helpers.cpp
EXTERNAL = -ltgui-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
STANDARD = -static-libgcc -static-libstdc++


test: build run
build: compile link
compile:
	echo "Compiling CPP files..."
	# g++ -c $(wildcard src/*.cpp) -DSFML_STATIC -Iinclude
	g++ -c $(SOURCE) -DSFML_STATIC -Iinclude
link:
	echo "Linking to SFML..."
	g++ $(wildcard *.o) -o main.exe $(STANDARD) -Llib $(EXTERNAL)
run:
	echo "Running main.exe..."
	./main.exe
clean:
	echo "Removing .o/.exe..."
	rm -f *.o *.exe

# -LD:\\github\\dependencies\\SDL2-2.0.8\\lib\\x64 -lSDL2main -lSDL2 -lopengl32 -o test-sdl
