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


#include "vec2.h"

vec2::vec2() {
	x = 0;
	y = 0;
}

vec2::vec2(float _x, float _y) {
	x = _x;
	y = _y;
}

vec2::~vec2()
{
	//dtor
}

vec2 vec2::operator+(vec2 o) {
	return vec2(x+o.x, y+o.y);
}

void vec2::operator+=(vec2 o) {
	x += o.x;
	y += o.y;
}

vec2 vec2::operator-(vec2 o) {
	return vec2(x-o.x, y-o.y);
}

void vec2::operator-=(vec2 o) {
	x -= o.x;
	y -= o.y;
}

vec2 vec2::operator*(float o) {
	return vec2(x*o, y*o);
}

vec2 vec2::operator/(float o) {
	return vec2(x/o, y/o);
}

void vec2::operator*=(float o) {
	x*=o;
	y*=o;
}

bool vec2::operator==(vec2 o) {
    return x == o.x && y == o.y;
}

bool vec2::clampBetween(vec2 c1, vec2 c2) {
    if(x < c1.x) {x = c1.x; return true;}
    else if(x > c2.x) {x = c2.x; return true;}
    if(y < c1.y) {y = c1.y; return true;}
    else if(y > c2.y) {y = c2.y; return true;}
    return false;
}

float dot(vec2 v1, vec2 v2) {
	return v1.x*v2.x+v1.y*v2.y;
}

float lengthSquared(vec2 v) {
	return v.x*v.x + v.y*v.y;
}

float length(vec2 v) {
	return sqrt(v.x*v.x + v.y*v.y);
}

float distanceBetween(vec2 v1, vec2 v2) {
    float dx = v1.x-v2.x;
    float dy = v1.y-v2.y;

    return sqrt(dx*dx+dy*dy);
}

vec2 normalize(vec2 v) {
	float l = length(v);
	if (l == 0.0f) return vec2(0.0f, 0.0f);
	return vec2(v.x/l, v.y/l);
}

vec2 project(vec2 s, vec2 t) {
	//@TODO: Replace by matrix projection?
	return t*(dot(s, t)/lengthSquared(t));
}
