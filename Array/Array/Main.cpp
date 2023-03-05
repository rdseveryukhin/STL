#include <array>
#include "Array.h"
#include <iterator>
#include "TestClass.h"


int main() {

	//int fill_val = 9;
	//std::string fill_val = "num";
	TestClass fill_val = TestClass(9);

	//std::array
	//std::array<int, 3> c = { 4, 5, 6 };
	//std::array<int, 3> a = { 1, 2, 3 };
	//std::array<std::string, 3> c = { "four", "five", "six"};
	//std::array<std::string, 3> a = { "one", "two", "three" };
	//std::array<std::string, 0> a;
	//std::array<int, 3> a = {};
	//std::array<int, 1> a;
	std::array<TestClass, 3> c = { TestClass(4), TestClass(5), TestClass(6) };
	std::array<TestClass, 3> a = {TestClass(1), TestClass(2), TestClass(3) };


	std::cout << "TYPES" << std::endl;
	std::cout << "class type a: " << typeid(decltype(a)).name() << std::endl;
	std::cout << "value type a: " << typeid(decltype(a)::value_type).name() << std::endl;
	std::cout << "type a elems: " << typeid(decltype(a._Elems)).name() << std::endl;
	std::cout << "iter type a: " << typeid(decltype(a)::iterator).name() << std::endl;
	std::cout << "const_iter type a: " << typeid(decltype(a)::const_iterator).name() << std::endl;
	std::cout << "reverse_iter type a: " << typeid(a.rbegin()).name() << std::endl;
	std::cout << "reverse_const_iter type a: " << typeid(a.crbegin()).name() << std::endl;
	std::cout << "iter category a: " << typeid(std::iterator_traits<decltype(a)::iterator>::iterator_category).name() << std::endl;
	std::cout << std::endl;

	std::cout << "ELEMS" << std::endl;
	std::cout << "first elem: " << a._Elems[0] << std::endl;
	std::cout << "elem at: " << a.at(0) << std::endl;
	std::cout << "std::array: ";
	for (int i = 0; i < a.size(); i++) {
		std::cout << a.data()[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "DATA()" << std::endl;
	if (a.data() == nullptr) {
		std::cout << "a is nullptr" << std::endl;
	}
	else {
		std::cout << "a.data: "<< a.data() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "SIZE()" << std::endl;
	std::cout << "size a: " << a.size() << std::endl;
	std::cout << std::endl;

	std::cout << "EMPTY()" << std::endl;
	std::cout << "empty a: " << a.empty() << std::endl;
	std::cout << std::endl;

	if (a.begin() == a.end()) {
		std::cout << "BEGIN = END" << std::endl;
	}
	else {
		std::cout << "BEGIN()" << std::endl;
		std::cout << "begin a: " << *(a.begin()) << std::endl;
		std::cout << "cbegin a: " << *(a.cbegin()) << std::endl;
		std::cout << "rbegin a: " << *(a.rbegin()) << std::endl;
		std::cout << "cbegin a: " << *(a.crbegin()) << std::endl;
		std::cout << std::endl;

		std::cout << "END()" << std::endl;
		std::cout << "end a: " << *(a.end() - 1) << std::endl;
		std::cout << "cend a: " << *(a.cend() - 1) << std::endl;
		std::cout << "rend a: " << *(a.rend() - 1) << std::endl;
		std::cout << "crend a: " << *(a.crend() - 1) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "SWAP()" << std::endl;
	a.swap(c);
	std::cout << "after swap: ";
	for (int i = 0; i < a.size(); i++) {
		std::cout << a.data()[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "FILL()" << std::endl;
	a.fill(fill_val);
	std::cout << "fill value: " << fill_val << std::endl;
	std::cout << "after fill: ";
	for (int i = 0; i < a.size(); i++) {
		std::cout << a.data()[i] << ' ';
	}
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;
	 

	//Array
	//Array<std::string, 3> d = { "four", "five", "six" };
	//Array<std::string, 3> b = { "one", "two", "three" };
	//Array<std::string, 0> b;
	//Array<int, 3> d = { 4, 5, 6 };
	Array<int, 3> t = { 1, 2, 3 };
	//Array<int, 3> b = {};
	Array<TestClass, 3> d = { TestClass(4), TestClass(5), TestClass(6) };
	Array<TestClass, 3> b = { TestClass(1), TestClass(2), TestClass(3) };

	std::cout << "TYPES" << std::endl;
	std::cout << "class type b: " << typeid(decltype(b)).name() << std::endl;
	std::cout << "value type b: " << typeid(decltype(b)::value_type).name() << std::endl;
	std::cout << "type b elems: " << typeid(decltype(b.elems)).name() << std::endl;
	std::cout << "iter type b: " << typeid(decltype(b)::iterator).name() << std::endl;
	std::cout << "const_iter type b: " << typeid(decltype(b)::const_iterator).name() << std::endl;
	std::cout << "reverse_iter type b: " << typeid(b.rbegin()).name() << std::endl;
	std::cout << "reverse_const_iter type b: " << typeid(b.crbegin()).name() << std::endl;
	std::cout << "iter category b: " << typeid(std::iterator_traits<decltype(b)::iterator>::iterator_category).name() << std::endl;
	std::cout << std::endl;
	
	std::cout << "ELEMS" << std::endl;
	std::cout << "first elem: " << b.elems[0] << std::endl;
	std::cout << "elem at: " << b.at(0) << std::endl;
	std::cout << "Array: ";
	for (int i = 0; i < b.size(); i++) {
		std::cout << b.data()[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "DATA()" << std::endl;
	if (b.data() == nullptr) {
		std::cout << "b is nullptr" << std::endl;
	}
	else {
		std::cout << "b.data: " << b.data() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "SIZE()" << std::endl;
	std::cout << "size b: " << b.size() << std::endl;
	std::cout << std::endl;

	std::cout << "EMPTY()" << std::endl;
	std::cout << "empty b: " << b.empty() << std::endl;
	std::cout << std::endl;

	if (b.begin() == b.end()) {
		std::cout << "BEGIN = END" << std::endl;
	}
	else {
		std::cout << "BEGIN()" << std::endl;
		std::cout << "begin b: " << *(b.begin()) << std::endl;
		std::cout << "cbegin b: " << *(b.cbegin()) << std::endl;
		std::cout << "rbegin b: " << *(b.rbegin()) << std::endl;
		std::cout << "crbegin b: " << *(b.crbegin()) << std::endl;
		std::cout << std::endl;

		std::cout << "END()" << std::endl;
		std::cout << "end b: " << *(b.end() - 1) << std::endl;
		std::cout << "cend b: " << *(b.cend() - 1) << std::endl;
		std::cout << "rend b: " << *(b.rend() - 1) << std::endl;
		std::cout << "crend b: " << *(b.crend() - 1) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "swap()" << std::endl;
	b.swap(d);
	std::cout << "after swap: ";
	for (int i = 0; i < b.size(); i++) {
		std::cout << b.data()[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "FILL()" << std::endl;
	b.fill(fill_val);
	std::cout << "fill value: " << fill_val << std::endl;
	std::cout << "after fill: ";
	for (int i = 0; i < b.size(); i++) {
		std::cout << b.data()[i] << ' ';
	}
	std::cout << std::endl;
}