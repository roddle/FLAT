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


#ifndef PICKUP_H
#define PICKUP_H

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include "StaticObject.h"
#include "DrawableBitmap.h"
#include "DrawStack3D.h"
#include "utilities.h"


#ifndef TIME_STEP
#define TIME_STEP 0.016666667f
#endif

class Pickup : public StaticObject
{
	public:
		Pickup();
		Pickup(DrawStack3D* world3D, vec3 _position);
		virtual ~Pickup();

		void remove();
		void draw();

		void setImageParameters(vec2 _position, float _scale, float _rotation);
	protected:
        ALLEGRO_BITMAP* skyBeam;
		ALLEGRO_SAMPLE* humSample;
		ALLEGRO_SAMPLE_ID* humID;
		float time;

		vec2 cposition;
		float cscale;
		float rotation;
	private:
};

#endif // PICKUP_H
