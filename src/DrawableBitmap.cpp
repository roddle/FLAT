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


#include "DrawableBitmap.h"

DrawableBitmap::DrawableBitmap()
{
	//ctor
}

DrawableBitmap::DrawableBitmap(const char* filename)
{
	scale = 1.0f;
	position = vec2(0.0f, 0.0f);

	rotation = 0.0f;

	bitmap = al_load_bitmap(filename);

	if(bitmap == NULL) {
		Print("Couldn't find image:");
		Print(filename);
	}
	else {
		size.x = al_get_bitmap_width(bitmap);
		size.y = al_get_bitmap_height(bitmap);
	}

	hasReflection = false;
	floatingHeight = 0.0f;

	localRotation = 0.0f;
	localScale = 1.0f;

	transparency = 255;

	tintR = 255;
	tintG = 255;
	tintB = 255;
}

DrawableBitmap::~DrawableBitmap()
{
	//dtor
}

void DrawableBitmap::setPosition(vec2 _position) {
	position = _position;
}

void DrawableBitmap::setScale(float _scale) {
	scale = _scale;
}

void DrawableBitmap::setLocalScale(float _scale) {
	localScale = _scale;
}

void DrawableBitmap::setRotation(float _rotation) {
	rotation = _rotation;
}

void DrawableBitmap::setLocalRotation(float _rotation) {
	localRotation = _rotation;
}

void DrawableBitmap::setReflection(bool reflection) {
	hasReflection = reflection;
}

void DrawableBitmap::setTransparency(float t) {
	if(t < 0) {
		t = 0;
	}
	if(t > 1.0f) {
		t = 1.0f;
	}

	transparency = (int)((1.0f-t)*255.0f);
}

void DrawableBitmap::draw() {

	//al_draw_scaled_bitmap(bitmap, 0, 0, size.x, size.y, position.x-(size.x/2.0f)*scale, position.y-(size.y/2.0f)*scale, size.x*scale, size.y*scale, 0);

	float totalScale = scale*localScale;
	float totalRotation = rotation+localRotation;
	float totalRotationComplement = rotation-localRotation;

	al_draw_tinted_scaled_rotated_bitmap(bitmap, al_map_rgba(tintR, tintG, tintB, transparency), size.x/2.0f, size.y/2.0f, position.x, position.y, totalScale, totalScale, totalRotation, 0);

	if(hasReflection) {
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

		//al_draw_tinted_scaled_rotated_bitmap(bitmap, al_map_rgb(100, 100, 100), size.x/2.0f, size.y/2.0f, position.x - sin(rotation)*(scale*size.y+floatingHeight*scale), position.y + cos(rotation)*scale*size.y+floatingHeight*scale, totalScale, totalScale, totalRotationComplement, 2);
		al_draw_tinted_scaled_rotated_bitmap(bitmap, al_map_rgba(0.9f*tintR, 0.9f*tintG, tintB, 100), size.x/2.0f, size.y/2.0f, position.x - sin(rotation)*(scale*size.y+floatingHeight*scale), position.y + cos(rotation)*scale*size.y+floatingHeight*scale, totalScale, totalScale, totalRotationComplement, 2);

		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
	}
}


void DrawableBitmap::setFloatingHeight(float height) {
	floatingHeight = height;
}

void DrawableBitmap::setTint(int r, int g, int b) {
	tintR = r;
	tintG = g;
	tintB = b;
}
