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


#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3
{
	public:
		vec3();
		vec3(float _x, float _y, float _z);
		virtual ~vec3();

		float x, y, z;

		void operator+=(vec3 o);
		vec3 operator+(vec3 o);
		vec3 operator-(vec3 o);
		vec3 operator*(float f);
};

float length(vec3 v);
vec3 normalize(vec3 v);
#endif // VEC3_H
