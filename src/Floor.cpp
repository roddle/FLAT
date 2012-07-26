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


#include "Floor.h"

Floor::Floor()
{
	tilt = 0.0f;
	position = vec3(0.0f, 0.0f, 0.0f);

	color = al_map_rgb(100, 120, 150);

	sceneryIndex = 1;

	sky[0] = al_load_bitmap("gfx/grad_1_sky.png");
	ice[0] = al_load_bitmap("gfx/grad_1_ice.png");
	sky[1] = al_load_bitmap("gfx/grad_2_sky.png");
	ice[1] = al_load_bitmap("gfx/grad_2_ice.png");
	scenery[0] = al_load_bitmap("gfx/crystal_cliff.png");
	scenery[1] = al_load_bitmap("gfx/mountain00.png");
	scenery[2] = al_load_bitmap("gfx/mountain03.png");
	scenery[3] = al_load_bitmap("gfx/mountain02.png");
	scenery[4] = al_load_bitmap("gfx/mountain01.png");
	scenery[5] = al_load_bitmap("gfx/mountain2_01.png");
	scenery[6] = al_load_bitmap("gfx/mountain2_06.png");
	scenery[7] = al_load_bitmap("gfx/mountain2_15.png");
	scenery[8] = al_load_bitmap("gfx/mountain2_12.png");
	scenery[9] = al_load_bitmap("gfx/moon2.png");
	scenery[10] = al_load_bitmap("gfx/moon2.png");
	scenery[11] = al_load_bitmap("gfx/moon2.png");
	scenery[12] = al_load_bitmap("gfx/moon2.png");
	scenery[13] = al_load_bitmap("gfx/stars.png");
	scenery[14] = al_load_bitmap("gfx/stars.png");
	scenery[15] = al_load_bitmap("gfx/stars.png");
	scenery[16] = al_load_bitmap("gfx/stars.png");
	scenery[17] = al_load_bitmap("gfx/stars.png");
    scenery[18] = al_load_bitmap("gfx/stars.png");
	scenery[19] = al_load_bitmap("gfx/stars.png");
	scenery[20] = al_load_bitmap("gfx/stars.png");
	scenery[21] = al_load_bitmap("gfx/stars.png");
	scenery[22] = al_load_bitmap("gfx/stars.png");
	scenery[23] = al_load_bitmap("gfx/stars.png");
	scenery[24] = al_load_bitmap("gfx/stars.png");
	scenery[25] = al_load_bitmap("gfx/stars.png");
	scenery[26] = al_load_bitmap("gfx/stars.png");


	sceneryAngle[0] = 1.8f;
	sceneryAngle[1] = -0.3f; //Not 100% sure on the placement of this one
	sceneryAngle[2] = -1.4f;
	sceneryAngle[3] = -2.6f;
	sceneryAngle[4] = 1.3f;
	sceneryAngle[5] = -0.5f;
	sceneryAngle[6] = -1.0f;
	sceneryAngle[7] = -2.0f;
	sceneryAngle[8] = 2.3f;
	sceneryAngle[9] = 0.5f;
	sceneryAngle[10] = 0.2f;
	sceneryAngle[11] = 0.6f;
	sceneryAngle[12] = 0.9f;
	sceneryAngle[13] = 0.5f;
	sceneryAngle[14] = 1.0f;
	sceneryAngle[15] = 1.5f;
	sceneryAngle[16] = 2.0f;
	sceneryAngle[17] = 2.5f;
	sceneryAngle[18] = 3.0f;
	sceneryAngle[19] = 3.5f;
	sceneryAngle[20] = 4.0f;
	sceneryAngle[21] = 4.5f;
	sceneryAngle[22] = 5.0f;
	sceneryAngle[23] = 5.5f;
	sceneryAngle[24] = 6.0f;
	sceneryAngle[25] = 6.5f;

	for(int i = 0; i < 26; i++) {
		//Gives the center coordinates for each image, which
		//it'll pivot around when rotated.
		sceneryCenter[i].x = al_get_bitmap_width(scenery[i])/2.0f;
		sceneryCenter[i].y = al_get_bitmap_height(scenery[i]) - 5.0f; //Minus 5 pixels to make sure the edge is always under the horizon.
		sceneryScale[i] = 1.0f;
	}

    sceneryCenter[9].y = 450.0f;
    sceneryCenter[10].y = 300.0f;
    sceneryCenter[11].y = 400.0f;
    sceneryCenter[12].y = 325.0f;
    sceneryCenter[13].y = 400.0f;
    sceneryCenter[14].y = 390.0f;
    sceneryCenter[15].y = 420.0f;
    sceneryCenter[16].y = 375.0f;
    sceneryCenter[17].y = 450.0f;
    sceneryCenter[18].y = 400.0f;
    sceneryCenter[19].y = 390.0f;
    sceneryCenter[20].y = 420.0f;
    sceneryCenter[21].y = 375.0f;
    sceneryCenter[22].y = 450.0f;
    sceneryCenter[23].y = 360.0f;
    sceneryCenter[24].y = 410.0f;
    sceneryCenter[25].y = 420.0f;

    sceneryScale[9] = 1.0f;
    sceneryScale[10] = 0.5f;
    sceneryScale[11] = 0.7f;
    sceneryScale[12] = 0.6f;


}

Floor::~Floor()
{
	//dtor
}


void Floor::swapScenery()
{
    if (sceneryIndex == 0)
    {
        sceneryIndex = 1;
    }
    else
    {
        sceneryIndex = 0;
    }
}

void Floor::setCamera(vec3 _position, float _angle, float _tilt) {
	position = _position;
	tilt = _tilt;
	angle = _angle;
}

void Floor::draw() {

	float dHeight = sin(tilt)*640.0f;

	float heightLeft = 360.0f-dHeight;
	float heightRight = 360.0f+dHeight;

	al_draw_scaled_rotated_bitmap(sky[sceneryIndex], 2.5f, 256, 640, 85-abs(tilt*30.0f), 300.0f, 1.1f, tilt*0.95f, 0);

    //TODO: Fix this because Cheese is useless :3
    //Fixed :D:D:D

    for(int i = 0; i < 26; i++) {
    	float dAngle = angle-sceneryAngle[i];

    	while(dAngle > PI) {
			dAngle -= 2*PI;
    	}

    	while(dAngle < -PI) {
			dAngle += 2*PI;
    	}


		float dx = (dAngle*900.0f*(0.9f+0.1f*abs(sin(dAngle))));
		al_draw_scaled_rotated_bitmap(scenery[i], sceneryCenter[i].x, sceneryCenter[i].y, 640.0f+dx, 360.0f + sin(tilt)*dx, sceneryScale[i], sceneryScale[i], tilt*0.95f, 0);
    }

	al_draw_scaled_rotated_bitmap(ice[sceneryIndex], 2.5f, 256, 640, 640+abs(tilt*30.0f), 300.0f, 1.1f, tilt*0.95f, 0);
    for(int i = 0; i < 26; i++) {
    	float dAngle = angle-sceneryAngle[i];

    	while(dAngle > PI) {
			dAngle -= 2*PI;
    	}

    	while(dAngle < -PI) {
			dAngle += 2*PI;
    	}


		float dx = (dAngle*900.0f*(0.9f+0.1f*abs(sin(dAngle))));

        al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
		//al_draw_scaled_rotated_bitmap(scenery[i], sceneryCenter[i].x, sceneryCenter[i].y, 640.0f+dx, 360.0f + sin(tilt)*dx, sceneryScale[i], -sceneryScale[i], tilt*0.95f, 0);
		if (i > 8)
		{
            al_draw_tinted_scaled_rotated_bitmap(scenery[i], al_map_rgba(0.9f*255, 0.9f*255, 255, 50), sceneryCenter[i].x, sceneryCenter[i].y, 640.0f+dx, 360.0f + sin(tilt)*dx, sceneryScale[i], -sceneryScale[i], tilt*0.95f, 0);

		}
		else
		{
            al_draw_tinted_scaled_rotated_bitmap(scenery[i], al_map_rgba(0.9f*255, 0.9f*255, 255, 50), sceneryCenter[i].x, sceneryCenter[i].y, 640.0f+dx, 360.0f + sin(tilt)*dx, sceneryScale[i], -sceneryScale[i]/2, tilt*0.95f, 0);
		}
//		al_draw_tinted_scaled_rotated_bitmap(scenery[i], al_map_rgba(0.9f*255, 0.9f*255, 255, 50), sceneryCenter[i].x, sceneryCenter[i].y, 640.0f+dx, 360.0f + sin(tilt)*dx, sceneryScale[i], -sceneryScale[i], tilt*0.95f, 0);
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
    }
}
