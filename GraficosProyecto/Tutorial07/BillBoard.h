#pragma once

#include <d3d11_1.h>
#include "PosableObject.h"

class BillBoard :public PosableObject
{
public:
	BillBoard();//pos, at, up, ancho, alto, path
	virtual ~BillBoard();
	
public:
	double ancho;
	double alto;
	char* path_imagen;
	ID3D11ShaderResourceView* textura;
};

