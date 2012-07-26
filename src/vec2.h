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


#ifndef VEC2_H
#define VEC2_H

#include <cmath>

class vec2
{
	public:
		vec2();
		vec2(float _x, float _y);
		virtual ~vec2();

		float x, y;

		vec2 operator+(vec2 o);
		void operator+=(vec2 o);
		vec2 operator-(vec2 o);
		void operator-=(vec2 o);
		vec2 operator*(float o);
		vec2 operator/(float o);
		void operator*=(float o);
		bool operator==(vec2 o);

		//Clamps the vector between these corners, returns true if clamped.
		bool clampBetween(vec2 c1, vec2 c2);
};

//Other functions used by vec2.
float dot(vec2 v1, vec2 v2);
float lengthSquared(vec2 v);
float length(vec2 v);
float distanceBetween(vec2 v1, vec2 v2);
vec2 normalize(vec2 v);
vec2 project(vec2 s, vec2 t);

#endif // VEC2_H
