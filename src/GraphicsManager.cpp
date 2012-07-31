/*
Copyright 2012 Johan "SteelRaven7" Hassel

This file is part of FLAT.

FLAT is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

FLAT is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FLAT.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "GraphicsManager.h"

GraphicsManager::GraphicsManager() {
	GraphicsManager(1280, 720);
}

GraphicsManager::GraphicsManager(int _resx, int _resy)
{
	initialize(_resx, _resy);
}

GraphicsManager::~GraphicsManager()
{
	al_shutdown_primitives_addon();
	al_destroy_display(display);

	Print("GraphicsManager was cleaned up.");
}


void GraphicsManager::pushDrawableObject(DrawableObject* o) {
	stack.push(o);
}



//Draw from the manager's stack, which should contain all objects to be drawn.
void GraphicsManager::draw() {
	al_clear_to_color(clearColor);

	stack.draw();

	al_flip_display();
}



//Initialize allegro and the display.
int GraphicsManager::initialize(int resx, int resy) {

	resolution_x = resx;
	resolution_y = resy;

	display = NULL;

	Print("Initialising Allegro...");
	//Initialize allegro and required addons
	if(!al_init()) {
		Print("Failed to initialize allegro!");
		return 0;
	}

	Print("Initialising Allegro primitives addon...");
	if(!al_init_primitives_addon()) {
		Print("Failed to initialize primitives addon!");
		return 0;
	}

	Print("Initialising Allegro image addon...");
	if(!al_init_image_addon()) {
		Print("Failed to initialize image addon!");
		return 0;
	}
	
	Print("Initialising Allegro font addon...");
	al_init_font_addon();

	Print("Initialising Allegro TTF addon...");
	if(!al_init_ttf_addon()) {
		Print("Failed to initialize ttf addon!");
		return 0;
	}

	Print("Initialising Allegro audio addon...");
	if(!al_install_audio()) {
		Print("Failed to initialize audio addon!");
		return 0;
	}


	Print("Initialising Allegro audio codecs addon...");
	if(!al_init_acodec_addon()) {
		Print("Failed to initialize audio codec addon!");
		return 0;
	}


	Print("Reserving audio samples addon...");
	if(!al_reserve_samples(16)){
		Print("Failed to reserve samples!");
		return -1;
	}


	Print("Initialising mouse...");
	if(!al_install_mouse()) {
		Print("Failed to initialize mouse");
		return 0;
	}


	Print("Initialising keyboard...");
	if(!al_install_keyboard()) {
		Print("Failed to initialize keyboard");
		return 0;
	}

	Print("Allegro initialized!");


	//Initialize the window
	display = al_create_display(resolution_x, resolution_y);
	if(!display) {
		Print("Failed to create display!");
		return -1;
	}

	Print("Display created successfully.");

	//Fill the window with a color.
	clearColor = al_map_rgb(100,100,200);

	return 1;
}

ALLEGRO_DISPLAY* GraphicsManager::getDisplay() {
	return display;
}

void GraphicsManager::targetBackbuffer() {
	al_set_target_bitmap(al_get_backbuffer(display));
}
