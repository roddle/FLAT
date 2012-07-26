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


#include "DrawableLine.h"

DrawableLine::DrawableLine()
{
	start = vec2(0.0f, 0.0f);
	end = vec2(0.0f, 10.0f);
	color = al_map_rgb(255, 0, 0);
	thickness = 2.0f;
}

DrawableLine::DrawableLine(vec2 _start, vec2 _end, ALLEGRO_COLOR _color, float _thickness)
{
	start = _start;
	end = _end;
	color = _color;
	thickness = _thickness;
}

DrawableLine::~DrawableLine()
{
	//dtor
}

void DrawableLine::draw() {
	al_draw_line(start.x, start.y, end.x, end.y, color, thickness);
}
