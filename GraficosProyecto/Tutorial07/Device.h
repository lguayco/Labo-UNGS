#pragma once

#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>

#include "Window.h"
#include "Scene.h"


//--------------------------------------------------------------------------------------
// Structures
//--------------------------------------------------------------------------------------
struct SimpleVertex
{
    DirectX::XMFLOAT3 Pos;
    DirectX::XMFLOAT2 Tex;
};

struct CBNeverChanges
{
    DirectX::XMMATRIX mView;
};

struct CBChangeOnResize
{
    DirectX::XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
    DirectX::XMMATRIX mWorld;
    DirectX::XMFLOAT4 vMeshColor;
};


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
ID3D11VertexShader*                 g_pVertexShader;
ID3D11PixelShader*                  g_pPixelShader;
ID3D11InputLayout*                  g_pVertexLayout;
ID3D11Buffer*                       g_pVertexBuffer;
ID3D11Buffer*                       g_pIndexBuffer;
ID3D11Buffer*                       g_pCBNeverChanges;
ID3D11Buffer*                       g_pCBChangeOnResize;
ID3D11Buffer*                       g_pCBChangesEveryFrame;
ID3D11SamplerState*                 g_pSamplerLinear;
DirectX::XMMATRIX                            g_World;
DirectX::XMMATRIX                            g_View;
DirectX::XMMATRIX                            g_Projection;


HRESULT CompileShaderFromFile( WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut );
ID3D11ShaderResourceView* LoadTexture( WCHAR* szFileName);

};

