#ifndef VECTOR3D_H_INCLUDED
#define VECTOR3D_H_INCLUDED

class Vector3D
{
public:
	float X;
	float Y;
	float Z;
public:
	Vector3D ();
	Vector3D (float x, float y, float z);
	void SetProperties (float x = 0.0f, float y = 0.0f, float z = 0.0f);
	void DisplayProperties ();
	~Vector3D ();
};

#endif // ! VECTOR3D_H_INCLUDED
