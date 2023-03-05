#include <iterator>

template <class T>
class Vector_iterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
	//types
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::random_access_iterator_tag;

	//ctors
	Vector_iterator() : ptr(nullptr) {}

	Vector_iterator(T* data) : ptr(data) {}

	Vector_iterator(const Vector_iterator& other) : ptr(other.ptr) {}

	~Vector_iterator() = default;

	Vector_iterator& operator = (const Vector_iterator& other) {
		ptr = other.ptr;
		return *this;
	}

	//opers
	reference operator*() const { return *ptr; }

	pointer operator->() const { return ptr; }

	reference operator[](difference_type n) const { return *(ptr + n); }

	//opers arithmetic
	friend Vector_iterator operator-(const Vector_iterator& it, difference_type n) {
		return Vector_iterator(it.ptr - n);
	}

	friend Vector_iterator operator+(const Vector_iterator& it, difference_type n) {
		return Vector_iterator(it.ptr + n);
	}

	difference_type operator - (const Vector_iterator& other) const { return ptr - other.ptr; }

	Vector_iterator& operator++() {
		++ptr;
		return *this;
	}

	Vector_iterator& operator++(int) {
		auto tmp = *this;
		++(*this);
		return tmp;
	}

	Vector_iterator& operator--() {
		--ptr;
		return *this;
	}

	Vector_iterator& operator--(int) {
		auto tmp = *this;
		--(*this);
		return tmp;
	}

	Vector_iterator& operator+=(difference_type n) {
		ptr += n;
		return *this;
	}

	Vector_iterator& operator-=(difference_type n) {
		ptr -= n;
		return *this;
	}

	//opers comparison
	bool operator == (const Vector_iterator& other) { return ptr == other.ptr; }

	bool operator != (const Vector_iterator& other) { return ptr != other.ptr; }

	bool operator < (const Vector_iterator& other) { return ptr < other.ptr; }

	bool operator > (const Vector_iterator& other) { return ptr > other.ptr; }

	bool operator <= (const Vector_iterator& other) { return ptr <= other.ptr; }

	bool operator >= (const Vector_iterator& other) { return ptr >= other.ptr; }

private:
	pointer ptr;
};
