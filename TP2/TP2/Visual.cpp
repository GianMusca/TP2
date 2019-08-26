#include "Visual.h"
#include "Robots.h"
#include "Piso.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>		//No olvides instalar allegro 


unsigned int SCALE = 100;				//Valor para escalar


//Funcion para dibujar tiles y robotos
int drawFloor(tileType* floor, robotType* robots, uint robotCount, uint width, uint height)
{
	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* tile_sucio;
	ALLEGRO_BITMAP* tile_limpio;
	ALLEGRO_BITMAP* robot;

	if (!al_init())
	{
		fprintf(stderr, "Unable to start allegro\n");
		return -1;
	}
	else if (!al_init_image_addon())
	{
		fprintf(stderr, "Unable to start image addon \n");
		al_uninstall_system();
		return -1;
	}
	else if (!(display = al_create_display(width * SCALE, height * SCALE)))
	{
		fprintf(stderr, "Unable to create display\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		return -1;
	}
	else if (!(tile_sucio = al_load_bitmap("dirtytile.png")))
	{
		fprintf(stderr, "Unable to load dirtytile picture\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		al_destroy_display(display);
		return -1;
	}
	else if (!(tile_limpio = al_load_bitmap("cleantile.png")))
	{
		fprintf(stderr, "Unable to load cleantile picture\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		al_destroy_display(display);
		return -1;
	}
	else if (!(robot = al_load_bitmap("robot2.png")))
	{
		fprintf(stderr, "Unable to load robot picture\n");
		al_uninstall_system();
		al_shutdown_image_addon();
		al_destroy_display(display);
		return -1;
	}

	ALLEGRO_BITMAP* drawme = tile_limpio;

	uint tilenum = 0;	//Para conectar tile correcto con coordenadas correctas

	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			//Chequeamos si tile es sucio/limpio
			if (floor[i] == 0)
			{
				drawme = tile_sucio;
			}
			else if (floor[i] == 1)
			{
				drawme = tile_limpio;
			}
			//Dibuja tile
			al_draw_scaled_bitmap(drawme,
				0, 0, al_get_bitmap_width(drawme), al_get_bitmap_height(drawme),
				j * SCALE, i * SCALE, al_get_display_width(display) / width, al_get_display_height(display) / height,
				0);
			++tilenum;
		}
	}

	//Dibuja robotos
	for (unsigned int i = 0; i < robotCount; i++)
	{
		al_draw_scaled_bitmap(robot,
			0, 0, al_get_bitmap_width(robot), al_get_bitmap_height(robot),
			robots[i].x * SCALE, robots[i].y * SCALE, al_get_display_width(display) / width, al_get_display_height(display) / height,
			0);
	}

	al_flip_display();
	al_rest(5.0);//para poder ver la imagen

	return (0);
}