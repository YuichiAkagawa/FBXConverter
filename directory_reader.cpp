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
	// ファイル一覧取得
	// folder : フォルダの絶対パスを入力とする 
	// 例 : "D:\\Users\\Pictures\\"

	//相対パスを絶対パスに変換
	char absolutelyFolder[1024];
	GetFullPathName(folder.c_str(), sizeof(absolutelyFolder) / sizeof(absolutelyFolder[0]), absolutelyFolder, nullptr);
	std::string absolutelyFolderName = absolutelyFolder;

	// 宣言
	std::vector<std::string> fileList;
	HANDLE hFind;
	WIN32_FIND_DATA fd;

	// ファイル名検索のためにワイルドカード追加
	// 例 : "D:\\Users\\Pictures\\*.*"
	std::stringstream ss;
	ss << absolutelyFolderName;
	std::string::iterator itr = absolutelyFolderName.end();
	itr--;
	if (*itr != '\\') ss << '\\';
	ss << "*.*";

	// ファイル探索
	// FindFirstFile(ファイル名, &fd);
	hFind = FindFirstFile(ss.str().c_str(), &fd);

	// 検索失敗
	if (hFind == INVALID_HANDLE_VALUE) {
		std::cout << "ファイル一覧を取得できませんでした" << std::endl;
		exit(1); // エラー終了
	}

	// ファイル名をリストに格納するためのループ
	do {
		// フォルダは除く
		if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			&& !(fd.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN))
		{
			//ファイル名をリストに格納
			char *file = fd.cFileName;
			std::string str = file;

			//拡張子を削除
			str = ExtractPathWithoutExt(str);

			fileList.push_back(str);
		}
	} while (FindNextFile(hFind, &fd)); //次のファイルを探索

										// hFindのクローズ
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