#include "Vector.h"
#include <algorithm>

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

int& Vector::operator[](size_t index)
{
	if (isInRange(index)) 
		return _data[index];	
}

int Vector::operator[](size_t index) const
{
	if (isInRange(index)) 
		return _data[index];
}

bool Vector::isInRange(size_t index) const
{
	return index < _size;
}

void Vector::print()
{
	std::cout << "size: " << _size << " capacity: " << _capacity << '\n';
	for (int i = 0; i < _size; i++)
		std::cout << _data[i] << " ";
	std::cout << std::endl;
}

void Vector::swap(Vector& other)
{
	Vector temp = other;
	other = *this;
	*this = temp;	
}

void Vector::resize(size_t capacity)
{
	if (capacity == _capacity)
		return;

	int* temp = new int[capacity];
	for (int i = 0; i < capacity; i++)
		if (i < _capacity)
			temp[i] = _data[i];
		else
			temp[i] = 0;
	delete[] _data;
	_data = temp;
	_size = capacity < _capacity ? capacity : _size;
	_capacity = capacity;
	
}

void Vector::push_back(const int& value)
{
	if (_size < _capacity)
		_data[_size] = value;
	else
	{
		double multiply = _capacity > 128 ? 1.5 : 2;
		size_t newCapacity = (size_t)(_capacity * multiply);
		resize(newCapacity);
		_data[_size] = value;
	}
	_size++;
}     

void Vector::pop_back()
{
	_size--;
	_data[_size] = 0;
}

size_t Vector::size() const
{
	return _size;
}

size_t Vector::capacity() const
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

// lexicographically greater than the contents of other
bool Vector::operator>(const Vector& other)
{
	size_t i = 0;
	while (i < _size && i < other._size)
	{
		if (_data[i] > other._data[i])
			return true;
		if (_data[i] < other._data[i])
			return false;
		++i;
	}
	return _size > other._size;
}

bool Vector::operator>=(const Vector& other)
{
	return *this > other || *this == other ;
}

bool Vector::operator<(const Vector& other)
{
	return !(*this >= other);
}

bool Vector::operator<=(const Vector& other)
{
	return *this < other || *this == other;
}

bool operator==(const Vector& l, const Vector& r)
{
	if (l.size() != r.size())
		return false;
	if (l.capacity() != r.capacity())
		return false;
	for (int i = 0; i < l.size(); i++)
	{
		if (l[i] != r[i])
			return false;
	}
	return true;
}

bool operator!=(const Vector& l, const Vector& r)
{
	return !(l == r);
}
