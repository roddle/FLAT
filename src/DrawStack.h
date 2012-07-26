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


#ifndef DRAWSTACK_H
#define DRAWSTACK_H

#include "DrawableObject.h"
#include <list>

class DrawStack : public DrawableObject
{
	public:
		DrawStack();
		virtual ~DrawStack();

		void push(DrawableObject* o);

		void draw();

		unsigned int length();

		DrawableObject* getElement(int index);
	protected:
	private:

		list <DrawableObject*> stack;
		list <DrawableObject*>::iterator it;
};

bool compareDrawableObjects(DrawableObject* o1, DrawableObject* o2);

#endif // DRAWSTACK_H
