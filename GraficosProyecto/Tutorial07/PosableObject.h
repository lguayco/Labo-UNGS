#pragma once

#include <directxmath.h>

class PosableObject
{
public:
	PosableObject(void);// recibir pos, at, up
	virtual ~PosableObject(void);
	void posicionar(double x, double y, double z);
	void trasladar(double dx, double dy, double dz);

public: // pasar a privado
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 at_point;
	DirectX::XMFLOAT3 up_dir;
};

