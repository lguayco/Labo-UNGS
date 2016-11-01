#pragma once

#include <d3d11_1.h>
#include <directxmath.h>
//#include "Device.h"
class Device;
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

class Mesh
{
public:
	Mesh(Device* device);
	~Mesh();

	void renderObject(DirectX::XMMATRIX mundo, DirectX::XMMATRIX vista, DirectX::XMMATRIX projection, ID3D11ShaderResourceView* textura, Device* device);

public:
	ID3D11Buffer* g_pIndexBuffer;
	ID3D11VertexShader* g_pVertexShader;
	ID3D11InputLayout*  g_pVertexLayout;
	ID3D11Buffer* g_pVertexBuffer;
	ID3D11PixelShader* g_pPixelShader;
	ID3D11Buffer* g_pCBNeverChanges;
	ID3D11Buffer* g_pCBChangeOnResize;
	ID3D11Buffer* g_pCBChangesEveryFrame;
	ID3D11SamplerState* g_pSamplerLinear;	

	HRESULT InitMesh(Device* device);
	HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
};

