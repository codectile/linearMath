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

#include "linear.h"

//vectors
cell AMX_NATIVE_CALL AddVectors(AMX* amx, cell* params)
{
	btVector3 vector1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 vector2(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	btVector3 resultant;
	resultant = vector1 + vector2;
	cell* mem_add[3];
	amx_GetAddr(amx, params[7], &mem_add[0]);
	amx_GetAddr(amx, params[8], &mem_add[1]);
	amx_GetAddr(amx, params[9], &mem_add[2]);
	*mem_add[0] = amx_ftoc(resultant.getX());
	*mem_add[1] = amx_ftoc(resultant.getY());
	*mem_add[2] = amx_ftoc(resultant.getZ());
	return 1;
}

cell AMX_NATIVE_CALL DotProduct(AMX* amx, cell* params)
{
	btVector3 vector1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 vector2(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	btScalar resultant;
	resultant = vector1.dot(vector2);
	return amx_ftoc(resultant);
}

cell AMX_NATIVE_CALL CrossProduct(AMX* amx, cell* params)
{
	btVector3 vector1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 vector2(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	btVector3 resultant;
	resultant = vector1.cross(vector2);
	cell* mem_add[3];
	amx_GetAddr(amx, params[7], &mem_add[0]);
	amx_GetAddr(amx, params[8], &mem_add[1]);
	amx_GetAddr(amx, params[9], &mem_add[2]);
	*mem_add[0] = amx_ftoc(resultant.getX());
	*mem_add[1] = amx_ftoc(resultant.getY());
	*mem_add[2] = amx_ftoc(resultant.getZ());
	return 1;
}

cell AMX_NATIVE_CALL GetVectorAngle(AMX* amx, cell* params)
{
	btVector3 vector1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 vector2(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	float angle;
	angle = vector1.angle(vector2);
	return amx_ftoc(angle);
}

cell AMX_NATIVE_CALL GetDistance(AMX* amx, cell* params)
{
	btVector3 vector1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 vector2(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	float distance;
	if(params[7] == 1)
		distance = vector1.distance(vector2);
	else
		distance = vector1.distance2(vector2);
	return amx_ftoc(distance);
}

cell AMX_NATIVE_CALL GetMagnitude(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	float magnitude;
	if(params[4] == 1)
		magnitude = vector.length();
	else
		magnitude = vector.length2();
	return amx_ftoc(magnitude);
}

cell AMX_NATIVE_CALL GetNormalized(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 normalized = vector.normalize();
	cell* mem_add[3];
	amx_GetAddr(amx, params[4], &mem_add[0]);
	amx_GetAddr(amx, params[5], &mem_add[1]);
	amx_GetAddr(amx, params[6], &mem_add[2]);
	*mem_add[0] = amx_ftoc(normalized.getX());
	*mem_add[1] = amx_ftoc(normalized.getY());
	*mem_add[2] = amx_ftoc(normalized.getZ());
	return 1;
}

cell AMX_NATIVE_CALL GetClosestAxis(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	int axis = vector.closestAxis();
	return axis;
}

cell AMX_NATIVE_CALL GetFurthestAxis(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	int axis = vector.furthestAxis();
	return axis;
}

cell AMX_NATIVE_CALL RotateVector(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 axis(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	btVector3 resultant = vector.rotate(axis, amx_ctof(params[7]));
	cell* mem_add[3];
	amx_GetAddr(amx, params[8], &mem_add[0]);
	amx_GetAddr(amx, params[9], &mem_add[1]);
	amx_GetAddr(amx, params[10], &mem_add[2]);
	*mem_add[0] = amx_ftoc(resultant.getX());
	*mem_add[1] = amx_ftoc(resultant.getY());
	*mem_add[2] = amx_ftoc(resultant.getZ());
	return 1;
}

cell AMX_NATIVE_CALL GetReflectedVector(AMX* amx, cell* params)
{
	btVector3 vector(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]));
	btVector3 normal(amx_ctof(params[4]), amx_ctof(params[5]), amx_ctof(params[6]));
	btVector3 resultant = vector - (2 * (vector.dot(normal)) * (normal.normalize()));;
	cell* mem_add[3];
	amx_GetAddr(amx, params[7], &mem_add[0]);
	amx_GetAddr(amx, params[8], &mem_add[1]);
	amx_GetAddr(amx, params[9], &mem_add[2]);
	*mem_add[0] = amx_ftoc(resultant.getX());
	*mem_add[1] = amx_ftoc(resultant.getY());
	*mem_add[2] = amx_ftoc(resultant.getZ());
	return 1;
}

//quaternions
cell AMX_NATIVE_CALL GetQuaternionAngle(AMX* amx, cell* params)
{
	btQuaternion quat1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
	btQuaternion quat2(amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]));
	float angle = quat1.angle(quat2);
	return amx_ftoc(angle);
}

cell AMX_NATIVE_CALL GetAxisOfRotation(AMX* amx, cell* params)
{
	btQuaternion quat(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
	btVector3 angle = quat.getAxis();
	cell* mem_add[3];
	amx_GetAddr(amx, params[7], &mem_add[0]);
	amx_GetAddr(amx, params[8], &mem_add[1]);
	amx_GetAddr(amx, params[9], &mem_add[2]);
	*mem_add[0] = amx_ftoc(angle.getX());
	*mem_add[1] = amx_ftoc(angle.getY());
	*mem_add[2] = amx_ftoc(angle.getZ());
	return 1;
}

cell AMX_NATIVE_CALL DotProductQuaternion(AMX* amx, cell* params)
{
	btQuaternion quat1(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
	btQuaternion quat2(amx_ctof(params[5]), amx_ctof(params[6]), amx_ctof(params[7]), amx_ctof(params[8]));
	btScalar product = quat1.dot(quat2);
	return amx_ftoc(product);
}

cell AMX_NATIVE_CALL GetQuaternionMagnitude(AMX* amx, cell* params)
{
	btQuaternion quat(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
	btScalar magnitude;
	if(params[5] == 1)
		magnitude = quat.length();
	else
		magnitude = quat.length2();
	return amx_ftoc(magnitude);
}

cell AMX_NATIVE_CALL GetInverseQuaternion(AMX* amx, cell* params)
{
	btQuaternion quat(amx_ctof(params[1]), amx_ctof(params[2]), amx_ctof(params[3]), amx_ctof(params[4]));
	btQuaternion inverse = quat.inverse();
	cell* mem_add[4];
	amx_GetAddr(amx, params[5], &mem_add[0]);
	amx_GetAddr(amx, params[6], &mem_add[1]);
	amx_GetAddr(amx, params[7], &mem_add[2]);
	amx_GetAddr(amx, params[8], &mem_add[2]);
	*mem_add[0] = amx_ftoc(inverse.getX());
	*mem_add[1] = amx_ftoc(inverse.getY());
	*mem_add[2] = amx_ftoc(inverse.getZ());
	*mem_add[3] = amx_ftoc(inverse.getW());
	return 1;
}

AMX_NATIVE_INFO linearNatives[] =
{
	{"AddVectors", AddVectors},
	{"DotProduct", DotProduct},
	{"CrossProduct", CrossProduct},
	{"GetVectorAngle", GetVectorAngle},
	{"GetDistance", GetDistance},
	{"GetMagnitude", GetMagnitude},
	{"GetNormalized", GetNormalized},
	{"GetClosestAxis", GetClosestAxis},
	{"GetFurthestAxis", GetFurthestAxis},
	{"RotateVector", RotateVector},
	{"GetReflectedVector", GetReflectedVector},
	//quaternions
	{"GetQuaternionAngle", GetQuaternionAngle},
	{"GetAxisOfRotation", GetAxisOfRotation},
	{"DotProductQuaternion", DotProductQuaternion},
	{"GetQuaternionMagnitude", GetQuaternionMagnitude},
	{"GetInverseQuaternion", GetInverseQuaternion},
	{0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx ) 
{
	return amx_Register(amx, linearNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx ) 
{
	return AMX_ERR_NONE;
}
