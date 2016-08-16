#pragma once

#include "BillBoard.h"
#include "Camera.h"

class Scene
{
public:
	Scene();
	~Scene();

BillBoard* el_billboard;
Camera* la_camara;
};

