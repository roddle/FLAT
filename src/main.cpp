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


#include <allegro5/allegro.h>

#include "Game.h"
#include "utilities.h"

Game game;

int main(int argc, char **argv) {

	game = Game();

	game.initialize();
}

void TARGET_BACKBUFFER() {
	game.getGraphicsMan()->targetBackbuffer();
}
