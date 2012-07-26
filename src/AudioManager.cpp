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


#include "AudioManager.h"


AudioManager::AudioManager()
{
    gameState = GAME_STATE_NONE;

    currentSample = new ALLEGRO_SAMPLE_ID();

    if(!al_init_acodec_addon())
        cout<<"couldnt install audio codecs"<<endl;


    normalMusic = al_load_sample("music/normal.wav");
    combatMusic = al_load_sample("music/combat.wav");
    dragonMusic = al_load_sample("music/dragon.wav");

    //ctor
}

int AudioManager::getGameState()
{
    return gameState;
}


void AudioManager::setGameState(int newState)
{
    if ((newState != gameState) && (gameState != GAME_STATE_DRAGON))
    {
        switch (newState)
        {
            case GAME_STATE_NONE:
                stopAudio();
                break;

            case GAME_STATE_COMBAT:
                Print("Setting combat state.");
                setAudioCue(combatMusic);
                break;

            case GAME_STATE_DRAGON:
                Print("Setting dragon state.");
                setAudioCue(dragonMusic);
                break;

            case GAME_STATE_NORMAL:
            default:
                Print("Setting normal state.");
                setAudioCue(normalMusic);
                break;
        }

        gameState = newState;
    }
}

void AudioManager::stopAudio()
{
    al_stop_sample(currentSample);
}

void AudioManager::setAudioCue(ALLEGRO_SAMPLE* newCue)
{
    al_stop_sample(currentSample);
    al_play_sample(newCue, 0.7f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_LOOP, currentSample);
}

AudioManager::~AudioManager()
{
    al_stop_sample(currentSample);
    //dtor
}