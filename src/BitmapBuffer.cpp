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


#include "BitmapBuffer.h"

BitmapBuffer::BitmapBuffer()
{
	//Print("Error: Initializing BitmapBuffer without parameters.");
}

BitmapBuffer::BitmapBuffer(int w, int h, DrawStack* stack) {
	bitmap = al_create_bitmap(w, h);

	//Set drawing target to this bitmap
	al_set_target_bitmap(bitmap);

	al_draw_filled_rectangle(0, 0, w, h, al_map_rgba(255, 0, 0, 0));

	//Draw from the stack parameter
	stack->draw();

	//Return to drawing to the screen
	TARGET_BACKBUFFER();

	flags = 0;
	position = vec2(0.0f, 0.0f);
}

BitmapBuffer::~BitmapBuffer()
{
	//dtor
}

void BitmapBuffer::draw() {
	al_draw_bitmap(bitmap, position.x, position.y, flags);
}

void BitmapBuffer::setPosition(vec2 _position) {
	position = _position;
}

void BitmapBuffer::setFlags(int _flags) {
	flags = _flags;
}
