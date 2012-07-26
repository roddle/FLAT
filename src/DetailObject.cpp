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


#include "DetailObject.h"

DetailObject::DetailObject()
{
	visible = true;

	//Tells DrawStack3D to delete this object if it's too far away from the camera.
	entityType = 1;

	radius = 2.0f;
}

DetailObject::~DetailObject()
{
	//dtor
}

void DetailObject::draw() {

	if(visible) {
		bitmap.draw();
	}
}

void DetailObject::setVisibility(bool _visible) {
	visible = _visible;
}

void DetailObject::setBitmap(DrawableBitmap _bitmap) {
	bitmap = _bitmap;
}

DrawableBitmap DetailObject::getBitmap() {
	return bitmap;
}

vec3 DetailObject::getPosition() {
	return position;
}

vec2 DetailObject::getPos() {
	return vec2(position.x, position.y);
}

float DetailObject::getRadius() {
	return radius;
}

void DetailObject::setPosition(vec3 _position) {
	position = _position;
}

void DetailObject::setImageParameters(vec2 _position, float _scale, float _rotation) {
	bitmap.setPosition(_position);
	bitmap.setScale(_scale*10.0f);
	bitmap.setRotation(_rotation);
}

void DetailObject::pushImage(DrawableBitmap b) {}
void DetailObject::setPrescale(float s) {}
void DetailObject::update() {}
void DetailObject::setJumpable() {}
bool DetailObject::isJumpable() {return false;}
