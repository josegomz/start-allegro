#Simple Makefile
#Variable

#posibles librerias -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_image

CPP=g++
PROJ=space
OBJ=main.o
CFLAGS=$(pkg-config --libs allegro-5) -lallegro -lallegro_main -lallegro_dialog -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_image -lallegro_audio -lallegro_acodec

#Reglas explicitas
all: $(OBJ)
	$(CPP) -o $(PROJ) $(OBJ) $(CFLAGS)

#Reglas implicitas
$(PROJ).o: $(PROJ).cpp 
#menu.o: menu.c
#contact.o: contact.c
clean:
	rm *.o
