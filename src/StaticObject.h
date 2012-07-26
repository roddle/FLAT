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


#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "DetailObject.h"
#include "DrawableBitmap.h"
#include "FrameContainer.h"

#ifndef PI
#define PI 3.14159265
#endif

class StaticObject : public DetailObject
{
	public:
		StaticObject();
		virtual ~StaticObject();

		void update();

		virtual void draw();

		void pushImage(DrawableBitmap b);

		virtual void setImageParameters(vec2 _position, float _scale, float _rotation);

		void setPlayerAngle2(float angle);

		void setPrescale(float s);

		bool isJumpable();
		void setJumpable();
	protected:
		FrameContainer frames;

		float playerAngle;
		float scale;
		float targetScale;

		bool jumpable;
	private:
};

#endif // STATICOBJECT_H
