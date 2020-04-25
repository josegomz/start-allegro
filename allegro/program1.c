/*tutorial basico de como crear una pantalla*/
#include <stdio.h>
#include <allegro5/allegro.h>

int main(int argc, char **argv){
   
   ALLEGRO_DISPLAY *display = NULL;
   //verifica si se pudo inicializar allegro
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
   //crea una pantalla con el ancho y el alto
   display = al_create_display(640, 480);
   if(!display) { // si falla imprimimos esto
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   //borra la pantalla actual al color dado 
   al_clear_to_color(al_map_rgb(255,255,0));//all_map_rgb -> toma tres valores dados rojo verde y azul
   /*allegro crea dos buffers:
		- el que se muestra en pantalla
		- el que se muestra en codigo
	*/
   al_flip_display();

   al_rest(10.0);//espera 10 segundos

   al_destroy_display(display);//destruye la pantalla y libera memoria

   return 0;
}