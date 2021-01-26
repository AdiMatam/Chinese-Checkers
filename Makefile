.SILENT:

MAIN = main
SOURCE = src/$(MAIN).cpp src/helpers.cpp src/color_manip.cpp
EXTERNAL = -ltgui-s -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
STANDARD = -static-libgcc -static-libstdc++


test: build run
build: compile link
compile:
	echo "Compiling CPP files..."
	# g++ -c $(wildcard src/*.cpp) -DSFML_STATIC -Iinclude
	g++ -c $(SOURCE) -DSFML_STATIC -Iinclude
link:
	echo "Linking libraries..."
	g++ $(wildcard *.o) -o $(MAIN).exe $(STANDARD) -Llib $(EXTERNAL)
run:
	echo "Running main.exe..."
	./$(MAIN).exe
clean:
	echo "Removing .o/.exe..."
	rm -f *.o *.exe

