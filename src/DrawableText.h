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


#ifndef DRAWABLETEXT_H
#define DRAWABLETEXT_H

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "vec2.h"
#include "DrawableObject.h"

class DrawableText : public DrawableObject
{
	public:
		DrawableText();
		DrawableText(ALLEGRO_FONT* _font, ALLEGRO_COLOR _color);
		virtual ~DrawableText();

		void draw();
		void setPosition(vec2 _position);
		void setText(const char* _text);
	protected:
	private:
		ALLEGRO_FONT* font;
		ALLEGRO_COLOR color;

		char* text;

		vec2 position;

};

#endif // DRAWABLETEXT_H
