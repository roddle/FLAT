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


#include "FrameContainer.h"

FrameContainer::FrameContainer()
{
	index = 0;
}

FrameContainer::~FrameContainer()
{
	//dtor
}

void FrameContainer::push(DrawableBitmap o) {
	frame.push_back(o);
}

void FrameContainer::setIndex(int i) {
	index = i;
	assert(index >= 0);
	//index = 0;
}

void FrameContainer::draw() {
	if(index < 0 || index >= frame.size()) {
		Print("FrameContainer: index out of bounds.");
		return;
	}

	frame[index].draw();
}

void FrameContainer::setImageParameters(vec2 _position, float _scale, float _rotation) {
	frame[index].setPosition(_position);
	frame[index].setScale(_scale);
	frame[index].setRotation(_rotation);
}

void FrameContainer::setImageFloatingHeight(float height) {
	frame[index].setFloatingHeight(height);
}

int FrameContainer::getNumber() {
	return frame.size();
}

void FrameContainer::clear() {
	frame.clear();
}

void FrameContainer::setTint(int r, int g, int b) {
	frame[index].setTint(r, g, b);
}
