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
#include "xm_math.h"

struct VERTEX
{
	XMMath::Float3 position;
	XMMath::Float3 normal;
	XMMath::Float4 color;
	XMMath::Float2 texcoord;
	XMMath::Float3 tangent;
	XMMath::Float4 boneIndex;
	XMMath::Float4 weight;
};

struct MATERIAL
{
	XMMath::Float4				ambient;
	XMMath::Float4				diffuse;
	XMMath::Float4				specular;
	XMMath::Float4				emission;
	float							power;
	ID3D11ShaderResourceView*		texture;
	std::string						textureName;
};

struct BONE
{
	std::string		name;
	XMMath::Matrix	initMtx;
	std::vector<std::vector<XMMath::Matrix>> animMtx;
};

struct MESH
{
	XMMath::Matrix			frameTransMtx;
	std::vector<VERTEX>			vertex;
	std::vector<WORD>			index;
	ID3D11Buffer*				vertexBuffer;
	ID3D11Buffer*				indexBuffer;
	MATERIAL					material;
};

struct MODEL
{
	XMMath::Matrix		frameTransMtx;
	std::vector<MESH>	mesh;
	std::vector<BONE>	bone;
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
