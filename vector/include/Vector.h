#pragma once

class Vector
{
public:
	Vector(size_t size = 0, int value = 0);
	Vector(const Vector&);
private:
	size_t _size;
	size_t _capacity;
	int* _data;
};