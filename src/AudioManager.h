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


#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "utilities.h"


#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/mouse.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define GAME_STATE_NONE -1
#define GAME_STATE_NORMAL 0
#define GAME_STATE_COMBAT 1
#define GAME_STATE_DRAGON 2

class AudioManager
{
    public:
        AudioManager();
        virtual ~AudioManager();
        int getGameState();
        void setGameState(int newState);
        void stopAudio();
        void setAudioCue(ALLEGRO_SAMPLE* newCue);

    protected:
    private:
        int gameState;
        ALLEGRO_SAMPLE* normalMusic;
        ALLEGRO_SAMPLE* combatMusic;
        ALLEGRO_SAMPLE* dragonMusic;
        ALLEGRO_SAMPLE_ID* currentSample;
//        ALLEGRO_MIXER musicMixer;
};

#endif // AUDIOMANAGER_H
