#include "BillBoard.h"


/*
pos:vec3
at:vec3
up:vec3
ancho
alto
mover
trasladar
*/
char path_imagen[1000];


BillBoard::BillBoard()
{	
}


BillBoard::~BillBoard()
{
}

void BillBoard::setMesh(Mesh* m)
{
	this->mesh = m;
}
