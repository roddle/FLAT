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


#ifndef DRAWSTACK3D_H
#define DRAWSTACK3D_H

#include <cmath>
#include "DrawStack.h"
#include "utilities.h"
#include "vec3.h"

#define PI 3.14159265
#define FIELD_OF_VIEW_WIDTH 900.0f

#define DETAIL_OBJECT_DESTROY_DISTANCE 400.0f

class DrawStack3D : public DrawableObject
{
	public:
		DrawStack3D();
		virtual ~DrawStack3D();

		void push(DrawableObject* o);

		void draw();

		void setCamera(vec3 _position, float _angle, float _tilt);

		void incrementRotation(float da);
		void incrementCamera(vec3 dPos);

		float playerAngle;
		float playerDistance;

	private:

		void updatePositions();

		vec3 camera;

		float angle;
		float tilt;

		DrawStack stack;
};

#endif // DRAWSTACK3D_H
