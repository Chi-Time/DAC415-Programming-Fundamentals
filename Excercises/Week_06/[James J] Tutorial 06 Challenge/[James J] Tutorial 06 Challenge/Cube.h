#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

class Cube
{
public: 
	Vector3D Vertices[8];
	float Size;

public:
	Cube ();
	Cube (float size);
	void MoveCube (Vector3D direction);
	Vector3D GetCentre ();
	Vector3D GetPosition ();
	void DisplayCentre ();
	void DisplayCube ();
	void DisplayPosition ();
	~Cube ();

private:
	Vector3D Centre;
	Vector3D Position;

private:
	void SetPoints ();
};

#endif // !CUBE_H_INCLUDED
