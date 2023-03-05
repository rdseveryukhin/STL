#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>  

#include <vector>
#include "TestClass.h"
#include "Vector.h"

Vector<int> create() {
	return Vector<int> (8, 8);
}

int main() {

	{
		/*auto assign_val = 5;
		auto push_val = 10;
		auto emplaceback_val = 9;
		auto insert_val = 11;
		auto emplace_val = 21;*/
		/*auto assign_val = "five";
		auto push_val = "ten";
		auto emplaceback_val = "nine";
		auto insert_val = "eleven";
		auto emplace_val = "twenty one";*/
		auto assign_val = TestClass(5);
		auto push_val = TestClass(10);
		auto emplaceback_val = TestClass(9);
		auto insert_val = TestClass(11);
		auto emplace_val = TestClass(21);

		//std::vector<int> c(7,7);
		//std::vector<int> a = { 1, 2, 3, 4, 5 };
		//std::vector<int> a(c.end(), c.begin());
		//std::vector<int> a;
		//std::vector<std::string> c;
		//std::vector<std::string> a;
		std::vector<TestClass> c;
		std::vector<TestClass> a;



		std::cout << "TYPES" << std::endl;
		std::cout << "class type a: " << typeid(decltype(a)).name() << std::endl;
		std::cout << "value type a: " << typeid(decltype(a)::value_type).name() << std::endl;
		std::cout << "data type a: " << typeid(a.data()).name() << std::endl;
		std::cout << "iter type a: " << typeid(decltype(a)::iterator).name() << std::endl;
		std::cout << "const_iter type a: " << typeid(decltype(a)::const_iterator).name() << std::endl;
		std::cout << "reverse_iter type a: " << typeid(a.rbegin()).name() << std::endl;
		std::cout << "reverse_const_iter type a: " << typeid(a.crbegin()).name() << std::endl;
		std::cout << "iter category a: " << typeid(std::iterator_traits<decltype(a)::iterator>::iterator_category).name() << std::endl;
		std::cout << std::endl;

		std::cout << "ELEMS" << std::endl;
		if (a.size() > 0) {
			std::cout << "first elem: " << a[0] << std::endl;
			std::cout << "elem at: " << a.at(a.size() - 1) << std::endl;
		}
		std::cout << "std::vector: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;

		std::cout << "DATA()" << std::endl;
		if (a.data() == nullptr) {
			std::cout << "a is nullptr" << std::endl;
		}
		else {
			std::cout << "a.data: " << a.data() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "SIZE()" << std::endl;
		std::cout << "capacity a: " << a.capacity() << std::endl;
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

		std::cout << "ASSIGN()" << std::endl;
		a.assign(5, assign_val);
		std::cout << "after assign: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "SWAP()" << std::endl;
		a.swap(c);
		std::cout << "after swap: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << std::endl;

		std::cout << "PUSH_BACK()" << std::endl;
		a.push_back(push_val);
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "a after push_back: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "POP_BACK()" << std::endl;
		a.pop_back();
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "a after pop_back: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "RESERVE()" << std::endl;
		a.reserve(20);
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << std::endl;

		std::cout << "SHRINK_TO_FIT()" << std::endl;
		a.shrink_to_fit();
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << std::endl;

		std::cout << "RESIZE()" << std::endl;
		a.resize(10);
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "EMPLACE_BACK()" << std::endl;
		a.emplace_back(emplaceback_val);
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "ERASE()" << std::endl;
		auto itx = a.erase(a.begin() + 7, a.begin() + 10);
		std::cout << "return iter: " << *itx << std::endl;
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "INSERT()" << std::endl;
		auto it = a.insert(a.begin(), insert_val);
		std::cout << "return iter: " << *it << std::endl;
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after insert: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "EMPLACE()" << std::endl;
		auto it2 = a.emplace(a.begin() + 2, emplace_val);
		std::cout << "return iter: " << *it2 << std::endl;
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after emplace: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "CLEAR()" << std::endl;
		a.clear();
		std::cout << "capacity a: " << a.capacity() << std::endl;
		std::cout << "size a: " << a.size() << std::endl;
		std::cout << "after clear: ";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		
		


		std::cout << std::endl;
		std::cout << std::endl;





		
		//Vector
		//Vector<int> d(7, 7);
		//Vector<int> d;
		//Vector<int> b = std::move(create());
		//b = d;
		//Vector<int> b{ 1, 2, 3, 4, 5 };
		//Vector<int> b;
		//Vector<std::string> d;
		//Vector<std::string> b;
		Vector<TestClass> d;
		Vector<TestClass> b;

		std::cout << "TYPES" << std::endl;
		std::cout << "class type b: " << typeid(decltype(b)).name() << std::endl;
		std::cout << "value type b: " << typeid(decltype(b)::value_type).name() << std::endl;
		std::cout << "data type b: " << typeid(b.data()).name() << std::endl;
		std::cout << "iter type b: " << typeid(decltype(b)::iterator).name() << std::endl;
		//std::cout << "const_iter type b: " << typeid(decltype(b)::const_iterator).name() << std::endl;
		std::cout << "reverse_iter type b: " << typeid(b.rbegin()).name() << std::endl;
		//std::cout << "reverse_const_iter type b: " << typeid(b.crbegin()).name() << std::endl;
		std::cout << "iter category b: " << typeid(std::iterator_traits<decltype(b)::iterator>::iterator_category).name() << std::endl;
		std::cout << std::endl;

		std::cout << "ELEMS" << std::endl;
		if (b.size() > 0) {
			std::cout << "first elem: " << b[0] << std::endl;
			std::cout << "b at: " << b.at(b.size() - 1) << std::endl;
		}
		std::cout << "Vector: ";
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
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << std::endl;

		std::cout << "EMPTY()" << std::endl;
		std::cout << "empty b: " << b.empty() << std::endl;
		std::cout << std::endl;

		if (b.begin() == b.end()) {
			std::cout << "BEGIN = END" << std::endl;
			std::cout << std::endl;
		}
		else {
			std::cout << "BEGIN()" << std::endl;
			std::cout << "begin b: " << *(b.begin()) << std::endl;
		//	std::cout << "cbegin b: " << *(b.cbegin()) << std::endl;
			std::cout << "rbegin b: " << *(b.rbegin()) << std::endl;
		//	std::cout << "crbegin b: " << *(b.crbegin()) << std::endl;
			std::cout << std::endl;

			std::cout << "END()" << std::endl;
			std::cout << "end b: " << *(b.end() - 1) << std::endl;
		//	std::cout << "cend b: " << *(b.cend() - 1) << std::endl;
			std::cout << "rend b: " << *(b.rend() - 1) << std::endl;
		//	std::cout << "crend b: " << *(b.crend() - 1) << std::endl;
			std::cout << std::endl;
		}

		std::cout << "ASSIGN()" << std::endl;
		b.assign(5, assign_val);
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after assign: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "SWAP()" << std::endl;
		b.swap(d);
		std::cout << "after swap: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "PUSH_BACK()" << std::endl;
		b.push_back(push_val);
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "a after push_back: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "POP_BACK()" << std::endl;
		b.pop_back();
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "b after pop_back: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "RESERVE()" << std::endl;
		b.reserve(20);
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << std::endl;

		std::cout << "SHRINK_TO_FIT()" << std::endl;
		b.shrink_to_fit();
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << std::endl;

		std::cout << "RESIZE()" << std::endl;
		b.resize(10);
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "EMPLACE_BACK()" << std::endl;
		b.emplace_back(emplaceback_val);
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "ERASE()" << std::endl;
		auto itxx = b.erase(b.begin() + 7, b.begin() + 10);
		std::cout << "return iter: " << *itxx << std::endl;
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after resize: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "INSERT()" << std::endl;
		auto it1 = b.insert(b.begin(), insert_val);
		std::cout << "return iter: " << *it1 << std::endl;
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after insert: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "EMPLACE()" << std::endl;
		auto it3 = b.emplace(b.begin() + 2, emplace_val);
		std::cout << "return iter: " << *it3 << std::endl;
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after emplace: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "CLEAR()" << std::endl;
		b.clear();
		std::cout << "capacity b: " << b.capacity() << std::endl;
		std::cout << "size b: " << b.size() << std::endl;
		std::cout << "after clear: ";
		for (int i = 0; i < b.size(); i++) {
			std::cout << b.data()[i] << ' ';
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	if (_CrtDumpMemoryLeaks()) {
		std::cout << "Leak detected!" << std::endl;
	}
	else {
		std::cout << "Leak NOT detected!" << std::endl;
	}
}
