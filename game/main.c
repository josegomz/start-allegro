/*mi primer programa en allegro*/
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>//para usar dialogs -lallegro_dialog
#include <allegro5/allegro_font.h> //para usar fuentes de texto
#include <allegro5/allegro_ttf.h> //archivo de fuentes
#include <allegro5/allegro_primitives.h> //primitivas de dibujo	

//realizar un programa
#define DISPLAY_WIDTH 640
#define DISPLAY_HEIGHT 480

int main(int argc, char const *argv[])
{
	//creacion de todos los objetos
	ALLEGRO_DISPLAY *display= NULL;//cremos la ventana 
	ALLEGRO_BITMAP *icon = NULL;//creamos un icono para el proyecto
	ALLEGRO_EVENT_QUEUE *event = NULL;//se crea un evento



	if(!al_init()){
		al_show_native_message_box(NULL, NULL, NULL, "Error", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;//falla al iniciar allegro
	}
	if(!al_init_image_addon()) {//inicializamos el uso de imagenes 
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    	return 0;
   	}

   	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);//creamos la ventana (ancho y alto)
   	event = al_create_event_queue();
	if(!display) { // si falla imprimimos esto
      al_show_native_message_box(NULL, NULL, NULL, "Error al crear display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   	}

	al_init_primitives_addon();
 	al_init_font_addon();//cargar una fuente de texto
 	al_init_ttf_addon();//caragar archivos de fuente
	al_install_keyboard();

 	ALLEGRO_FONT *size_16 = al_load_font("ARCADECLASSIC.TTF", 56, 1);
 	ALLEGRO_FONT *size_32 = al_load_font("ARCADECLASSIC.TTF", 92, 2);

 	//color de fondo
 	al_clear_to_color(al_map_rgb(0,0,0));
	icon = al_load_bitmap("icon.png");
 	al_set_window_title(display, "Racing car!");//agregar titulo
	al_set_window_position(display, 0,0);//posision de la pantalla

	al_set_display_icon(display, icon);// icono del programa

 	//dibujar una linea
	al_draw_line(12.0, 12.0, 200.0, 12.0,al_map_rgb(255,0,0),3.0);
	//dibujar un punto
	al_draw_pixel(14,14, al_map_rgb(0, 255, 0));
	//dibujar un rectangulo 
	al_draw_filled_rectangle(16,16,40,40,al_map_rgb(255,150,110));
	//dibujar un circulo
	//al_draw_filled_circle(105,16,2,al_map_rgb(55,150,210));
	al_draw_filled_circle(55,28,12,al_map_rgb(55,150,210));
	//dibujar un triangulo
	al_draw_filled_triangle(75 ,16,75,40,95,28,al_map_rgb(55,150,210));
	//dibujar un elipse
	//             posicion del centro
	//				  x      y
	 al_draw_ellipse(115, 28, 12.0, 4.0,al_map_rgb(200, 0, 0), 1.0);

	//dibujar el texto
  	al_draw_text(size_32, al_map_rgb(255, 255, 255),50, 50, 0, "Racing car!");
  	al_draw_text(size_16, al_map_rgb(250, 250, 0),50, 150, 0, "start game!");


 	al_flip_display();

 	al_register_event_source(event,al_get_keyboard_event_source());
 	al_register_event_source(event,al_get_display_event_source(display));
 	bool quit = false;
 	while(!quit)
 	{
 		ALLEGRO_EVENT e;
 		al_wait_for_event(event, &e);
 		if(e.type == ALLEGRO_EVENT_KEY_DOWN) {
 			switch(e.keyboard.keycode)
 			{
 				case ALLEGRO_KEY_ESCAPE:
				quit = true; 
			}
		}
 	}
 	//al_rest(3.0);//espera 10 segundos
	al_destroy_display(display);
	return 0;
}
