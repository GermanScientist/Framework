#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

template <class T>
class Vector_t
{
	public:
		//Constructors
		Vector_t<T>();
		Vector_t<T>(T _x, T _y);
		Vector_t<T>(T _x, T _y, T _z);
		virtual ~Vector_t<T>();

		//Positions
		T x;
		T y;
		T z;

		//Get directions
		static Vector_t<T> getDown();
		static Vector_t<T> getUp();
		static Vector_t<T> getLeft();
		static Vector_t<T> getRight();
		static Vector_t<T> getForward();
		static Vector_t<T> getBackward();

		//Add another Vector to this Vector
		Vector_t<T>& operator+=(const Vector_t<T>& _other);
		Vector_t<T> operator+(const Vector_t<T>& _other) const;

		//Subtract another Vector to this Vector
		Vector_t<T>& operator-=(const Vector_t<T>& _other);
		Vector_t<T> operator-(const Vector_t<T>& _other) const;

		//Add another Vector to this Vector
		Vector_t<T>& operator*=(const Vector_t<T>& _other);
		Vector_t<T> operator*(const Vector_t<T>& _other) const;

		//Divide another Vector by this Vector
		Vector_t<T>& operator/=(const Vector_t<T>& _other);
		Vector_t<T> operator/(const Vector_t<T>& _other) const;

		//Add any number to this Vector
		Vector_t<T>& operator+=(const T _other);
		Vector_t<T> operator+(const T _other) const;

		//Subtract any number to this Vector
		Vector_t<T>& operator-=(const T _other);
		Vector_t<T> operator-(const T _other) const;

		//Multiply any number to this Vector
		Vector_t<T>& operator*=(const T _other);
		Vector_t<T> operator*(const T _other) const;

		//Divide any number by this Vector
		Vector_t<T>& operator/=(const T _other);
		Vector_t<T> operator/(const T _other) const;

		//Check if this is equal to other
		bool operator==(const Vector_t<T>& _other) const;

		//Check if this is not equal to other
		bool operator!=(const Vector_t<T>& _other) const;
};

//Vector1 typedefs
typedef Vector_t<int> Vectori;
typedef Vector_t<float> Vectorf;
typedef Vector_t<double> Vectord;
typedef Vectorf Vector;

//Vector2 typedefs
typedef Vector_t<int> Vector2i;
typedef Vector_t<float> Vector2f;
typedef Vector_t<double> Vector2d;
typedef Vector2f Vector2;

//Vector3 typedefs
typedef Vector_t<int> Vector3i;
typedef Vector_t<float> Vector3f;
typedef Vector_t<double> Vector3d;
typedef Vector3f Vector3;

//Constructor
template <class T>
Vector_t<T>::Vector_t()
{
	x = 0;
	y = 0;
	z = 0;
}

//Overloaded constructor
template <class T>
Vector_t<T>::Vector_t(T _x, T _y)
{
	x = _x;
	y = _y;
	z = 0;
}

//Overloaded constructor
template <class T>
Vector_t<T>::Vector_t(T _x, T _y, T _z)
{
	x = _x;
	y = _y;
	z = _z;
}

//Destructor
template <class T>
Vector_t<T>::~Vector_t()
{

}



template<class T>
Vector_t<T> Vector_t<T>::getDown()
{
	return Vector_t<T>(0, 1, 0);
}

template<class T>
Vector_t<T> Vector_t<T>::getUp()
{
	return Vector_t<T>(0, -1, 0);
}

template<class T>
Vector_t<T> Vector_t<T>::getLeft()
{
	return Vector_t<T>(-1, 0, 0);
}

template<class T>
Vector_t<T> Vector_t<T>::getRight()
{
	return Vector_t<T>(1, 0, 0);
}

template<class T>
Vector_t<T> Vector_t<T>::getForward()
{
	return Vector_t<T>(0, 0, -1);
}

template<class T>
Vector_t<T> Vector_t<T>::getBackward()
{
	return Vector_t<T>(0, 0, 1);
}

//Add another Vector to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator+=(const Vector_t<T>& _other)
{
	x += _other.x;
	y += _other.y;
	z += _other.z;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator+(const Vector_t<T>& _other) const
{
	return Vector_t<T>(x + _other.x, y + _other.y, z + _other.z);
}

//Subtract another Vector to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator-=(const Vector_t<T>& _other)
{
	x -= _other.x;
	y -= _other.y;
	z -= _other.z;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator-(const Vector_t<T>& _other) const
{
	return Vector_t<T>(x - _other.x, y - _other.y, z - _other.z);
}

//Multiply another Vector to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator*=(const Vector_t<T>& _other)
{
	x *= _other.x;
	y *= _other.y;
	z *= _other.z;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator*(const Vector_t<T>& _other) const
{
	return Vector_t<T>(x * _other.x, y * _other.y, z * _other.z);
}

//Divide another Vector to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator/=(const Vector_t<T>& _other)
{
	x /= _other.x;
	y /= _other.y;
	z /= _other.z;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator/(const Vector_t<T>& _other) const
{
	return Vector_t<T>(x / _other.x, y / _other.y, z / _other.z);
}

//Add any number to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator+=(const T _other)
{
	x += _other;
	y += _other;
	z += _other;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator+(const T _other) const
{
	return Vector_t<T>(x + _other, y + _other, z + _other);
}

//Subtract any number to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator-=(const T _other)
{
	x -= _other;
	y -= _other;
	z -= _other;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator-(const T _other) const
{
	return Vector_t<T>(x - _other, y - _other, z - _other);
}

//Multiply any number to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator*=(const T _other)
{
	x *= _other;
	y *= _other;
	z *= _other;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator*(const T _other) const
{
	return Vector_t<T>(x * _other, y * _other, z * _other);
}

//Divide any number to this Vector
template <class T>
Vector_t<T>& Vector_t<T>::operator/=(const T _other)
{
	x /= _other;
	y /= _other;
	z /= _other;
	
	return *this;
}

template <class T>
Vector_t<T> Vector_t<T>::operator/(const T _other) const
{
	return Vector_t<T>(x / _other, y / _other, z / _other);
}

//Check if this is equal to other
template <class T>
bool Vector_t<T>::operator==(const Vector_t<T>& _other) const {
	return (x == _other.x && y == _other.y && z == _other.z);
}

//Check if this is not equal to other
template <class T>
bool Vector_t<T>::operator!=(const Vector_t<T>& _other) const {
	return !(*this == _other);
}

//Iostream << and >> overloader
template <class T>
std::ostream& operator<<(std::ostream& _stream, Vector_t<T> _other)
{
	_stream << "(" << _other.x << ", " << _other.y << ", " << _other.z << ")";

	return _stream;
}

template <class T>
std::istream& operator>>(std::istream& _stream, Vector_t<T>& _other)
{
	_stream >> _other.x >> _other.y >> _other.z;

	return _stream;
}

#endif /* VECTOR_H */