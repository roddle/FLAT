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


#ifndef FRAMECONTAINER_H
#define FRAMECONTAINER_H

#include <vector>
#include "DrawableBitmap.h"
#include "DrawableObject.h"


class FrameContainer : public DrawableObject
{
	public:
		FrameContainer();
		virtual ~FrameContainer();

		void push(DrawableBitmap o);

		void draw();

		void setIndex(int i);

		void setImageParameters(vec2 _position, float _scale, float _rotation);
		void setImageFloatingHeight(float height);

		void clear();

		int getNumber();

		void setTint(int r, int g, int b);
	protected:
	private:
		vector <DrawableBitmap> frame;
		int index;
};

#endif // FRAMECONTAINER_H
