//**-------------------------------------------------------**
//**
//**                    xm_math.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**
#ifndef _XM_MATH_H_
#define _XM_MATH_H_

#include <DirectXMath.h>

class XMMath
{
public:
	static void Addition(DirectX::XMFLOAT2& valueReturn, const DirectX::XMFLOAT2& valueLeft, const DirectX::XMFLOAT2& valueRight);
	static void Addition(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);
	static void Addition(DirectX::XMFLOAT4& valueReturn, const DirectX::XMFLOAT4& valueLeft, const DirectX::XMFLOAT4& valueRight);
	
	static void Subtraction(DirectX::XMFLOAT2& valueReturn, const DirectX::XMFLOAT2& valueLeft, const DirectX::XMFLOAT2& valueRight);
	static void Subtraction(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);
	static void Subtraction(DirectX::XMFLOAT4& valueReturn, const DirectX::XMFLOAT4& valueLeft, const DirectX::XMFLOAT4& valueRight);

	static void Multiplication(DirectX::XMFLOAT2& valueReturn, const DirectX::XMFLOAT2& valueLeft, float valueRight);
	static void Multiplication(DirectX::XMFLOAT2& valueReturn, const DirectX::XMFLOAT2& valueLeft, const DirectX::XMFLOAT2& valueRight);
	static void Multiplication(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, float valueRight);
	static void Multiplication(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);	
	static void Multiplication(DirectX::XMFLOAT4& valueReturn, const DirectX::XMFLOAT4& valueLeft, float valueRight);
	static void Multiplication(DirectX::XMFLOAT4& valueReturn, const DirectX::XMFLOAT4& valueLeft, const DirectX::XMFLOAT4& valueRight);

	static void Division(DirectX::XMFLOAT2& valueReturn, const DirectX::XMFLOAT2& valueLeft, const DirectX::XMFLOAT2& valueRight);
	static void Division(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);
	static void Division(DirectX::XMFLOAT4& valueReturn, const DirectX::XMFLOAT4& valueLeft, const DirectX::XMFLOAT4& valueRight);

	static void Normalize(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& value);
	static float Length(const DirectX::XMFLOAT3& value);
	static float LengthSq(const DirectX::XMFLOAT3& value);
	static float Dot(const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);
	static void Cross(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& valueLeft, const DirectX::XMFLOAT3& valueRight);
	
	static void Transform(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& value, const DirectX::XMFLOAT4X4& mtx);
	static void TransformNormal(DirectX::XMFLOAT3& valueReturn, const DirectX::XMFLOAT3& value, const DirectX::XMFLOAT4X4& mtx);
	static void Identity(DirectX::XMFLOAT4X4& valueReturn);
	static void Inverse(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT4X4& value);
	static void Transpose(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT4X4& value);
	static void LookAtLH(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& posAt, const DirectX::XMFLOAT3& vecUp);
	static void PerspectiveFovLH(DirectX::XMFLOAT4X4& valueReturn, float fov, float aspect, float nearZ, float farZ);
	static void Scaling(DirectX::XMFLOAT4X4& valueReturn, float value);
	static void Scaling(DirectX::XMFLOAT4X4& valueReturn, float x, float y, float z);
	static void Scaling(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT3& value);
	static void RotationX(DirectX::XMFLOAT4X4& valueReturn, float angle);
	static void RotationY(DirectX::XMFLOAT4X4& valueReturn, float angle);
	static void RotationZ(DirectX::XMFLOAT4X4& valueReturn, float angle);
	static void RotationAxis(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT3& value, float angle);
	static void RotationQuaternion(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT3& value, float angle);
	static void Translation(DirectX::XMFLOAT4X4& valueReturn, float x, float y, float z);
	static void Translation(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT3& value);
	static void Multiplication(DirectX::XMFLOAT4X4& valueReturn, const DirectX::XMFLOAT4X4& valueLeft, const DirectX::XMFLOAT4X4& valueRight);
};

#endif // !_XM_MATH_H_
