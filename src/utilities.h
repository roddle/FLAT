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


//utilities.h

#include <iostream>
#include <string>
#include <allegro5/allegro_native_dialog.h>

#include "vec2.h"

#ifndef __UTILITIES_H_LOCK__
#define __UTILITIES_H_LOCK__

using namespace std;

void Print(string output);
void Print(string output, float n);
void Print(string output, vec2 v);
void Alert(const char* msg);
void Error(const char* msg);
float random(float scale);
bool chance(float chance);
float mod(float a, float b);

#endif // __UTILITIES_H_LOCK__
