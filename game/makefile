#Simple Makefile
#Variable

CXX=gcc
PROJ=main
OBJ=main.o
CFLAGS=$(pkg-config --libs allegro-5) -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_image

#Reglas explicitas
all: $(OBJ)
	$(CXX) -o $(PROJ) $(OBJ) $(CFLAGS)

#Reglas implicitas
$(PROJ).o: $(PROJ).c 
#menu.o: menu.c
#contact.o: contact.c
clean:
	rm *.o
