#include <iostream>

class TestClass {
public:
	int data;

	TestClass(int data) : data(data) {};

	TestClass() : data(0) {};

	friend std::ostream& operator<<(std::ostream& os, const TestClass& obj) {
		os << obj.data;
		return os;
	}
};
