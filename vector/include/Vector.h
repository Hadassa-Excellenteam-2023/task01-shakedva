#pragma once
#include <iostream>

class Vector
{
public:
	Vector(size_t size = 0, int value = 0);
	Vector(const Vector&); // copy c-tor
	~Vector();

	size_t size();
	size_t capacity();
	bool empty();
	int* data();
	void clear();
	void print();
	void swap(Vector&);
	void resize(size_t);
	void push_back(const int&);
	void pop_back();
	Vector& operator=(const Vector&);
	int& operator[](size_t);
	int operator[](size_t) const;
private:
	bool isInRange(size_t) const;
	size_t _size;
	size_t _capacity;
	int* _data;
};