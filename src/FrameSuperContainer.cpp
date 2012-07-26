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


#include "FrameSuperContainer.h"

FrameSuperContainer::FrameSuperContainer()
{
	index = 0;
}

FrameSuperContainer::~FrameSuperContainer()
{
	//dtor
}

void FrameSuperContainer::draw() {
	if(index < 0 || index > container.size()) {
		Print("FrameSuperContainer: index out of bounds.");
		return;
	}

	container[index].draw();
}

void FrameSuperContainer::push(FrameContainer c) {
	container.push_back(c);
}

void FrameSuperContainer::setIndex(int i) {
	index = i;
}

void FrameSuperContainer::setSubIndex(int i) {
	container[index].setIndex(i);
}

int FrameSuperContainer::getNumber() {
	return container.size();
}

void FrameSuperContainer::setImageParameters(vec2 _position, float _scale, float _rotation) {
	container[index].setImageParameters(_position, _scale*8.0f, _rotation);
}
