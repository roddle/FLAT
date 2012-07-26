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


#ifndef DRAWABLELINE_H
#define DRAWABLELINE_H

#include <allegro5/allegro_primitives.h>
#include "DrawableObject.h"
#include "vec2.h"

class DrawableLine : public DrawableObject
{
	public:
		DrawableLine();
		DrawableLine(vec2 _start, vec2 _end, ALLEGRO_COLOR _color, float _thickness);
		virtual ~DrawableLine();

		void draw();
	private:
		vec2 start, end;
		ALLEGRO_COLOR color;
		float thickness;
};

#endif // DRAWABLELINE_H
