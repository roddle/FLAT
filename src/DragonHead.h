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


#ifndef DRAGONHEAD_H
#define DRAGONHEAD_H

#include <vector>
#include <cmath>
#include <allegro5/allegro_audio.h>
#include "FrameContainer.h"
#include "Character.h"
#include "DragonSpine.h"
#include "DrawStack3D.h"
#include "Player.h"


#define DRAGON_SPINE_LENGTH 40
#define DRAGON_WAVE_AMPLITUDE 0.7f

#define DRAGON_ROAM_CENTRAL_FORCE 0.2f
#define DRAGON_ROAM_WAVE_AMPLITUDE 3.0f

#define DRAGON_TERMINAL_VELOCITY 0.8f
#define DRAGON_BASE_ACCELERATION 0.02f
#define DRAGON_EXTRA_ACCELERATION 0.03f
#define DRAGON_FRICTION 0.98f
#define DRAGON_MIN_CHARGE_DISTANCE 30.0f

#define DRAGON_KNOCKBACK_FORCE 1.0f
#define DRAGON_KNOCKBACK_AIR 7.0f
#define DRAGON_KNOCKBACK_RANGE 2.0f
#define DRAGON_KNOCKBACK_DAIRTIME 0.1f

#define DRAGON_FLEE_ACCELERATION 0.003f
#define DRAGON_FLEE_TERMINAL_VELOCITY 0.15f
#define DRAGON_FLEE_JERKING_ACCELERATION 0.02f
#define DRAGON_FLEE_FIRE_TIMER 1.5f
#define DRAGON_FLEE_FIRE_STARTUP_TIME 3.0f
#define DRAGON_FLEE_MAX_DISTANCE 300.0f

#define DRAGON_WRITHE_SPEED 0.05f
#define DRAGON_WRITHE_AIR 1.0f

#define DRAGON_ATTACK_DAMAGE 0.25f

#ifndef PI
#define PI 3.14159265
#endif

#ifndef TIME_STEP
#define TIME_STEP 0.016666667f
#endif

class DragonHead : public Character
{
	public:
		DragonHead();
		DragonHead(DrawStack3D* world3D, vector <Character*> *npc);
		virtual ~DragonHead();

		void draw();
		void update();

		void setImageParameters(vec2 _position, float _scale, float _rotation);

		void setPlayerAngle2(float angle);

		void setPlayer(Player* _player);

		void dealDamage(float howMuch);

		virtual bool isInvurnable();

		bool dragon;

		ALLEGRO_DISPLAY* display;
	protected:

		void updateIndex();
		FrameContainer headFrames;
		float playerAngle;

		ALLEGRO_SAMPLE* roar1;
		ALLEGRO_SAMPLE* roar2;
		ALLEGRO_SAMPLE* deathSample;
		ALLEGRO_SAMPLE* painSample;
		ALLEGRO_SAMPLE* ambience;

		float time;

		int phase;

		int stage;

		float writheOffset;

		bool invurnable;

		vector <DragonSpine*> spine;

		Player* player;

		float roar1Timeout;
		float roar2Timeout;

	private:

				ALLEGRO_BITMAP* splashEnd;
};

#endif // DRAGONHEAD_H
