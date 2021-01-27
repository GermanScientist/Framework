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

		//Set vector values
		Vector_t<T> setVector(T _x, T _y, T _z);
		
		//Copy vector
		Vector_t<T> copyVector();

		//Get difference
		T getDistance(Vector_t<T> _other);
		static T getDistance(Vector_t<T> _a, Vector_t<T> _b);

		//Get dot product
		T getDot(Vector_t<T> _other);
		static T getDot(Vector_t<T> _a, Vector_t<T> _b);

		//Get Lerped value
		Vector_t<T> lerp(Vector_t<T> _other, T _amount);
		static Vector_t<T> lerp(Vector_t<T> _a, Vector_t<T> _b, T _amount);

		//Get the magnitude
		T getMagnitude();
		static T getMagnitude(Vector_t<T> _other);

		//Get the magnitude squared
		T getMagnitudeSquared();
		static T getMagnitudeSquared(Vector_t<T> _other);

		//Normalize the vector
		Vector_t<T> normalize();
		static Vector_t<T> normalize(Vector_t<T> _other);

		//Get the normalized vector
		Vector_t<T> getNormalized();
		static Vector_t<T> getNormalized(Vector_t<T> _other);

		//Clamp the vector
		Vector_t<T> clamp(T _min, T _max);
		static Vector_t<T> clamp(Vector_t<T> _other, T _min, T _max);

		//Get the clamp vector
		Vector_t<T> getClamped(T _min, T _max);
		static Vector_t<T> getClamped(Vector_t<T> _other, T _min, T _max);

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