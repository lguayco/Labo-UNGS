#include "BillboardView.h"

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "DDSTextureLoader.h"
#include "resource.h"

using namespace DirectX;
XMMATRIX worldMatrix;
XMMATRIX scaleMatrix = XMMatrixScaling(0.2f, 0.2f, 0.2f);

// Initialize the world matrices
BillboardView::BillboardView()
{
	worldMatrix = XMMatrixIdentity(); //worldMatrix no existe ni en tutorial 7
}


BillboardView::~BillboardView()
{
}
