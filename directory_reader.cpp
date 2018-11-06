//**-------------------------------------------------------**
//**
//**                directory_reader.cpp
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "directory_reader.h"

std::vector<std::string> DirectoryReader::Read(std::string folder)
{
	// �t�@�C���ꗗ�擾
	// folder : �t�H���_�̐�΃p�X����͂Ƃ��� 
	// �� : "D:\\Users\\Pictures\\"

	//���΃p�X���΃p�X�ɕϊ�
	char absolutelyFolder[1024];
	GetFullPathName(folder.c_str(), sizeof(absolutelyFolder) / sizeof(absolutelyFolder[0]), absolutelyFolder, nullptr);
	std::string absolutelyFolderName = absolutelyFolder;

	// �錾
	std::vector<std::string> fileList;
	HANDLE hFind;
	WIN32_FIND_DATA fd;

	// �t�@�C���������̂��߂Ƀ��C���h�J�[�h�ǉ�
	// �� : "D:\\Users\\Pictures\\*.*"
	std::stringstream ss;
	ss << absolutelyFolderName;
	std::string::iterator itr = absolutelyFolderName.end();
	itr--;
	if (*itr != '\\') ss << '\\';
	ss << "*.*";

	// �t�@�C���T��
	// FindFirstFile(�t�@�C����, &fd);
	hFind = FindFirstFile(ss.str().c_str(), &fd);

	// �������s
	if (hFind == INVALID_HANDLE_VALUE) {
		std::cout << "�t�@�C���ꗗ���擾�ł��܂���ł���" << std::endl;
		exit(1); // �G���[�I��
	}

	// �t�@�C���������X�g�Ɋi�[���邽�߂̃��[�v
	do {
		// �t�H���_�͏���
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			&& !(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
		{
			//�t�@�C���������X�g�Ɋi�[
			char *file = fd.cFileName;
			std::string str = file;

			//�g���q���폜
			str = ExtractPathWithoutExt(str);

			fileList.push_back(str);
		}
	} while (FindNextFile(hFind, &fd)); //���̃t�@�C����T��

										// hFind�̃N���[�Y
	FindClose(hFind);

	return fileList;
}

std::string DirectoryReader::ExtractPathWithoutExt(const std::string &fn)
{
	std::string::size_type pos;
	if ((pos = fn.find_last_of(".")) == std::string::npos) {
		return fn;
	}

	return fn.substr(0, pos);
}