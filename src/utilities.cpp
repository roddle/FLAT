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


#include "utilities.h"

using namespace std;

void Print(string output) {
	cout<<output<<"\n";
}

void Print(string output, float n) {
	cout<<output<<" "<<n<<"\n";
}

void Print(string output, vec2 v) {
	cout<<output<<" ("<<v.x<<", "<<v.y<<")"<<"\n";
}

void Alert(const char* msg) {
	/*al_show_native_message_box(
     NULL,
     "Warning",
     msg,
     NULL,
     NULL,
     ALLEGRO_MESSAGEBOX_WARN
  );*/
}

void Error(const char* msg) {
	/*al_show_native_message_box(
     NULL,
     "Error",
     msg,
     NULL,
     NULL,
     ALLEGRO_MESSAGEBOX_ERROR
  );*/
}

float random(float scale) {
	return (((float)(rand()%20000-10000))/10000.0f)*scale;
}

bool chance(float chance) {
	return rand()%30000<chance*30000.0f;
}

float mod(float a, float b) {
	int n = (int)(a/b);
	return a-b*n;
}
