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


#include "Projectile.h"

Projectile::Projectile()
{
	visible = true;

	//Tells DrawStack3D to delete this object if it's too far away from the camera.
	entityType = 1;

	time = 0.0f;
}

Projectile::~Projectile()
{
	//dtor
}

void Projectile::draw() {
	if(visible) {
		starburstBitmap.draw();
		haloBitmap.draw();
	}
}

void Projectile::setVelocity(vec2 _velocity) {
	velocity = _velocity;
}

void Projectile::update() {
	position.x += velocity.x;
	position.y += velocity.y;

	time+=TIME_STEP;
}

void Projectile::setStarburstBitmap(DrawableBitmap bitmap) {
	starburstBitmap = bitmap;
}

void Projectile::setHaloBitmap(DrawableBitmap bitmap) {
	haloBitmap = bitmap;
}

void Projectile::setImageParameters(vec2 _position, float _scale, float _rotation) {
	starburstBitmap.setPosition(_position);
	starburstBitmap.setScale(_scale*7.0f);
	starburstBitmap.setRotation(_rotation);

	float localRotation = time*2.0f;
	float localScale = 0.8f+sin(time*5.0f)*0.3f;

	starburstBitmap.setLocalRotation(localRotation);

	haloBitmap.setPosition(_position);
	haloBitmap.setScale(_scale*7.0f);
	haloBitmap.setRotation(_rotation);

	haloBitmap.setLocalScale(localScale);
}
