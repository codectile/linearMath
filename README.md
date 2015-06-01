![linear](https://img.shields.io/badge/linearMath-v1.0-brightgreen.svg) [![chatroom](https://camo.githubusercontent.com/da2edb525cde1455a622c58c0effc3a90b9a181c/68747470733a2f2f6261646765732e6769747465722e696d2f4a6f696e253230436861742e737667)](https://gitter.im/codectile/linearMath)

# linearMath
Linear mathematics plugin for sa-mp. This plugin is based upon Bullet's LinearMath library, to provide fast and efficient vector as well as quaternion math calculations. It completely utilizes, **S**ingle **I**nstruction, **M**ultiple **D**ata (**SIMD**) method of parallel computing which makes it fast as well as efficient.

##Functions

```pawn

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
```

##Description

#####AddVectors - Addition of two vectors
```
x1 - x component of a vector1
y1 - y component of a vector1
z1 - z component of a vector1

x2 - x component of a vector2
y2 - y component of a vector2
z2 - z component of a vector2

x - passed-by-reference, the component x after addition
y - passed-by-reference, the component y after addition
z - passed-by-reference, the component z after addition
```


#####DotProduct - Dot product of two vectors.
```
x1 - x component of a vector1
y1 - y component of a vector1
z1 - z component of a vector1

x2 - x component of a vector2
y2 - y component of a vector2
z2 - z component of a vector2
```


#####CrossProduct - Cross product of two vectors
```
x1 - x component of a vector1
y1 - y component of a vector1
z1 - z component of a vector1

x2 - x component of a vector2
y2 - y component of a vector2
z2 - z component of a vector2

x - passed-by-reference, the component x of the resultant vector after the vector product.
y - passed-by-reference, the component y of the resultant vector after the vector product.
z - passed-by-reference, the component z of the resultant vector after the vector product.
```


#####GetVectorAngle - Returns the angle of the vector
```
x1 - x component of a vector1
y1 - y component of a vector1
z1 - z component of a vector1

x2 - x component of a vector2
y2 - y component of a vector2
z2 - z component of a vector2

angle - passed-by-reference, angle between two vectors
```


#####GetDistance - Returns the distance between two vectors
```
x1 - x component of a vector1
y1 - y component of a vector1
z1 - z component of a vector1

x2 - x component of a vector2
y2 - y component of a vector2
z2 - z component of a vector2

distance - passed-by-reference, distance between two vectors
```


#####GetMagnitude - Returns the magnitude/size/length of two vectors
```
x - x component of a vector
y - y component of a vector
z - z component of a vector
```


#####GetNormalized - Normalizes the vector
```
x - x component of a vector
y - y component of a vector
z - z component of a vector

nx - passed-by-reference, the normalized component x
ny - passed-by-reference, the normalized component y
nz - passed-by-reference, the normalized component z
```


#####GetClosestAxis - Returns the closest axis of a vector
```
x - x component of a vector
y - y component of a vector
z - z component of a vector
```

#####GetFurthestAxis - Returns the Furthest axis of a vector
```
x - x component of a vector
y - y component of a vector
z - z component of a vector
```


#####RotateVector` - Rotates the vector according to the specified angle and axis
```
x - x component of a vector
y - y component of a vector
z - z component of a vector

ax - x component of a vector
ay - y component of a vector
az - z component of a vector

angle - angle to rotate by which

rx - passed-by-reference, the component x of the rotated vector
ry - passed-by-reference, the component y of the rotated vector
rz - passed-by-reference, the component z of the rotated vector
```


#####GetReflectedVector - Returns the reflected vector
```
x - x component of a vector
y - y component of a vector
z - z component of a vector

nx - x component(normalized) of a vector
ny - y component(normalized) of a vector
nz - z component(normalized) of a vector

rx - passed-by-reference, the component x of the reflected vector
ry - passed-by-reference, the component y of the reflected vector
rz - passed-by-reference, the component z of the reflected vector
```


#####GetQuaternionAngle - Returns the angle between two quaternions
```
x1 - x component of a quaternion1
y1 - y component of a quaternion1
z1 - z component of a quaternion1
w1 - w component of a quaternion1

x2 - x component of a quaternion2
y2 - y component of a quaternion2
z2 - z component of a quaternion2
w2 - w component of a quaternion2
```

#####GetAxisOfRotation - Returns the axis of rotation of a quaternion
```
x - x component of a quaternion
y - y component of a quaternion
z - z component of a quaternion
w - w component of a quaternion

x1 - passed-by-reference, the axis x of rotation
y1 - passed-by-reference, the axis y of rotation
z1 - passed-by-reference, the axis z of rotation
```


#####DotProductQuaternion - Dot product of two quaternions
```
x1 - x component of a quaternion1
y1 - y component of a quaternion1
z1 - z component of a quaternion1
w1 - w component of a quaternion1

x2 - x component of a quaternion2
y2 - y component of a quaternion2
z2 - z component of a quaternion2
w2 - w component of a quaternion2
```


#####GetQuaternionMagnitude - Magnitude of a quaternion
```
x - x component of a quaternion
y - y component of a quaternion
z - z component of a quaternion
w - w component of a quaternion
```

#####GetInverseQuaternion - Inverse of a quaternion
```
x - x component of a quaternion
y - y component of a quaternion
z - z component of a quaternion
w - w component of a quaternion

ix - inversed x component of a quaternion
iy - inversed y component of a quaternion
iz - inversed z component of a quaternion
iw - inversed w component of a quaternion
```
