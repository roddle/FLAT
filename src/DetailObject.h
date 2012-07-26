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


#ifndef DETAILOBJECT_H
#define DETAILOBJECT_H

#include "vec3.h"
#include "vec2.h"
#include "DrawableObject.h"
#include "DrawableBitmap.h"


class DetailObject : public DrawableObject
{
	public:
		DetailObject();
		virtual ~DetailObject();

		void draw();

		bool visible;

		void setVisibility(bool _visible);

		void setBitmap(DrawableBitmap _bitmap);
		DrawableBitmap getBitmap();

		void setPosition(vec3 _position);

		vec3 getPosition();
		vec2 getPos();

		float getRadius();

		void setImageParameters(vec2 _position, float _scale, float _rotation);

		virtual void pushImage(DrawableBitmap b);

		virtual void setPrescale(float s);

		virtual void update();

		virtual bool isJumpable();
		virtual void setJumpable();

	protected:

		vec3 position;

		float radius;

	private:

		DrawableBitmap bitmap;
};

#endif // DETAILOBJECT_H
