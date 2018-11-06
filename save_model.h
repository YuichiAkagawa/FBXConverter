//**-------------------------------------------------------**
//**
//**                   save_model.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**

#ifndef _SAVE_MODEL_H_
#define _SAVE_MODEL_H_

#include <d3d11.h>
#include <string>
#include <vector>
#include <DirectXMath.h>

struct VERTEX
{
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 normal;
	DirectX::XMFLOAT4 color;
	DirectX::XMFLOAT2 texcoord;
	DirectX::XMFLOAT3 tangent;
	DirectX::XMFLOAT4 boneIndex;
	DirectX::XMFLOAT4 weight;
};

struct MATERIAL
{
	DirectX::XMFLOAT4				ambient;
	DirectX::XMFLOAT4				diffuse;
	DirectX::XMFLOAT4				specular;
	DirectX::XMFLOAT4				emission;
	float							power;
	ID3D11ShaderResourceView*		texture;
	std::string						textureName;
};

struct BONE
{
	std::string		name;
	DirectX::XMFLOAT4X4	initMtx;
	std::vector<std::vector<DirectX::XMFLOAT4X4>> animMtx;
};

struct MESH
{
	DirectX::XMFLOAT4X4			frameTransMtx;
	std::vector<VERTEX>			vertex;
	std::vector<WORD>			index;
	ID3D11Buffer*				vertexBuffer;
	ID3D11Buffer*				indexBuffer;
	MATERIAL					material;
};

struct MODEL
{
	DirectX::XMFLOAT4X4		frameTransMtx;
	std::vector<MESH>	mesh;
	std::vector<BONE>	bone;
};

constexpr unsigned int NUM = 1;
static const std::string g_pModelFile[] =
{
	{"t-90a"},
};

class LoadFBX;

class SaveModel
{
public:
	bool Init(std::string modelFileName);
};

class SaveModelManager
{
public:
	bool Init();

private:
};
#endif // !_SAVE_MODEL_H_
