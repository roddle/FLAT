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


#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "utilities.h"
#include "DrawableObject.h"
#include "DrawStack.h"

class GraphicsManager
{
	public:
		GraphicsManager();
		GraphicsManager(int _resx, int _resy);
		virtual ~GraphicsManager();

		void draw();

		void pushDrawableObject(DrawableObject* o);

		void targetBackbuffer();

		ALLEGRO_DISPLAY* getDisplay();
	private:
		ALLEGRO_COLOR clearColor;
		ALLEGRO_DISPLAY *display;

		unsigned int resolution_x;
		unsigned int resolution_y;

		int initialize(int resx, int resy);

		DrawStack stack;
};

#endif // GRAPHICSMANAGER_H
