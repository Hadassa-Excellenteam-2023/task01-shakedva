#include "Vector.h"

Vector::Vector(size_t size, int value) : _size(size), _capacity(size), _data(new int[size])
{
	//_size = size;
	//_capacity = size;
	//_data = new int[size];
	for (int i = 0; i < _size; i++)
		_data[i] = value;
}

Vector::Vector(const Vector& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = new int[_size];
	for (int i = 0; i < _capacity; i++)
		_data[i] = other._data[i];
}

