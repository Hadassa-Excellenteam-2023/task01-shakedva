#include "Vector.h"

Vector::Vector(size_t size, int value) : _size(size), _capacity(size), _data(new int[size])
{
	for (int i = 0; i < _size; i++)
		_data[i] = value;
}

Vector::Vector(const Vector& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = new int[_size];
	for (int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

Vector::~Vector()
{
	delete[] _data;
}

Vector& Vector::operator=(const Vector &other)
{
	if (this == &other)
		return *this;

	delete[] _data;
	_data = new int[other._capacity];
	_size = other._size;
	_capacity = other._capacity;
	for (int i = 0; i < _size; i++)
		_data[i] = other._data[i];
	return *this;
}

void Vector::print()
{
	for (int i = 0; i < _size; i++)
		std::cout << _data[i];
}

size_t Vector::size()
{
	return _size;
}

size_t Vector::capacity()
{
	return _capacity;
}

bool Vector::empty()
{
	return _size == 0;
}

int* Vector::data()
{
	return _size == 0 ? nullptr : _data;
}

void Vector::clear()
{
	delete[] _data;
	_data = nullptr;
	_size = 0;
}	

