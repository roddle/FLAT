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


#include "DragonSpine.h"

DragonSpine::DragonSpine()
{
	visible = true;
	unlinked = false;
	onground = false;
	velocity = vec3(0.0f, 0.0f, 0.0f);
	distance = 1.0f;
	invurnable = true;
	health = 1.0f;
	entityType = 0;
}

DragonSpine::~DragonSpine()
{
	//dtor
}

bool DragonSpine::isInvurnable() {
	return invurnable;
}

void DragonSpine::setImageParameters(vec2 _position, float _scale, float _rotation) {
	updateIndex();
	spineFrames.setImageParameters(_position, _scale*18.0f, _rotation);
	spineFrames.setImageFloatingHeight(-80.0f - 50.0f*position.z);
}

void DragonSpine::setVelocity(vec3 vel) {
	velocity = vel;
}

void DragonSpine::setVurnability(bool v) {
	invurnable = !v;
}

void DragonSpine::updateIndex() {
	int len = spineFrames.getNumber();
	float angle = playerAngle - facingAngle + PI/16;

	while(angle < 0) {
		angle += 2*PI;
	}
	while(angle >= 2*PI) {
		angle -= 2*PI;
	}

	spineFrames.setIndex((int)(angle/(2*PI)*((float)len)));
}

void DragonSpine::draw() {
	if(!visible) {
		return;
	}

	spineFrames.draw();
}

void DragonSpine::update() {
	if(unlinked) {
		position += velocity;

		if(!onground) {
			velocity.z += 0.02f;
		} else {
			velocity.z = 0;
			position.z = 1.4f;
		}

		if(position.z > 1.4f || onground) {
			position.z = 1.4f;
			velocity.z *= -0.5f;
			velocity.x *= 0.95f;
			velocity.y *= 0.95f;

			if(abs(velocity.z) < 0.1f && position.z > 1.35 && !onground) {
				onground=true;

				//Make this object a detail object so that it is cleaned up if too far away from the camera.
				entityType = 1;
			}
		}
	}
}

void DragonSpine::dealDamage(float howMuch) {
	if(invurnable) {
		return;
	}

	health -= howMuch;

	if(health < 0) {
		unlinked = true;

		velocity.x += cos(playerAngle)*howMuch*0.2f;
		velocity.y += sin(playerAngle)*howMuch*0.2f;
		velocity.z = -howMuch*0.3f;
		onground = false;

		if(position.z > 1.35) {
			position.z = 1.35;
		}
	}
}

void DragonSpine::setPlayerAngle2(float angle) {
	playerAngle = angle;
}

void DragonSpine::setFrameContainer(FrameContainer c) {
	spineFrames = c;
}

void DragonSpine::setPosition(vec3 _position) {
	position = _position;
}

vec3 DragonSpine::getPosition() {
	return position;
}

void DragonSpine::setFacingAngle(float angle) {
	facingAngle = angle;
}
