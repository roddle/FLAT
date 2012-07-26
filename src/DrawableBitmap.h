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


#ifndef DRAWABLEBITMAP_H
#define DRAWABLEBITMAP_H

#include <allegro5/allegro.h>
#include "DrawableObject.h"
#include "utilities.h"


class DrawableBitmap : public DrawableObject
{
	public:
		DrawableBitmap();
		DrawableBitmap(const char* filename);
		virtual ~DrawableBitmap();

		void setPosition(vec2 _position);
		void setScale(float _scale);
		void setLocalScale(float _scale);
		void setRotation(float _rotation);
		void setLocalRotation(float _rotation);

		void draw();

		void setReflection(bool reflection);

		void setFloatingHeight(float height);

		void setTransparency(float t);

		void setTint(int r, int g, int b);
	protected:
	private:
		ALLEGRO_BITMAP* bitmap;

		vec2 position;
		vec2 size;

		float scale;
		float localScale;
		float rotation;
		float localRotation;

		int transparency;

		int tintR, tintG, tintB;

		float floatingHeight;

		bool hasReflection;
};

#endif // DRAWABLEBITMAP_H
