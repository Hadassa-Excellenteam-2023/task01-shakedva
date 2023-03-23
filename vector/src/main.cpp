#include <iostream>
#include <Vector.h>
#include <vector>
#include <algorithm>

int main()
{
	Vector v1 = Vector(5, 1);
	Vector v2 = Vector(2, 2);
	Vector v3 = Vector(4);
	Vector v4 = Vector();
	Vector v5 = v2; // copy ctor

	std::cout << "v1: " << v1 <<std::endl;
	std::cout << "v2: " << v2 <<std::endl;
	std::cout << "v3: " << v3 <<std::endl;
	std::cout << "v4: " << v4 <<std::endl;
	std::cout << "copy ctor: Vector v5 = v2: v5: " << v5 <<std::endl;

	v5 = v3; // copy assignment operator
	std::cout << "copy assignment: v5 = v3: v5: " << v5 << std::endl;

	Vector v6 = (std::move(v2)); // move ctor
	v4 = (std::move(v3)); // move assignment operator

	std::cout << "move ctor: v6 <- v2: v6: " << v6 << "  v2: " << v2 << std::endl;
	std::cout << "move assignment: v4 <- v3: v4: " << v4 << " v3: " << v3 << std::endl;


	std::cout << "--------------------------------------------------------------\n";

	std::cout << "v6 size(): " << v6.size() << " capacity(): " << v6.capacity() << '\n';
	std::cout << "v6.resize(10)\n";
	v6.resize(10);
	std::cout << "v6 size(): " << v6.size() << " capacity(): " << v6.capacity() << '\n';

	std::cout << "--------------------------------------------------------------\n";
	std::cout << "v1.empty() returns: " << v1.empty() << "\nv3.empty() returns: " << v3.empty() << '\n';
	std::cout << "--------------------------------------------------------------\n";

	std::cout << "v4 int& operator[]: " << v4;
	v4[1] = 1;
	v4[2] = 2;
	v4[3] = 3;
	std::cout << " ---> " << v4 << std::endl;
	std::cout << "v4 operator[] const: " << v4[0] << " " << v4[1] << " " << v4[2] << " " << v4[3] << "\n";

	std::cout << "--------------------------------------------------------------\n";
	
	std::cout << "push back(4): " << v5;
	v5.push_back(4);
	std::cout << " ---> " << v5 << std::endl;

	std::cout << "insert(2, 8): " << v5;
	v5.insert(2, 8);
	std::cout << " ---> " << v5 << std::endl;

	std::cout << "swap(v1, v5): v1: " << v1 << " v5: " << v5;
	v1.swap(v5);
	std::cout << " --->  v1: " << v1 << " v5: " << v5 << std::endl;

	std::cout << "pop back: " << v1;
	v1.pop_back();
	std::cout << " ---> " << v1 << std::endl;

	std::cout << "clear(): " << v1;
	v1.clear();
	std::cout << " ---> " << v1 << std::endl;

	std::cout << "--------------------------------------------------------------\n";
	std::cout << "v5 " << v5 << std::endl;
	std::cout << "v6 " << v6 << std::endl;
	std::cout << "v5 == v6 returns " << (v5 == v6) << '\n';
	std::cout << "v5 != v6 returns " << (v5 != v6) << '\n';
	std::cout << "v5 >= v6 returns " << (v5 >= v6) << '\n';
	std::cout << "v5 > v6 returns " << (v5 > v6) << '\n';
	std::cout << "v5 <= v6 returns " << (v5 <= v6) << '\n';
	std::cout << "v5 < v6 returns " << (v5 < v6) << '\n';
	std::cout << "--------------------------------------------------------------\n";
	v3 = v6;
	std::cout << "v3 " << v3 << std::endl;
	std::cout << "v6 " << v6 << std::endl;
	std::cout << "v3 == v6 returns " << (v3 == v6) << '\n';
	std::cout << "v3 != v6 returns " << (v3 != v6) << '\n';
	std::cout << "v3 >= v6 returns " << (v3 >= v6) << '\n';
	std::cout << "v3 > v6 returns " << (v3 > v6) << '\n';
	std::cout << "v3 <= v6 returns " << (v3 <= v6) << '\n';
	std::cout << "v3 < v6 returns " << (v3 < v6) << '\n';
	std::cout << "--------------------------------------------------------------\n";

	return 0;
}