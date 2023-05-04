#include "Vector.h"
#include <algorithm>
/*
* Constructor that receives optional size and value. 
* Initialize a container with the size and fill it with the value. 
*/
Vector::Vector(size_t size, int value) : _size(size), _capacity(size), _data(new int[size])
{
	for (int i = 0; i < _size; i++)
		_data[i] = value;
}
/*
* Copy constructor that receives a Vector.
* Deep copy all the Vector's data.
*/
Vector::Vector(const Vector& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_data = new int[_size];
	for (size_t i = 0; i < _size; i++)
		_data[i] = other._data[i];
}
/*
* Destructor.
*/
Vector::~Vector()
{
	delete[] _data;
}
/*
* Copy assignment operator overload that receives a Vector and copy it's data. 
*/
Vector& Vector::operator=(Vector other)
{
	Vector tmp(other);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
	std::swap(_data, other._data);
	return *this;
}
/*
* Move constructor that receives a lvalue Vector.
*/
Vector::Vector(Vector&& other) 
	: _size(other._size), _capacity(other._capacity), _data(other._data)
{
	other._size = 0;
	other._capacity = INITIAL_CAPACITY;
	other._data = nullptr;
}
/*
* Access specified element
*/
int& Vector::operator[](size_t index)
{
	if (!isInRange(index))
		throw std::out_of_range("Index out range");
	return _data[index];
}
/*
* Access specified element
*/
int Vector::operator[](size_t index) const
{
	if (!isInRange(index))
		throw std::out_of_range("Index out range");
	return _data[index];
}

bool Vector::isInRange(size_t index) const
{
	return index < _size;
}
/*
* Calls resize with a specific capacity, depends on the current vector's capacity. 
*/
void Vector::addCapacity()
{
	size_t capacity = (_capacity == 0) ? 1 : _capacity;
	double multiply = capacity > 128 ? 1.5 : 2;
	size_t newCapacity = (size_t)(capacity * multiply);
	resize(newCapacity);
}
/*
* Receives two Vectors and swaps their data. 
*/
void Vector::swap(Vector& other)
{
	Vector temp = other;
	other = *this;
	*this = temp;	
}
/*
* Receive capacity and resizes the _data accordingly.
* If the current capacity is biggen then received, the container will be reduced. 
* Otherwise, the container will add additional 0s at the end. 
*/
void Vector::resize(size_t capacity)
{
	if (capacity == _capacity) // no need to resize
		return;
	int* temp;
	if (capacity != 0)
	temp = new int[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		// when capacity is 0, it has nothing to add from _data to temp. 
		// add additional 0s to the end. 
 		if (i < _capacity && _capacity > 0)
			temp[i] = _data[i];
		else
			temp[i] = 0;
	}
	delete[] _data;
	_data = temp;
	// if received smaller capacity, some values were truncated.
	_size = capacity < _capacity ? capacity : _size;
	_capacity = capacity;
	
}
/*
* Adds an element to the end, and resizes if needed.
*/
void Vector::push_back(const int& value)
{
	if (_size >= _capacity)
		addCapacity();

	_data[_size] = value;
	_size++;
}     
/*
* Removes the last element
*/
void Vector::pop_back()
{
	if (_size > 0) {
		_size--;
		_data[_size] = 0;
	}
}
/*
* Erases the element in the index received
*/
void Vector::erase(size_t index)
{
	if (!isInRange(index)) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	for (size_t i = index; i < _size-1; i++)
		_data[i] = _data[i + 1];
	_size--;
}
/*
* Inserts an element in the index received
*/
void Vector::insert(size_t index, const int& value)
{
	if (!isInRange(index)) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (index == _size)
		push_back(value);
	else 
	{
		if (_size >= _capacity)
			addCapacity();
		
		for (size_t i = _size; i > index; i--)
			_data[i] = _data[i - 1];
		_data[index] = value;
		_size++;
	}
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

/*
* Checks if _data is lexicographically greater than the other Vector by comparing
* their values. 
*/
bool Vector::operator>(const Vector& other) const
{
	size_t i = 0;
	while (i < _size && i < other._size)
	{
		if (_data[i] != other._data[i])
			return _data[i] > other._data[i];
		++i;		
	}
	return _size > other._size;
}
/*
* Checks if _data is lexicographically greater or equal than the other Vector.
*/
bool Vector::operator>=(const Vector& other)
{
	return *this > other || *this == other ;
}
/*
* Checks if _data is lexicographically lesser than the other Vector.
*/
bool Vector::operator<(const Vector& other)
{
	return !(*this >= other);
}
/*
* Checks if _data is lexicographically lesser or equal  than the other Vector.
*/
bool Vector::operator<=(const Vector& other)
{
	return *this < other || *this == other;
}

/*
* Checks if _data is lexicographically equal to the other Vector.
*/
bool operator==(const Vector& l, const Vector& r)
{
	if (l.size() != r.size())
		return false;
	for (size_t i = 0; i < l.size(); i++)
	{
		if (l[i] != r[i])
			return false;
	}
	return true;
}
/*
* Checks if _data is lexicographically inequal to the other Vector.
*/
bool operator!=(const Vector& l, const Vector& r)
{
	return !(l == r);
}
/*
* Print the vector to the ostream
*/
std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	for (size_t i = 0; i < v.size(); i++)
		os << v[i] << " ";
	return os;
}
