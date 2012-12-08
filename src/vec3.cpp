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


#include "vec3.h"

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3::~vec3()
{
	//dtor
}

void vec3::operator+=(vec3 o) {
	x += o.x;
	y += o.y;
	z += o.z;
}

vec3 vec3::operator*(float f) {
	return vec3(x*f, y*f, z*f);
}

vec3 vec3::operator+(vec3 o) {
	return vec3(x+o.x, y+o.y, z+o.z);
}

vec3 vec3::operator-(vec3 o) {
	return vec3(x-o.x, y-o.y, z-o.z);
}

float length(vec3 v) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vec3 normalize(vec3 v) {
	float len = length(v);
	if (len == 0.0f) return vec3(0.0f, 0.0f, 0.0f);
	return vec3(v.x/len, v.y/len, v.z/len);
}
