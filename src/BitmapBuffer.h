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


#ifndef BITMAPBUFFER_H
#define BITMAPBUFFER_H

#include <allegro5/allegro_primitives.h>
#include "DrawableObject.h"
#include "DrawStack.h"

/*
Class that holds a single buffered image that is prerendered via a DrawStack object.
*/

void TARGET_BACKBUFFER();

class BitmapBuffer : public DrawableObject
{
	public:
		BitmapBuffer();
		BitmapBuffer(int w, int h, DrawStack* stack);
		virtual ~BitmapBuffer();

		void draw();

		void setFlags(int _flags);

		void setPosition(vec2 _position);

	private:
		vec2 position;
		int flags, w, h;

		ALLEGRO_BITMAP* bitmap;
};

#endif // BITMAPBUFFER_H
