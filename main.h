//**-------------------------------------------------------**
//**
//**                     main.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**
#ifndef _MAIN_H_
#define _MAIN_H_

#include <Windows.h>
#include <DirectXMath.h>

constexpr UINT WINDOW_WIDTH = 480;
constexpr UINT WINDOW_HEIGHT = 360;

HWND				GetHWND();

template <typename T>
inline void SafeDelete(T*& p) {
	if (p != nullptr) {
		delete (p);
		(p) = nullptr;
	}
}

template <typename T>
inline void SafeDeleteArray(T*& p) {
	if (p != nullptr) {
		delete[](p);
		(p) = nullptr;
	}
}

template <typename T>
inline void SafeRelease(T*& p) {
	if (p != nullptr) {
		(p)->Release();
		(p) = nullptr;
	}
}

#endif // _MAIN_H_