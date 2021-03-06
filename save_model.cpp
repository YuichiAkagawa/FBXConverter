//**-------------------------------------------------------**
//**
//**                   save_model.cpp
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**
#include <codecvt>
#include <fstream>
#include "directory_reader.h"
#include "load_fbx.h"
#include "main.h"
#include "save_model.h"

using namespace XMMath;

static const std::string FBX_MODEL_DIRECTORY = "FBXModel/";
static const std::string CONVERT_MODEL_DIRECTORY = "ConvertModel/";

bool SaveModel::Init(std::string modelFileName)
{
	LoadFBX loadFbx;

	MODEL model;
	if (!loadFbx.Load(FBX_MODEL_DIRECTORY + modelFileName + ".fbx", model))
	{
		return false;
	}

	std::ofstream fout;
	fout.open(CONVERT_MODEL_DIRECTORY + modelFileName + ".model", std::ios::out | std::ios::binary | std::ios::trunc);
	if (!fout)
	{
		return false;
	}

	size_t meshVectorSize = model.mesh.size();
	fout.write((const char*)&meshVectorSize, sizeof(size_t));
	for (unsigned int i = 0; i < meshVectorSize; i++)
	{
		size_t vertexVectorSize = model.mesh[i].vertex.size();
		fout.write((const char*)&vertexVectorSize, sizeof(size_t));

		for (unsigned int j = 0; j < vertexVectorSize; j++)
		{
			fout.write((const char*)&model.mesh[i].vertex[j].boneIndex, sizeof(Float4));
			fout.write((const char*)&model.mesh[i].vertex[j].color, sizeof(Float4));
			fout.write((const char*)&model.mesh[i].vertex[j].normal, sizeof(Float3));
			fout.write((const char*)&model.mesh[i].vertex[j].position, sizeof(Float3));
			fout.write((const char*)&model.mesh[i].vertex[j].tangent, sizeof(Float3));
			fout.write((const char*)&model.mesh[i].vertex[j].texcoord, sizeof(Float2));
			fout.write((const char*)&model.mesh[i].vertex[j].weight, sizeof(Float4));
		}

		size_t indexVectorSize = model.mesh[i].index.size();
		fout.write((const char*)&indexVectorSize, sizeof(size_t));
		for(unsigned int j = 0; j < indexVectorSize; j++)
		{
			fout.write((const char*)&model.mesh[i].index[j], sizeof(WORD));
		}
		fout.write((const char*)&model.mesh[i].frameTransMtx, sizeof(Matrix));

		size_t textureNameSize = model.mesh[i].material.textureName.size();
		fout.write((const char*)&textureNameSize, sizeof(size_t));	
		const char* textureName = model.mesh[i].material.textureName.c_str();
		fout.write(textureName, textureNameSize);
	}
	
	size_t boneVectorSize = model.bone.size();
	fout.write((const char*)&boneVectorSize, sizeof(size_t));
	for (unsigned int i = 0; i < boneVectorSize; i++)
	{
		size_t animMtxVectorSize = model.bone[i].animMtx.size();
		fout.write((const char*)&animMtxVectorSize, sizeof(size_t));
		for(unsigned int j = 0; j < animMtxVectorSize; j++)
		{
			fout.write((const char*)&model.bone[i].animMtx[j], sizeof(Matrix));
		}
		fout.write((const char*)&model.bone[i].initMtx, sizeof(Matrix));

		size_t boneNameSize = model.bone[i].name.size();
		fout.write((const char*)&boneNameSize, sizeof(size_t));
		const char* boneName = model.bone[i].name.c_str();
		fout.write(boneName, boneNameSize);
	}
	fout.write((const char*)&model.frameTransMtx, sizeof(Matrix));

	fout.close();

	return true;
}

bool SaveModelManager::Init()
{
	std::vector<std::string> modelNames = DirectoryReader::Read(FBX_MODEL_DIRECTORY);

	for (size_t i = 0; i < modelNames.size(); i++)
	{
		SaveModel model;

		if (!model.Init(modelNames[i]))
		{
			return false;
		}
	}
	return true;
}
