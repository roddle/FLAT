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


#include "DrawStack3D.h"

DrawStack3D::DrawStack3D()
{
	camera = vec3(0.0f, 0.0f, 0.0f);
	angle = 0.0f;

	tilt = 0.0f;

	stack = DrawStack();
}

DrawStack3D::~DrawStack3D()
{
	//dtor
}

void DrawStack3D::push(DrawableObject* o) {
	stack.push(o);
}

void DrawStack3D::draw() {
	updatePositions();

	//al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	stack.draw();
	//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
}

void DrawStack3D::updatePositions() {

	tilt*=0.95;

	int len = stack.length();

	float cosTilt = cos(tilt);
	float sinTilt = sin(tilt);

	for(int i = 0; i < len; i++) {
		DrawableObject* e = stack.getElement(i);

		vec3 charPos = e->getPosition();

		float dy = charPos.y-camera.y;
		float dx = charPos.x-camera.x;
		float dz = charPos.z-camera.z;

		float charAngle = atan2f(dy, dx);

		float dAngle = mod(angle, 2.0f*PI) - mod(charAngle, 2.0f*PI);

		//Clamp dAngle between -PI and PI
		if(dAngle > PI) {
			dAngle -= PI*2.0f;
		}

		if(dAngle < -PI) {
			dAngle += PI*2.0f;
		}

		float distance = length(vec3(dx, dy, dz));

		//Used for weapon 'raycasts'.
		e->setPlayerAngle2(charAngle);
		e->setPlayerAngle(dAngle);
		e->setPlayerDistance(distance);
		//

		float absDAngle = abs(dAngle);

		distance = length(vec3(dx, dy, dz));

		if(distance > DETAIL_OBJECT_DESTROY_DISTANCE && e->entityType == 1) {
			//Destroy detail object.
			e->destroy = true;
		}

		if(distance > 500.0f || dAngle > PI/2 || dAngle < -PI/2) {
			e->setVisibility(false);
		} else {
			e->setVisibility(true);

			//Fake some field of view perspective stuff.
			float dX = dAngle*FIELD_OF_VIEW_WIDTH*(0.9f+0.1f*abs(sin(dAngle)));

			float dZ = 400.0f*(dz)/distance;

			float scale = 1.0f/distance;


			if(distance < PI) {
				dZ += cos(distance/2.0f)*150.0f;
			}



			//Tilt offsets:
			float oX = -sinTilt*dZ+cosTilt*dX;
			float oY = sinTilt*dX+cosTilt*dZ;


			e->setImageParameters(vec2(640+oX, 360+oY), scale, tilt);
			e->priority = scale;
		}
	}
}

void DrawStack3D::setCamera(vec3 _position, float _angle, float _tilt) {
	camera = _position;
	angle = _angle;
	tilt = _tilt;
}

void DrawStack3D::incrementRotation(float da) {
	angle += da;
}

void DrawStack3D::incrementCamera(vec3 dPos) {
	float sinAng = sin(angle);
	float cosAng = cos(angle);

	camera.x += dPos.x*cosAng-dPos.y*sinAng;
	camera.y += dPos.y*cosAng+dPos.x*sinAng;

	tilt += 0.1f*dPos.y;
}
