//**-------------------------------------------------------**
//**
//**                    xm_math.h
//**               Author: Akagawa Yuichi
//**
//**-------------------------------------------------------**
#ifndef _XM_MATH_H_
#define _XM_MATH_H_

#include <DirectXMath.h>

using namespace DirectX;

namespace XMMath
{
	struct Float2;
	struct Float3;
	struct Float4;
	struct Matrix;

	//Float2
	struct Float2 : public XMFLOAT2
	{
		inline Float2() : XMFLOAT2(0.0f, 0.0f)
		{

		}

		inline Float2(const Float2& value) : XMFLOAT2(value.x, value.y)
		{

		}

		inline Float2(float value) : XMFLOAT2(value, value)
		{

		}

		inline Float2(float x, float y) : XMFLOAT2(x, y)
		{

		}

		inline Float2(const XMVECTOR& value) : XMFLOAT2()
		{
			XMVECTOR vec = value;
			XMStoreFloat2((XMFLOAT2*)this, vec);
		}

		inline operator XMVECTOR() const
		{
			XMFLOAT2 f2 = *this;
			XMVECTOR vec = XMLoadFloat2(&f2);
			return vec;
		}

		inline Float2& operator=(const Float2& value)
		{
			if (this != &value)
			{
				x = value.x;
				y = value.y;
			}
			return *this;
		}

		inline bool operator==(const Float2& value)const
		{
			return XMVector2Equal(*this, value);
		}

		inline bool operator!=(const Float2& value)const
		{
			return !XMVector2Equal(*this, value);
		}

		inline const Float2 operator+(const Float2& value)const
		{
			return (Float2)XMVectorAdd(*this, value);
		}

		inline const Float2 operator+(float value)const
		{
			Float2 f2(value, value);
			return (Float2)XMVectorAdd(*this, f2);
		}

		inline const Float2 operator-(const Float2& value)const
		{
			return (Float2)XMVectorSubtract(*this, value);
		}

		inline const Float2 operator-(float value)const
		{
			Float2 f2(value, value);
			return (Float2)XMVectorSubtract(*this, f2);
		}

		inline const Float2 operator*(float value)const
		{
			Float2 f2(value, value);
			return (Float2)XMVectorMultiply(*this, f2);
		}

		inline const Float2 operator*(const Float2& value)const
		{
			return (Float2)XMVectorMultiply(*this, value);
		}

		inline const Float2 operator/(float value)const
		{
			Float2 f2(XMVectorReciprocal(Float2(value, value)));
			return (Float2)XMVectorMultiply(*this, f2);
		}

		inline const Float2 operator/(const Float2& value)const
		{
			Float2 f2(XMVectorReciprocal(value));
			return (Float2)XMVectorMultiply(*this, f2);
		}

		inline Float2& operator+=(const Float2& value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float2& operator+=(float value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float2& operator-=(const Float2& value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float2& operator-=(float value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float2& operator*=(float value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float2& operator*=(const Float2& value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float2& operator/=(float value)
		{
			*this = *this / value;
			return *this;
		}

		inline Float2& operator/=(const Float2& value)
		{
			*this = *this / value;
			return *this;
		}

		inline const Float2 operator-()const
		{
			Float2 f2(-1.0f, -1.0f);
			return (Float2)XMVectorMultiply(*this, f2);
		}

		inline float Length()const
		{
			return ((Float2)XMVector2Length(*this)).x;
		}

		inline float LengthSq()const
		{
			return ((Float2)XMVector2LengthSq(*this)).x;
		}

		inline Float2& Normalize()
		{
			*this = (Float2)XMVector2Normalize(*this);
			return *this;
		}
	};

	//Float3
	struct Float3 : public XMFLOAT3
	{
		inline Float3() : XMFLOAT3(0.0f, 0.0f, 0.0f)
		{

		}

		inline Float3(const Float3& value) : XMFLOAT3(value.x, value.y, value.z)
		{

		}

		inline Float3(float value) : XMFLOAT3(value, value, value)
		{

		}

		inline Float3(float x, float y, float z) : XMFLOAT3(x, y, z)
		{

		}

		inline Float3(const XMVECTOR& value) : XMFLOAT3()
		{
			XMVECTOR vec = value;
			XMStoreFloat3((XMFLOAT3*)this, vec);
		}

		inline operator XMVECTOR()const
		{
			XMFLOAT3 f3 = *this;
			XMVECTOR vec = XMLoadFloat3(&f3);
			return vec;
		}

		inline Float3& operator=(const Float3& value)
		{
			if (this != &value)
			{
				x = value.x;
				y = value.y;
				z = value.z;
			}
			return *this;
		}

		inline bool operator==(const Float3& value)const
		{
			return XMVector3Equal(*this, value);
		}

		inline bool operator!=(const Float3& value)const
		{
			return !XMVector3Equal(*this, value);
		}

		inline const Float3 operator+(const Float3& value)const
		{
			return (Float3)XMVectorAdd(*this, value);
		}

		inline const Float3 operator+(float value)const
		{
			Float3 f3(value, value, value);
			return (Float3)XMVectorAdd(*this, f3);
		}

		inline const Float3 operator-(const Float3& value)const
		{
			return (Float3)XMVectorSubtract(*this, value);
		}

		inline const Float3 operator-(float value)const
		{
			Float3 f3(value, value, value);
			return (Float3)XMVectorSubtract(*this, f3);
		}

		inline const Float3 operator*(float value)const
		{
			Float3 f3(value, value, value);
			return (Float3)XMVectorMultiply(*this, f3);
		}

		inline const Float3 operator*(const Float3& value)const
		{
			return (Float3)XMVectorMultiply(*this, value);
		}

		inline const Float3 operator/(float value)const
		{
			Float3 f3(XMVectorReciprocal(Float3(value, value, value)));
			return (Float3)XMVectorMultiply(*this, f3);
		}

		inline const Float3 operator/(const Float3& value)const
		{
			Float3 f3(XMVectorReciprocal(value));
			return (Float3)XMVectorMultiply(*this, f3);
		}

		inline Float3& operator+=(const Float3& value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float3& operator+=(float value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float3& operator-=(const Float3& value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float3& operator-=(float value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float3& operator*=(float value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float3& operator*=(const Float3& value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float3& operator/=(float value)
		{
			*this = *this / value;
			return *this;
		}

		inline Float3& operator/=(const Float3& value)
		{
			*this = *this / value;
			return *this;
		}

		inline const Float3 operator-()const
		{
			Float3 f3(-1.0f, -1.0f, -1.0f);
			return (Float3)XMVectorMultiply(*this, f3);
		}

		inline float Length()const
		{
			return ((Float3)XMVector3Length(*this)).x;
		}

		inline float LengthSq()const
		{
			return ((Float3)XMVector3LengthSq(*this)).x;
		}

		inline Float3& Normalize()
		{
			*this = (Float3)XMVector3Normalize(*this);
			return *this;
		}
	};

	//Float4
	struct Float4 : public XMFLOAT4
	{
		inline Float4() : XMFLOAT4(0.0f, 0.0f, 0.0f, 0.0f)
		{

		}

		inline Float4(const Float4& value) : XMFLOAT4(value.x, value.y, value.z, value.w)
		{

		}

		inline Float4(float value) : XMFLOAT4(value, value, value, value)
		{

		}

		inline Float4(float x, float y, float z, float w) : XMFLOAT4(x, y, z, w)
		{

		}

		inline Float4(const XMVECTOR& value) : XMFLOAT4()
		{
			XMVECTOR vec = value;
			XMStoreFloat4((XMFLOAT4*)this, vec);
		}

		inline operator XMVECTOR()const
		{
			XMFLOAT4 f4 = *this;
			XMVECTOR vec = XMLoadFloat4(&f4);
			return vec;
		}

		inline Float4& operator=(const Float4& value)
		{
			if (this != &value)
			{
				x = value.x;
				y = value.y;
				z = value.z;
				w = value.w;
			}
			return *this;
		}

		inline bool operator==(const Float4& value)const
		{
			return XMVector4Equal(*this, value);
		}

		inline bool operator!=(const Float4& value)const
		{
			return !XMVector4Equal(*this, value);
		}

		inline const Float4 operator+(const Float4& value)const
		{
			return (Float4)XMVectorAdd(*this, value);
		}

		inline const Float4 operator+(float value)const
		{
			Float4 f4(value, value, value, value);
			return (Float4)XMVectorAdd(*this, f4);
		}

		inline const Float4 operator-(const Float4& value)const
		{
			return (Float4)XMVectorSubtract(*this, value);
		}

		inline const Float4 operator-(float value)const
		{
			Float4 f4(value, value, value, value);
			return (Float4)XMVectorSubtract(*this, f4);
		}

		inline const Float4 operator*(float value)const
		{
			Float4 f4(value, value, value, value);
			return (Float4)XMVectorMultiply(*this, f4);
		}

		inline const Float4 operator*(const Float4& value)const
		{
			return (Float4)XMVectorMultiply(*this, value);
		}

		inline const Float4 operator/(float value)const
		{
			Float4 f4(XMVectorReciprocal(Float4(value, value, value, value)));
			return (Float4)XMVectorMultiply(*this, f4);
		}

		inline const Float4 operator/(const Float4& value)const
		{
			Float4 f4(XMVectorReciprocal(value));
			return (Float4)XMVectorMultiply(*this, f4);
		}

		inline Float4& operator+=(const Float4& value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float4& operator+=(float value)
		{
			*this = *this + value;
			return *this;
		}

		inline Float4& operator-=(const Float4& value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float4& operator-=(float value)
		{
			*this = *this - value;
			return *this;
		}

		inline Float4& operator*=(float value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float4& operator*=(const Float4& value)
		{
			*this = *this * value;
			return *this;
		}

		inline Float4& operator/=(float value)
		{
			*this = *this / value;
			return *this;
		}

		inline Float4& operator/=(const Float4& value)
		{
			*this = *this / value;
			return *this;
		}

		inline const Float4 operator-()const
		{
			Float4 f4(-1.0f, -1.0f, -1.0f, -1.0f);
			return (Float4)XMVectorMultiply(*this, f4);
		}

		inline float Length()const
		{
			return ((Float4)XMVector4Length(*this)).x;
		}

		inline float LengthSq()const
		{
			return ((Float4)XMVector4LengthSq(*this)).x;
		}

		inline Float4& Normalize()
		{
			*this = (Float4)XMVector4Normalize(*this);
			return *this;
		}
	};

	//Matrix
	struct Matrix : public XMFLOAT4X4
	{
		inline Matrix() : XMFLOAT4X4()
		{
			Identity();
		}

		inline Matrix(const Matrix& mtx) : XMFLOAT4X4(mtx)
		{

		}

		inline Matrix(const XMMATRIX& other) : XMFLOAT4X4()
		{
			XMMATRIX mtx = other;
			XMStoreFloat4x4((XMFLOAT4X4*)this, mtx);
		}

		inline operator XMMATRIX() const
		{
			Matrix mtx = *this;
			XMMATRIX matrix = XMLoadFloat4x4(&mtx);
			return matrix;
		}

		inline Matrix& operator=(const XMFLOAT4X4& other)
		{
			(XMFLOAT4X4)*this = other;
			return *this;
		}

		inline Matrix& operator=(const XMMATRIX& other)
		{
			XMMATRIX mtx = other;
			XMStoreFloat4x4((XMFLOAT4X4*)this, mtx);
			return *this;
		}

		inline Float3 GetPos()const
		{
			return Float3(_41, _42, _43);
		}

		inline Matrix& SetPos(const Float3& value)
		{
			_41 = value.x;
			_42 = value.y;
			_43 = value.z;
			return *this;
		}

		inline const Matrix operator*(const Matrix& value)const
		{
			return (Matrix)XMMatrixMultiply(*this, value);
		}

		inline Matrix& operator*=(const Matrix& value)
		{
			*this = *this * value;
			return *this;
		}

		inline Matrix& Identity()
		{
			*this = (Matrix)XMMatrixIdentity();
			return *this;
		}

		inline Matrix& Scaling(const Float3& scale)
		{
			*this = (Matrix)XMMatrixScalingFromVector(scale);
			return *this;
		}

		inline Matrix& RotationX(float angle)
		{
			*this = (Matrix)XMMatrixRotationX(angle);
			return *this;
		}

		inline Matrix& RotationY(float angle)
		{
			*this = (Matrix)XMMatrixRotationY(angle);
			return *this;
		}

		inline Matrix& RotationZ(float angle)
		{
			*this = (Matrix)XMMatrixRotationZ(angle);
			return *this;
		}

		inline Matrix& RotationAxis(const Float3& axis, float angle)
		{
			*this = (Matrix)XMMatrixRotationAxis(axis, angle);
			return *this;
		}

		inline Matrix& RotationQuaternionAxis(const Float3& axis, float angle)
		{
			*this = (Matrix)XMMatrixRotationQuaternion(XMQuaternionRotationAxis(axis, angle));
			return *this;
		}

		inline Matrix& Translation(const Float3& value)
		{
			*this = (Matrix)XMMatrixTranslationFromVector(value);
			return *this;
		}

		inline Matrix& Transpose()
		{
			*this = (Matrix)XMMatrixTranspose(*this);
			return *this;
		}

		inline Matrix& Inverse()
		{
			XMVECTOR vec;
			*this = (Matrix)XMMatrixInverse(&vec, *this);
			return *this;
		}
	};

	//Method Float2
	inline float Dot(const Float2& value1, const Float2& value2)
	{
		return ((Float2)XMVector2Dot(value1, value2)).x;
	}

	inline float Length(const Float2& value)
	{
		return ((Float2)XMVector2Length(value)).x;
	}

	inline float LengthSq(const Float2& value)
	{
		return ((Float2)XMVector2LengthSq(value)).x;
	}

	inline const Float2 Normalize(const Float2& value)
	{
		return (Float2)XMVector2Normalize(value);
	}

	//Method Float3
	inline float Dot(const Float3& value1, const Float3& value2)
	{
		return ((Float3)XMVector3Dot(value1, value2)).x;
	}

	inline const Float3 Cross(const Float3& value1, const Float3& value2)
	{
		return (Float3)XMVector3Cross(value1, value2);
	}

	inline float Length(const Float3& value)
	{
		return ((Float3)XMVector3Length(value)).x;
	}

	inline float LengthSq(const Float3& value)
	{
		return ((Float3)XMVector3LengthSq(value)).x;
	}

	inline const Float3 Normalize(const Float3& value)
	{
		return (Float3)XMVector3Normalize(value);
	}

	inline const Float3 Transform(const Float3& value, const Matrix& mtx)
	{
		return (Float3)XMVector3Transform(value, mtx);
	}

	inline const Float3 TransformNormal(const Float3& value, const Matrix& mtx)
	{
		return (Float3)XMVector3TransformNormal(value, mtx);
	}

	//Method Float4
	inline float Dot(const Float4& value1, const Float4& value2)
	{
		return ((Float4)XMVector4Dot(value1, value2)).x;
	}

	inline float Length(const Float4& value)
	{
		return ((Float4)XMVector4Length(value)).x;
	}

	inline float LengthSq(const Float4& value)
	{
		return ((Float4)XMVector4LengthSq(value)).x;
	}

	inline const Float4 Normalize(const Float4& value)
	{
		return (Float4)XMVector4Normalize(value);
	}

	//Method Matrix
	inline const Matrix Transpose(const Matrix& value)
	{
		return  (Matrix)XMMatrixTranspose(value);
	}

	inline const Matrix Inverse(const Matrix& value)
	{
		XMVECTOR vec;
		return (Matrix)XMMatrixInverse(&vec, value);
	}

	inline const Matrix LookAtLH(
		const Float3& pos, const Float3& posAt, const Float3& vecUp)
	{
		return (Matrix)XMMatrixLookAtLH(
			pos, posAt, vecUp);
	}

	inline const Matrix PerspectiveFovLH(
		float fov, float aspect, float nearZ, float farZ)
	{
		return (Matrix)XMMatrixPerspectiveFovLH(
			fov, aspect, nearZ, farZ);
	}
}
#endif // !_XM_MATH_H_
