/*
Copyright 2012 Johan "SteelRaven7" Hassel
Copyright 2012 Josh "Cheeseness" Bush

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


#ifndef FLOOR_H
#define FLOOR_H

#include <allegro5/allegro.h>
#include "vec2.h"
#include "vec3.h"
#include "DrawableObject.h"
#include "DrawableBitmap.h"

#ifndef PI
#define PI 3.14159265
#endif

class Floor : public DrawableObject
{
	public:
		Floor();
		virtual ~Floor();

		void draw();

		void swapScenery();

		void setCamera(vec3 _position, float _angle, float _tilt);

	protected:
	private:

		ALLEGRO_COLOR color;

		ALLEGRO_BITMAP* sky[2];
		ALLEGRO_BITMAP* ice[2];
		ALLEGRO_BITMAP* scenery[26];
		ALLEGRO_BITMAP* stars;

		float sceneryAngle[26];
		float sceneryScale[26];
		vec2 sceneryCenter[26];

		vec3 position;
		float tilt;
		float angle;

		int sceneryIndex;
};

#endif // FLOOR_H
