//**-------------------------------------------------------**
//**
//**                directory_reader.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**

#ifndef _DIRECTORY_READER_H_
#define _DIRECTORY_READER_H_

#include <vector>
#include <string>

class DirectoryReader
{
public:
	static std::vector<std::string> Read(std::string folder);
	
private:
	static std::string ExtractPathWithoutExt(const std::string &fn);
};

#endif // !_DIRECTORY_READER_H_
