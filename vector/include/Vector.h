#pragma once
#include <iostream>

class Vector
{
public:
	Vector(size_t size = 0, int value = 0);
	Vector(const Vector&); // copy c-tor
	~Vector();
	Vector& operator=(const Vector&);
	size_t size();
	size_t capacity();
	bool empty();
	int* data();
	void clear();
	void print();
private:
	size_t _size;
	size_t _capacity;
	int* _data;
};