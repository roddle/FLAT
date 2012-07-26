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


#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(const char* filename, const char* soundFilename)
{
	image = DrawableBitmap(filename);
	crosshair = DrawableBitmap("gfx/crosshair.png");
	muzzleFlash = DrawableBitmap("gfx/muzzleflash.png");
	crosshair.setPosition(vec2(640.0f, 365.0f));

	fireSound = al_load_sample(soundFilename);

	isReadyToFire = true;
	isFiring = false;
	isHoldingFire = false;
	isSwitching = true;
	drawMuzzleFlash = false;

	firing = false;

	fireTimer = 0;
	fireAnimationTimer = 0;
	aimTimer = 0;

	kb = 0.0f;
}

Weapon::~Weapon()
{
	//dtor
}

void Weapon::fire() {
	if(isReadyToFire) {

		fireTimer = fireTimerMax;
		fireAnimationTimer = fireAnimationTimerMax;
		aimTimer = aimTimerMax;
		isReadyToFire = false;
		isFiring = true;
		drawMuzzleFlash = true;
		firing = true;

		kb = kickback;

		al_play_sample(fireSound, 0.8f, 0.8f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	isHoldingFire = true;
}

void Weapon::draw() {
	float dy = 0.0f;
	float dx = 0.0f;
	float dz = 0.0f;
	float da = 0.0f;

	if(fireAnimationTimer > 0) {
		float sinAngle = sin((fireAnimationTimer/fireAnimationTimerMax)*PI);

		if(fireAnimationTimer < fireAnimationTimerMax*angleDuration) {
			da += angleMultiplier*sin((fireAnimationTimer/(angleDuration*fireAnimationTimerMax))*PI);
		}

		dy += yKick*sinAngle;
		dx += xKick*sinAngle;
		dz += zKick*sinAngle;
	}

	float sinRatio = sin((1.0f-switchRatio)*(PI/2));
	float cosRatio = 1.0f-cos((1.0f-switchRatio)*(PI/2));

	dz -= cosRatio * 0.5;
	dy += cosRatio * 350.0f;
	dx -= cosRatio * 300.0f;
	da -= cosRatio;

	dy += lingerKick*(1.0f-cos((aimTimer/aimTimerMax)*PI));

	dx += sin(phase)*50.0f;
	dy += cos(phase)*20.0f;
	da += sin(phase)*-0.1f;

	image.setPosition(vec2(standardPosition.x+dx, standardPosition.y+dy));
	image.setRotation(da);
	image.setScale(1.0f + dz);

	if(drawMuzzleFlash) {

		//Additive alpha blending
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

		muzzleFlash.setPosition(vec2(muzzlePosition.x+sin(phase)*50.0f, muzzlePosition.y+cos(phase)*10.0f));
		muzzleFlash.setScale(muzzleScale);
		muzzleFlash.setRotation(random(PI));

		muzzleFlash.draw();
		drawMuzzleFlash = false;

		//Premultiplied alpha blending
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);

	}

	image.draw();
	crosshair.draw();

}

void Weapon::update() {

	if(isFiring) {
		fireTimer -= TIME_STEP;
	}
	isFiring = fireTimer > 0;

	if(aimTimer > 0) {
		aimTimer -= TIME_STEP;
	}

	if(fireAnimationTimer > 0) {
		fireAnimationTimer -= TIME_STEP;
	}

	isReadyToFire = !isFiring && (!isHoldingFire || automatic) && !isSwitching;
	isHoldingFire = false;
	kb = 0.0f;
	firing = false;
}

void Weapon::setSwitchRatio(float ratio) {
	switchRatio = ratio;
}

void Weapon::setSwitching(bool switching) {
	isSwitching = switching;
}

void Weapon::setPhase(float _phase) {
	phase = _phase;
}
