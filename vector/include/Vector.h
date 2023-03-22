#pragma once
#include <iostream>


class Vector
{
public:
	Vector(size_t size = 0, int value = 0);
	// copy ctor and assignment 
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	// move ctor and assignment 
	Vector(Vector&&);
	Vector& operator=(Vector&&);
	~Vector();
	size_t size() const;
	size_t capacity() const;
	bool empty();
	int* data();
	void clear();
	void print();
	void swap(Vector&);
	void resize(size_t);
	void push_back(const int&);
	void pop_back();
	void erase(size_t);
	void insert(size_t, const int&);
	
	int& operator[](size_t);
	int operator[](size_t) const;
	bool operator>(const Vector&);
	bool operator>=(const Vector&);
	bool operator<(const Vector&);
	bool operator<=(const Vector&);
	
private:
	bool isInRange(size_t) const;
	void addCapacity();
	size_t _size;
	size_t _capacity;
	int* _data;
};

bool operator==(const Vector&, const Vector&);
bool operator!=(const Vector&, const Vector&);
