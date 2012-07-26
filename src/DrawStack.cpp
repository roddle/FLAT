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


#include "DrawStack.h"

DrawStack::DrawStack()
{
	//ctor
}

DrawStack::~DrawStack()
{
	//dtor
}

void DrawStack::push(DrawableObject* o) {
	stack.push_back(o);
}

void DrawStack::draw() {
	stack.sort(compareDrawableObjects);

	for(it = stack.begin(); it != stack.end(); ) {

		//it is a drawableObject** :3
		(*it)->draw();

		if((*it)->destroy) {
			//delete (*it);
			it = stack.erase(it);
		}
		else {
			++it;
		}
	}
}

unsigned int DrawStack::length() {
	return stack.size();
}

DrawableObject* DrawStack::getElement(int index) {
	it = stack.begin();

	for(int i = 0; i < index; i++) ++it;

	return (*it);
}

bool compareDrawableObjects(DrawableObject* o1, DrawableObject* o2) {
	return o1->priority < o2->priority;
}
