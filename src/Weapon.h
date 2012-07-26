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


#ifndef WEAPON_H
#define WEAPON_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>

#include "DrawableObject.h"
#include "DrawableBitmap.h"
#include "DrawableCircle.h"
#include "DrawStack.h"
#include "BitmapBuffer.h"
#include "utilities.h"

#ifndef PI
#define PI 3.14159265f
#endif

#ifndef TIME_STEP
#define TIME_STEP 0.01666667f
#endif


class Weapon : public DrawableObject
{
	public:
		Weapon();
		Weapon(const char* filename, const char* soundFilename);
		virtual ~Weapon();

		void update();
		void draw();

		void fire();

		void generateMuzzleFlash(float radius);

		void setSwitchRatio(float ratio);

		void setSwitching(bool switching);

		vec2 standardPosition;

		bool automatic;

		vec2 muzzlePosition;

		float muzzleScale;

		float fireTimerMax;
		float fireAnimationTimerMax;
		float aimTimerMax;

		float angleDuration;
		float angleMultiplier;

		float xKick;
		float yKick;
		float zKick;

		int rounds;
		float spread;

		float lingerKick;

		float kickback;

		float kb;

		bool firing;
		float fireDamage;

		void setPhase(float _phase);
	protected:
	private:
		DrawableBitmap image;
		DrawableBitmap crosshair;
		ALLEGRO_SAMPLE* fireSound;


		DrawableBitmap muzzleFlash;


		float fireTimer;
		float fireAnimationTimer;
		float aimTimer;

		float switchRatio;

		float phase;

		bool isReadyToFire;
		bool isFiring;
		bool isHoldingFire;
		bool isSwitching;

		bool drawMuzzleFlash;
};

#endif // WEAPON_H
