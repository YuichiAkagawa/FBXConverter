//**-------------------------------------------------------**
//**
//**                     load.fbx.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**

#ifndef _LOAD_FBX_H_
#define _LOAD_FBX_H_

#include <fbxsdk.h>
#include <unordered_map>
#include <string>
#include "xm_math.h"
#include "save_model.h"

struct FBXANIMATION
{
	std::string name;
	std::vector<BONE> bone;
	int frameNum;
	int startFrame;
	int endFrame;
	FbxTime framePeriod;
};

struct VERTEXFBX
{
	XMMath::Float3  position;
	XMMath::Float3  normal;
	XMMath::Float4  color;
	XMMath::Float2  texcoord;
	XMMath::Float3  positionDefault;
};

struct VERTEXBONE
{
	float boneIndex;
	float weight;
};

struct VERTEXPOINTBONE
{
	XMMath::Float3 position;
	VERTEXBONE boneData[4];
};

struct UVSet
{
	std::string uvSetName;
	std::string texName;
};

struct FBXUV
{
	std::string uvSetName;
	std::vector<XMMath::Float2> texcoord;
};

struct MESH_
{
	int   pointCount;
	int   polygonCount;
	int   indexCount;
	UVSet uvSet;
	unsigned int  vertexShader;
	std::vector<VERTEXFBX> vertex;
	std::vector<BONE>      bone;
};

class Systems;
class LoadFBX
{
	friend class Systems;
public:
	LoadFBX(void) {}
	~LoadFBX(void);

	bool Load(std::string fileName, MODEL& model);
	bool LoadAnimation(std::string fileName, MODEL& model);

private:

	void InitializeSdkObjects(FbxManager*& pManager, FbxScene*& pScene);
	bool LoadScene(FbxManager* pManager, FbxDocument* pScene, const char* pFilename, bool animation);

	// ���b�V���𐔂���
	void	CountMesh(FbxNode* pNode, MODEL& model);
	// ���b�V���̏����擾����
	bool GetMesh(FbxNode* pNode, MODEL& model);

	void	GetPosition(FbxMesh* mesh, XMMath::Matrix& mtx);// ���_���W
	void	GetMeshMaterialList(FbxMesh* mesh);			// ���b�V���}�e���A�����X�g�̎擾
	void	GetBone(FbxMesh* mesh);						// �{�[��
	void	GetVertexNormal(FbxMesh* mesh, XMMath::Matrix& mtx);				// �@��
	void	GetVertexTangent(FbxMesh* mesh, XMMath::Matrix& mtx);			// tangent
	void	GetVertexUV(FbxMesh* mesh);					// �e�N�X�`�����W
	void	GetTextureNames(FbxMesh* mesh);				// �e�N�X�`��
	void	GetVertexColor(FbxMesh* mesh);				// �F

	bool CreateModelData(MODEL& model);
	bool CreateVeretx(MODEL& model, int indexNum, const int* index, UVSet uv);

	void CreateMtx(XMMath::Matrix& mtx, const FbxMatrix fbxMtx);
	void ReleaseTempObj(void);			// �ꎞ���̉��
	void ReleaseTempAnimObj(void);			// �ꎞ���̉��

	void GetAnimation(FBXANIMATION& animInfo);

	// �}�e���A���̐�(0 = CountMesh, 1 = GetMesh)
	int materialCount_[2] = { 0, 0 };

	// FBX
	FbxManager* lSdkManager_ = NULL;
	FbxScene*   lScene_ = NULL;

	// �ꎞ�ϐ�
	std::string	fileName_;
	int		pointCount_;
	int		polygonCount_;
	unsigned int		indexCount_;
	std::vector<VERTEXPOINTBONE>			tempPoint_;
	std::vector<VERTEXPOINTBONE>			tempVertex_;
	std::vector<XMMath::Float3>			tempNormal_;
	std::vector<XMMath::Float3>			tempTangent_;
	std::vector<XMMath::Float4>			tempColor_;
	std::vector<FBXUV>						tempTexcoord_;
	std::vector<UVSet>						tempUVSet_;
	std::vector<FBXANIMATION>				tempAnim_;
	std::vector<int>						meshMaterialList_;

	std::vector<BONE>						boneList_;

	std::vector<FBXANIMATION>				animationStack_;
	std::vector<FbxNode*>					tempNode_;
	std::vector<BONE>						animBoneList_;

	XMMath::Matrix mtx_;		//�ϊ��S��
	XMMath::Matrix mtxViewZ_;	//Z�o�b�t�@�p
	XMMath::Matrix mtxProjZ_;
};

#endif //_LOAD_FBX_H_
