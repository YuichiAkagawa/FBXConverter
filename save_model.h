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

static const std::string g_pModelFile[] =
{
	{ "hornet_pilot" },
	{ "hornet_body" },
	{ "hornet_body_parts" },
	{ "hornet_body_parts2" },
	{ "hornet_aim120" },
	{ "hornet_aim9_right" },
	{ "hornet_aim9_left" },
	{ "hornet_flap_right" },
	{ "hornet_flap_left" },
	{ "hornet_elevator_right" },
	{ "hornet_elevator_left" },
	{ "hornet_aileron_right" },
	{ "hornet_aileron_left" },
	{ "hornet_radder_right" },
	{ "hornet_radder_left" },
	{ "hornet_canopy" },
	{ "hornet_glass_front" },
	{ "hornet_glass_back" },
	{ "skydome" },
	{ "test" },
};

class LoadFBX;

class SaveModel
{
public:
	bool Init(int modelName);
};

class SaveModelManager
{
public:
	bool Init();

private:
};
#endif // !_SAVE_MODEL_H_
