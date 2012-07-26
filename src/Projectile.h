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


#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "DetailObject.h"
#include "vec2.h"

#ifndef TIME_STEP
#define TIME_STEP 0.01666667f
#endif

class Projectile : public DetailObject
{
	public:
		Projectile();
		virtual ~Projectile();

		void setVelocity(vec2 _velocity);

		void setStarburstBitmap(DrawableBitmap bitmap);
		void setHaloBitmap(DrawableBitmap bitmap);

		void update();
		void draw();

		void setImageParameters(vec2 _position, float _scale, float _rotation);
	protected:
	private:
		vec2 velocity;

		DrawableBitmap starburstBitmap;
		DrawableBitmap haloBitmap;

		float time;
};

#endif // PROJECTILE_H
