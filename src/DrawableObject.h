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


#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "utilities.h"
#include "vec2.h"
#include "vec3.h"

class DrawableObject
{
	public:
		DrawableObject();
		virtual ~DrawableObject();

		virtual void draw();
		float priority;

		virtual void setVisibility(bool _visible);

		//@Hack
		virtual vec3 getPosition();
		virtual float getFacingAngle();
		virtual void setImageParameters(vec2 _position, float _scale, float _rotation);

		virtual float getPlayerAngle();
		virtual void setPlayerAngle(float angle);
		virtual void setPlayerAngle2(float angle);

		virtual float getPlayerDistance();
		virtual void setPlayerDistance(float distance);

		bool destroy;

		int entityType;
};

#endif // DRAWABLEOBJECT_H
