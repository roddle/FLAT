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


#include "DrawableObject.h"

DrawableObject::DrawableObject()
{
	priority = 20000;
	destroy = false;

	entityType = 0;
}

DrawableObject::~DrawableObject()
{
	//dtor
}

void DrawableObject::draw() {
	Print("Non-overloaded draw()-call!");
}

vec3 DrawableObject::getPosition() {
	Print("getPosition() not overloaded");
	return vec3(0.0f, 0.0f, 0.0f);
}

float DrawableObject::getFacingAngle() {
	Print("getFacingAngle() not overloaded");
	return 0.0f;
}

void DrawableObject::setImageParameters(vec2 _position, float _scale, float _rotation) {
	Print("setImagePosition() not overloaded");
}

void DrawableObject::setVisibility(bool _visible) {
	Print("setVisibility() not overloaded");
}

void DrawableObject::setPlayerAngle2(float angle) {}
void DrawableObject::setPlayerAngle(float angle) {}
float DrawableObject::getPlayerAngle() {}

void DrawableObject::setPlayerDistance(float distance) {}
float DrawableObject::getPlayerDistance() {}
