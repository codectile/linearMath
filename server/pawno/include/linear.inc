/*
    Copyright (C) 2015  codectile
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

/*
	Plugin: linear
	Author: codectile
*/

//vectors
native	AddVectors(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, &Float:x, &Float:y, &Float:z);
native	Float:DotProduct(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native	CrossProduct(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, &Float:x, &Float:y, &Float:z);
native	Float:GetVectorAngle(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native	Float:GetDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2);
native	Float:GetMagnitude(Float:x, Float:y, Float:z);
native	GetNormalized(Float:x, Float:y, Float:z , &Float:nx, &Float:ny, &Float:nz);
native	GetClosestAxis(Float:x, Float:y, Float:z);
native	GetFurthestAxis(Float:x, Float:y, Float:z);
native	RotateVector(Float:x, Float:y, Float:z, Float:ax, Float:ay, Float:az, Float:angle, &Float:rx, &Float:ry, &Float:rz);
native	GetReflectedVector(Float:x, Float:y, Float:z, Float:nx, Float:ny, Float:nz, &Float:rx, &Float:ry, &Float:rz);

//quaternions
native	Float:GetQuaternionAngle(Float:x1, Float:y1, Float:z1, Float:w1, Float:x2, Float:y2, Float:z2, Float:w2);
native	GetAxisOfRotation(Float:x, Float:y, Float:z, Float:w, &Float:x1, &Float:y1, &Float:z1);
native	Float:DotProductQuaternion(Float:x1, Float:y1, Float:z1, Float:w1, Float:x2, Float:y2, Float:z2, Float:w2);
native	Float:GetQuaternionMagnitude(Float:x, Float:y, Float:z, Float:w);
native	Float:GetInverseQuaternion(Float:x, Float:y, Float:z, Float:w, &Float:ix, &Float:iy, &Float:iz, &Float:iw);
