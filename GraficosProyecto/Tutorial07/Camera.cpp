#include "Camera.h"


using namespace DirectX;


Camera::Camera()
{
	XMFLOAT3 Pos;
	XMVECTOR Eye = XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	float fovy;
	//matriz_vista = XMMatrixLookAtLH(Eye, At, Up);

	/*RECT rc;
	GetClientRect(g_hWnd, &rc); //Este método no puede estar afuera, porque tiene valor de retorno.
	UINT ancho = rc.right - rc.left;
	UINT alto = rc.bottom - rc.top;*/
}


Camera::~Camera()
{
}
