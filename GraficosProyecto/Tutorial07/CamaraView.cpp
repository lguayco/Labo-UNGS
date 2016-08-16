#include "CamaraView.h"

#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>
#include "DDSTextureLoader.h"
#include "resource.h"

using namespace DirectX;

XMMATRIX view;

CamaraView::CamaraView()
{
	struct CBNeverChanges
	{
		XMMATRIX viewMatrix;
	};

	struct CBChangeOnResize
	{
		XMMATRIX ProjectionMatrix;
	};
}


CamaraView::~CamaraView()
{
}
