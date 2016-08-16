#pragma once

#include "PosableObject.h"

class Camera : public PosableObject
{
public:
	Camera();
	~Camera();
public:

	int ancho;
	int alto;
	double angulo_de_vision_y;
	//double near;
	//double far;

};

