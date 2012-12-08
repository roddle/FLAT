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


#include "StaticObject.h"

StaticObject::StaticObject()
{
	scale = 0.0f;
	jumpable = false;
	//playerAngle = 0.0f;
}

StaticObject::~StaticObject()
{
	//dtor
}

void StaticObject::pushImage(DrawableBitmap b) {
	frames.push(b);
}

void StaticObject::setImageParameters(vec2 _position, float _scale, float _rotation) {
	update();

	int len = frames.getNumber();
	float angle = playerAngle;

	//Clamp angle between 0 and 2*PI
	angle += PI;

	frames.setIndex((int)(angle/(2*PI)*((float)len)));

	frames.setImageParameters(_position, _scale*scale, _rotation);
}

void StaticObject::update() {
	if(scale < targetScale) {
		scale += 0.1f;
	}
}

void StaticObject::draw() {
	if(!visible) {
		return;
	}
	frames.draw();
}

void StaticObject::setPlayerAngle2(float angle) {
	playerAngle = angle;
}

void StaticObject::setPrescale(float s) {
	targetScale = s;
}

bool StaticObject::isJumpable() {
	return jumpable;
}

void StaticObject::setJumpable() {
	jumpable = true;
}
