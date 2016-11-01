#pragma once

#include <d3d11_1.h>
#include "PosableObject.h"
#include "Mesh.h"

class BillBoard :public PosableObject
{
public:
	BillBoard();
	virtual ~BillBoard();

	void setMesh(Mesh* mesh);
	
public:
	double ancho;
	double alto;
	char* path_imagen;
	ID3D11ShaderResourceView* textura;
	Mesh* mesh;
};

