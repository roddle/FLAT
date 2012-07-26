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


#include "DrawableCircle.h"

DrawableCircle::DrawableCircle()
{
	//ctor
}

DrawableCircle::DrawableCircle(vec2 _position, float _radius, ALLEGRO_COLOR _color)
{
	position = _position;
	radius = _radius;
	color = _color;
}

DrawableCircle::~DrawableCircle()
{
	//dtor
}

void DrawableCircle::draw() {
	al_draw_filled_circle(position.x, position.y, radius, color);
}
