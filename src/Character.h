/*
Copyright 2012 Johan "SteelRaven7" Hassel
Copyright 2012 Josh "Cheeseness" Bush

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


#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro5/allegro_audio.h>

#include "vec3.h"
#include "vec2.h"
#include "DrawableObject.h"
#include "DrawableBitmap.h"
#include "Projectile.h"
#include "FrameSuperContainer.h"

#define TYPE_GRUNT 0
#define TYPE_DRAGON 1

#define GRUNT_CRUISE_SPEED 0.005f
#define GRUNT_CRUISE_SPEED_RANDOM 0.002f
#define GRUNT_CRUISE_FRICTION 0.99f

#define GRUNT_CHASE_BOOST 0.004f
#define GRUNT_CHASE_TIME 10.0f

#define GRUNT_BRAKE_SPEED 0.01f
#define GRUNT_BRAKE_FRICTION 0.92f

#define GRUNT_CIRCLE_SPEED 0.004f
#define GRUNT_CIRCLE_FRICTION 0.98f

#define GRUNT_FIRE_TIMER 4.0f
#define GRUNT_FIRE_TIMER_RANDOM 1.0f
#define GRUNT_FIRE_RANGE 60.0f

#define GRUNT_PROJECTILE_SPEED 0.8f
#define GRUNT_PROJECTILE_DAMAGE 0.1f

#define DRAGON_PROJECTILE_SPEED 1.0f

#define FRAME_NUMBER 12

#define ANIMATION_SPEED 1.5f

#ifndef PI
#define PI 3.14159265
#endif

#ifndef TIME_STEP
#define TIME_STEP 0.01666667f
#endif

class Character : public DrawableObject
{
	public:
		Character();
		virtual ~Character();

		virtual void update();
		void draw();

		bool visible;

		void setVisibility(bool _visible);

		void setBitmap(DrawableBitmap _bitmap);
		DrawableBitmap getBitmap();
		void setProjectileStarburstBitmap(DrawableBitmap _bitmap);
		void setProjectileHaloBitmap(DrawableBitmap _bitmap);

		void setPosition(vec3 _position);
		void setFacingAngle(float _angle);

		vec3 getPosition();
		float getFacingAngle();

		float getPlayerAngle();
		void setPlayerAngle(float angle);

		float getPlayerDistance();
		void setPlayerDistance(float distance);

		void setImageParameters(vec2 _position, float _scale, float _rotation);

		void updateTarget(vec2 _targetPosition, vec2 _targetVelocity);

		virtual void dealDamage(float howMuch);

		bool isFiring();

		float getProjectileSpeed();

		Projectile* getProjectile();

		int enemyType;

		virtual bool isInvurnable();

		void setFrame(FrameSuperContainer c);

		void useContainer();

		void setPlayerAngle2(float angle);

		bool dragon;

	protected:

		DrawableBitmap projectileStarburstBitmap;
		DrawableBitmap projectileHaloBitmap;

		ALLEGRO_SAMPLE* fireSample;
		ALLEGRO_SAMPLE* skateSample;
		ALLEGRO_SAMPLE* deathSample;
        ALLEGRO_SAMPLE* painSample;

		float playerAngle;
		float playerDistance;

		vec3 position;
		vec2 velocity;
		float angle;

		float facingAngle;

		float health;

		bool firing;

		float fireTimer;

		bool invurnable;

		bool usingContainer;

		FrameSuperContainer container;

		float rotationAngle;

		float animationFrame;

	private:

		DrawableBitmap bitmap;

		vec2 targetPosition;
		vec2 targetVelocity;

		float friction;

		float surroundDir;

		float headingAngle;

		void updateGruntAI();

		float chaseTimer;
};

#endif // CHARACTER_H
