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


#include "DrawableText.h"

DrawableText::DrawableText()
{
	text = (char*)"Nothing";
}

DrawableText::DrawableText(ALLEGRO_FONT* _font, ALLEGRO_COLOR _color)
{
	font = _font;
	position = vec2(0.0f, 0.0f);
	color = _color;
}

DrawableText::~DrawableText()
{
	//dtor
}

void DrawableText::draw() {
	al_draw_text(font, color, position.x, position.y, 0, text);
}

void DrawableText::setPosition(vec2 _position) {
	position = _position;
}

void DrawableText::setText(const char* _text) {
	text = (char*)_text;
}
