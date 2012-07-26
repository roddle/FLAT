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


#ifndef DRAGONSPINE_H
#define DRAGONSPINE_H

#include "Character.h"
#include "FrameContainer.h"

#ifndef PI
#define PI 3.14159265
#endif

class DragonSpine : public Character
{
	public:
		DragonSpine();
		virtual ~DragonSpine();

		void draw();

		void setImageParameters(vec2 _position, float _scale, float _rotation);

		void update();

		void setPlayerAngle2(float angle);

		void setFrameContainer(FrameContainer c);

		void setPosition(vec3 _position);
		vec3 getPosition();

		void setFacingAngle(float angle);

		void dealDamage(float howMuch);

		void setVelocity(vec3 vel);

		bool unlinked;
		bool onground;

		float distance;

		void setVurnability(bool v);

		bool isInvurnable();
	protected:

		void updateIndex();
		FrameContainer spineFrames;
		float playerAngle;

		vec3 velocity;

		bool invurnable;
};

#endif // DRAGONSPINE_H
