#pragma once

#include <d3d11_1.h>
#include <d3dcompiler.h>

#include <directxcolors.h>

#include "Window.h"
#include "Scene.h"

class Device
{
public:
	Device(Window* mi_window);
	virtual ~Device(void);

	void Render(Scene* scene);

public: //pasar privado
	
D3D_DRIVER_TYPE                     g_driverType;
D3D_FEATURE_LEVEL                   g_featureLevel;

ID3D11Device*                       g_pd3dDevice;
ID3D11DeviceContext*                g_pImmediateContext;
IDXGISwapChain*                     g_pSwapChain;
ID3D11RenderTargetView*             g_pRenderTargetView;
ID3D11Texture2D*                    g_pDepthStencil;
ID3D11DepthStencilView*             g_pDepthStencilView;

ID3D11ShaderResourceView* LoadTexture( WCHAR* szFileName);

};

