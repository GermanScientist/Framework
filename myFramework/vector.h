/**
 * @file vector.h
 *
 * @brief The Textureloader header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

template <class T>
class Vector_t
{
	public:
		///@brief Constructor of the Vector.
		Vector_t<T>();

		///@brief Constructor of the Vector.
		///@param _x The X value of the vector.
		///@param _y The Y value of the vector.
		Vector_t<T>(T _x, T _y);

		///@brief Constructor of the Vector.
		///@param _x The X value of the vector.
		///@param _y The Y value of the vector.
		///@param _z The Z value of the vector.
		Vector_t<T>(T _x, T _y, T _z);

		///@brief Destructor of the Vector.
		virtual ~Vector_t<T>();

		///@brief The X value of the vector.
		T x;

		///@brief The Y value of the vector.
		T y;

		///@brief The Z value of the vector.
		T z;

		///@brief Gets the down vector.
		///@return Vector_t<T>(0, 1, 0)
		static Vector_t<T> getDown();

		///@brief Gets the up vector.
		///@return Vector_t<T>(0, -1, 0)
		static Vector_t<T> getUp();

		///@brief Gets the left vector.
		///@return Vector_t<T>(-1, 0, 0)
		static Vector_t<T> getLeft();

		///@brief Gets the right vector.
		///@return Vector_t<T>(1, 0, 0)
		static Vector_t<T> getRight();

		///@brief Gets the forward vector.
		///@return Vector_t<T>(0, 0, -1)
		static Vector_t<T> getForward();

		///@brief Gets the backward vector.
		///@return Vector_t<T>(0, 0, 1)
		static Vector_t<T> getBackward();

		///@brief Sets the Vector values to the given values.
		///@param _x The new X value.
		///@param _y The new Y value.
		///@param _z The new Z value.
		///@return Vector_t<T> *this
		Vector_t<T> setVector(T _x, T _y, T _z);
		
		///@brief Creates a copy of the Vector.
		///@return Vector_t<T>(this->x, this->y, this->z)
		Vector_t<T> copyVector();

		///@brief Gets the distance between this Vector and the other Vector.
		///@param _other The other vector.
		///@return T distance
		T getDistance(Vector_t<T> _other);

		///@brief Gets the distance between Vector a and Vector b.
		///@param _a Vector a.
		///@param _b Vector b.
		///@return T distance
		static T getDistance(Vector_t<T> _a, Vector_t<T> _b);

		///@brief Gets the dot product between this Vector and the other Vector.
		///@param _other The other vector.
		///@return T dotProduct
		T getDot(Vector_t<T> _other);

		///@brief Gets the dot product between Vector a and Vector b.
		///@param _a Vector a.
		///@param _b Vector b.
		///@return T dotProduct
		static T getDot(Vector_t<T> _a, Vector_t<T> _b);

		///@brief Gets the interpolated value between this Vector and the other Vector.
		///@param _other The other vector.
		///@param _amount The value used to interpolate between this Vector and the other Vector.
		///@return Vector_t<T> *this
		Vector_t<T> lerp(Vector_t<T> _other, T _amount);

		///@brief Gets the interpolated value between Vector a and Vector b.
		///@param _a Vector a.
		///@param _b Vector b.
		///@param _amount The value used to interpolate between Vector a and Vector b.
		///@return Vector_t<T>
		static Vector_t<T> lerp(Vector_t<T> _a, Vector_t<T> _b, T _amount);

		///@brief Gets the magnitude of this Vector.
		///@return T magnitude
		T getMagnitude();

		///@brief Gets the magnitude of a Vector.
		///@param _other The Vector you want to know the magnitude of.
		///@return T magnitude
		static T getMagnitude(Vector_t<T> _other);

		///@brief Gets the squared magnitude of this Vector.
		///@return T squaredMagnitude
		T getMagnitudeSquared();

		///@brief Gets the squared magnitude of a Vector.
		///@param _other The Vector you want to know the squared magnitude of.
		///@return T squaredMagnitude
		static T getMagnitudeSquared(Vector_t<T> _other);

		///@brief Normalizes this Vector.
		///@return Vector_t<T> *this
		Vector_t<T> normalize();

		///@brief Normalizes a Vector.
		///@param _other The Vector you want to normalize.
		///@return Vector_t<T> _other
		static Vector_t<T> normalize(Vector_t<T> _other);

		///@brief Gets the normalized Vector.
		///@return Vector_t<T> normalizedVector
		Vector_t<T> getNormalized();

		///@brief Gets the normalized Vector.
		///@param _other The Vector you want the normalized Vector of.
		///@return Vector_t<T> normalizedVector
		static Vector_t<T> getNormalized(Vector_t<T> _other);

		///@brief Clamps this Vector.
		///@param _min The minimum the value is allowed to be clamped.
		///@param _max The maximum the value is allowed to be clamped.
		///@return Vector_t<T> *this
		Vector_t<T> clamp(T _min, T _max);

		///@brief Clamps a Vector.
		///@param _other The Vector that needs to be clamped.
		///@param _min The minimum the value is allowed to be clamped.
		///@param _max The maximum the value is allowed to be clamped.
		///@return Vector_t<T> _other
		static Vector_t<T> clamp(Vector_t<T> _other, T _min, T _max);

		///@brief Gets the clamped Vector.
		///@param _min The minimum the value is allowed to be clamped.
		///@param _max The maximum the value is allowed to be clamped.
		///@return Vector_t<T> clampedVector
		Vector_t<T> getClamped(T _min, T _max);

		///@brief Gets the clamped Vector.
		///@param _other The Vector you want the clamped Vector of.
		///@param _min The minimum the value is allowed to be clamped.
		///@param _max The maximum the value is allowed to be clamped.
		///@return Vector_t<T> clampedVector
		static Vector_t<T> getClamped(Vector_t<T> _other, T _min, T _max);

		///@brief Overloads the += operator.
		///@param _other The Vector you want add to this Vector.
		Vector_t<T>& operator+=(const Vector_t<T>& _other);

		///@brief Overloads the + operator.
		///@param _other The Vector you want add to this Vector.
		Vector_t<T> operator+(const Vector_t<T>& _other) const;

		///@brief Overloads the -= operator.
		///@param _other The Vector you want subtract from this Vector.
		Vector_t<T>& operator-=(const Vector_t<T>& _other);

		///@brief Overloads the - operator.
		///@param _other The Vector you want subtract from this Vector.
		Vector_t<T> operator-(const Vector_t<T>& _other) const;

		///@brief Overloads the *= operator.
		///@param _other The Vector you want multiply to this Vector.
		Vector_t<T>& operator*=(const Vector_t<T>& _other);

		///@brief Overloads the * operator.
		///@param _other The Vector you want multiply to this Vector.
		Vector_t<T> operator*(const Vector_t<T>& _other) const;

		///@brief Overloads the /= operator.
		///@param _other The Vector you want divide by this Vector.
		Vector_t<T>& operator/=(const Vector_t<T>& _other);

		///@brief Overloads the / operator.
		///@param _other The Vector you want divide by this Vector.
		Vector_t<T> operator/(const Vector_t<T>& _other) const;

		///@brief Overloads the += operator.
		///@param _other The number you want add to this Vector.
		Vector_t<T>& operator+=(const T _other);

		///@brief Overloads the + operator.
		///@param _other The number you want add to this Vector.
		Vector_t<T> operator+(const T _other) const;

		///@brief Overloads the -= operator.
		///@param _other The number you want subtract from this Vector.
		Vector_t<T>& operator-=(const T _other);

		///@brief Overloads the - operator.
		///@param _other The number you want subtract from this Vector.
		Vector_t<T> operator-(const T _other) const;

		///@brief Overloads the *= operator.
		///@param _other The number you want multiply to this Vector.
		Vector_t<T>& operator*=(const T _other);

		///@brief Overloads the * operator.
		///@param _other The number you want multiply to this Vector.
		Vector_t<T> operator*(const T _other) const;

		///@brief Overloads the /= operator.
		///@param _other The number you want divide by this Vector.
		Vector_t<T>& operator/=(const T _other);

		///@brief Overloads the / operator.
		///@param _other The number you want divide by this Vector.
		Vector_t<T> operator/(const T _other) const;

		///@brief Overloads the == operator.
		///@param _other The Vector you want to compare with this Vector.
		bool operator==(const Vector_t<T>& _other) const;

		///@brief Overloads the != operator.
		///@param _other The Vector you want to compare with this Vector.
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


//Get down direction
template<class T>
Vector_t<T> Vector_t<T>::getDown()
{
	return Vector_t<T>(0, 1, 0);
}

//Get up direction
template<class T>
Vector_t<T> Vector_t<T>::getUp()
{
	return Vector_t<T>(0, -1, 0);
}

//Get left direction
template<class T>
Vector_t<T> Vector_t<T>::getLeft()
{
	return Vector_t<T>(-1, 0, 0);
}

//Get right direction
template<class T>
Vector_t<T> Vector_t<T>::getRight()
{
	return Vector_t<T>(1, 0, 0);
}

//Get forward direction
template<class T>
Vector_t<T> Vector_t<T>::getForward()
{
	return Vector_t<T>(0, 0, -1);
}

//Get backward direction
template<class T>
Vector_t<T> Vector_t<T>::getBackward()
{
	return Vector_t<T>(0, 0, 1);
}

//Set vector values
template<class T>
Vector_t<T> Vector_t<T>::setVector(T _x, T _y, T _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;

	return *this;
}

//Copy vector
template<class T>
Vector_t<T> Vector_t<T>::copyVector()
{
	return Vector_t<T>(this->x, this->y, this->z);
}

//Get distance between 2 vectors
template<class T>
T Vector_t<T>::getDistance(Vector_t<T> _other)
{
	float distX = this->x - _other.x;
	float distY = this->y - _other.y;
	float distZ = this->z - _other.z;

	return sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
}

template<class T>
T Vector_t<T>::getDistance(Vector_t<T> _a, Vector_t<T> _b)
{
	float distX = _a.x - _b.x;
	float distY = _a.y - _b.y;
	float distZ = _a.z - _b.z;

	return sqrt((distX * distX) + (distY * distY) + (distZ * distZ));
}

//Get the dot value between 2 vectors
template<class T>
T Vector_t<T>::getDot(Vector_t<T> _other)
{
	T a = (this->x * _other.x);
	T b = (this->y * _other.y);
	T c = (this->z * _other.z);

	return a + b + c;
}

template<class T>
T Vector_t<T>::getDot(Vector_t<T> _a, Vector_t<T> _b)
{
	T a = (_a.x * _b.x);
	T b = (_a.y * _b.y);
	T c = (_a.z * _b.z);

	return a + b + c;
}

//Get lerped value
template<class T>
Vector_t<T> Vector_t<T>::lerp(Vector_t<T> _other, T _amount)
{
	this->x = (this->x + _other.x) * _amount;
	this->y = (this->y + _other.y) * _amount;
	this->z = (this->z + _other.z) * _amount;

	return *this;
}

template<class T>
Vector_t<T> Vector_t<T>::lerp(Vector_t<T> _a, Vector_t<T> _b, T _amount)
{
	T a = (_a.x + _b.x) * _amount;
	T b = (_a.y + _b.y) * _amount;
	T c = (_a.z + _b.z) * _amount;

	return Vector_t<T>(a, b, c);
}

//Get the magnitude of the vector
template<class T>
T Vector_t<T>::getMagnitude()
{
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

template<class T>
T Vector_t<T>::getMagnitude(Vector_t<T> _other)
{
	return sqrt((_other.x * _other.x) + (_other.y * _other.y) + (_other.z * _other.z));
}

//Get the magnitude squared
template<class T>
T Vector_t<T>::getMagnitudeSquared()
{
	return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

template<class T>
T Vector_t<T>::getMagnitudeSquared(Vector_t<T> _other)
{
	return (_other.x * _other.x) + (_other.y * _other.y) + (_other.z * _other.z);
}

//Normalize the vector
template<class T>
Vector_t<T> Vector_t<T>::normalize()
{
	T magnitude = this->getMagnitude();
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;

	return *this;
}

template<class T>
Vector_t<T> Vector_t<T>::normalize(Vector_t<T> _other)
{
	T magnitude = _other.getMagnitude();
	_other.x /= magnitude;
	_other.y /= magnitude;
	_other.z /= magnitude;

	return _other;
}

//Get the normalized vector
template<class T>
Vector_t<T> Vector_t<T>::getNormalized()
{
	return Vector_t<T>(this->x/this->getMagnitude(), this->y/this->getMagnitude(), this->z/this->getMagnitude());
}

template<class T>
Vector_t<T> Vector_t<T>::getNormalized(Vector_t<T> _other)
{
	return Vector_t<T>(_other.x / _other.getMagnitude(), _other.y / _other.getMagnitude(), _other.z / _other.getMagnitude());
}

//Clamp the vector
template<class T>
Vector_t<T> Vector_t<T>::clamp(T _min, T _max)
{
	if (this->x < _min) {this->x = _min;};
	if (this->x > _max) {this->x = _max;};

	if (this->y < _min) {this->y = _min;};
	if (this->y > _max) {this->y = _max;};

	if (this->z < _min) {this->z = _min;};
	if (this->z > _max) {this->z = _max;};

	return *this;
}

template<class T>
Vector_t<T> Vector_t<T>::clamp(Vector_t<T> _other, T _min, T _max)
{
	if (_other.x < _min) {_other.x = _min;};
	if (_other.x > _max) {_other.x = _max;};

	if (_other.y < _min) {_other.y = _min;};
	if (_other.y > _max) {_other.y = _max;};

	if (_other.z < _min) {_other.z = _min;};
	if (_other.z > _max) { _other.z = _max;};

	return _other;
}

//Get the clamped the vector
template<class T>
Vector_t<T> Vector_t<T>::getClamped(T _min, T _max)
{
	Vector3 tempVector(this->x, this->y, this->z);
	if (tempVector.x < _min) {tempVector.x = _min;};
	if (tempVector.x > _max) {tempVector.x = _max;};

	if (tempVector.y < _min) {tempVector.y = _min;};
	if (tempVector.y > _max) {tempVector.y = _max;};

	if (tempVector.z < _min) {tempVector.z = _min;};
	if (tempVector.z > _max) {tempVector.z = _max;};

	return tempVector;
}

template<class T>
Vector_t<T> Vector_t<T>::getClamped(Vector_t<T> _other, T _min, T _max)
{
	Vector3 tempVector(_other.x, _other.y, _other.z);
	if (tempVector.x < _min) {tempVector.x = _min;};
	if (tempVector.x > _max) {tempVector.x = _max;};

	if (tempVector.y < _min) {tempVector.y = _min;};
	if (tempVector.y > _max) {tempVector.y = _max;};

	if (tempVector.z < _min) {tempVector.z = _min;};
	if (tempVector.z > _max) {tempVector.z = _max;};

	return tempVector;
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