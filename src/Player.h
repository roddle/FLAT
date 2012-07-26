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


#ifndef PLAYER_H
#define PLAYER_H

#define LOSE_TIME 1.5f

#define FRICTION_BASE 0.991f
#define FRICTION_MODIFIER_MULTIPLIER 0.005f

#define LEAN_MULTIPLIER 0.02f
#define LEAN_DRAG 0.97f

#define TURN_SENSETIVITY 0.006f
#define SPEED 0.10f
#define SPEED_CARVING 0.018f

#define SPEED_BACKWARDS_MULTIPLIER 1.0f

//Total frames = PI/JUMP_DTIME
#define JUMP_DTIME 0.14f
#define JUMP_HEIGHT 2.0f
#define JUMP_PUSH 0.1f

#define HEIGHT_DRAG 0.92f
#define HEIGHT_ACCELERATE_AMMOUNT 2.0f

#define WEAPON_SWITCH_TIME 1.0f

#define INVURNABILITY_TIME 0.5f

#ifndef TIME_STEP
#define TIME_STEP 0.01666667f
#endif

#define CHARACTER_HEIGHT 1.0f

#ifndef PI
#define PI 3.14159265
#endif

#include <cmath>
#include <allegro5/allegro_audio.h>
#include "DrawableObject.h"
#include "Weapon.h"
#include "utilities.h"
#include "vec2.h"
#include "vec3.h"

class Player : public DrawableObject
{
	public:
		Player();
		virtual ~Player();

		void update();

		void draw();

		void holdForward();
		void holdBackward();
		void holdLeft();
		void holdRight();

		void jump();
		void jumpRelease();
		bool isJumping();

		bool isVurnable();

		void turn(float ratio);

		vec2 getVel();
		vec2 getPos();

		void setVelocity(vec2 vel);
		void setPosition(vec2 pos);

		vec3 getCameraPosition();
		float getCameraAngle();
		float getCameraTilt();

		void switchWeapon(int index);

		void fire();

		void knockback(vec2 direction, float force, float air, float dTime);

		float getWeaponDamage();
		int getWeaponRounds();
		float getWeaponSpread();

		void pickup();

		bool firing;

		void takeDamage(float dmg);

		void heal();

        int getHealth();

		bool gameOver;
	protected:
	private:
		Weapon pistol;
		Weapon shotgun;
		Weapon smg;

		ALLEGRO_SAMPLE* skateSound;
		ALLEGRO_SAMPLE* painSounds[3];
		ALLEGRO_SAMPLE* deathSound;
        ALLEGRO_SAMPLE* pickupSound;


		float displayHealthTimer;

		ALLEGRO_BITMAP* healthBitmap;

		Weapon* currentWeapon;

		Weapon* weaponList[4];

		DrawableBitmap hurtOverlay;

		vec3 position;
		vec2 velocity;
		vec2 acceleration;

		float angle;
		float tilt;

		float frictionmodifier;

		float lean;
		float leanmodifier;

		float height;

		float invurnabilityTimeout;

		float jumpPhase;
		vec2 jumpDirection;
		bool jumping;
		bool wantsToJump;
		float airHeight;
		float jumpDTime;

		int currentWeaponIndex;
		int nextWeaponIndex;
		float weaponSwitchTimeout;

		float health;
		float loseTimer;
		bool passingOut;

		bool holdingLeft;
		bool holdingRight;
		bool holdingBack;
		bool holdingJump;

		int weaponPickup;
		int healthpacks;

		int lastDir;

		float time;

		float healthCD;
};

#endif // PLAYER_H
