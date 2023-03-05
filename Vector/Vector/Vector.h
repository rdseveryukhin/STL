#include <initializer_list>
#include<memory>
#include <string>
#include "Iterator.h"

template <typename T, typename A = std::allocator<T>>
class Vector {

public:

	//types
	using value_type = T;
	using iterator = Vector_iterator<T>;
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;

	//ctors
	Vector() : _size(0), _capacity(0), _data(nullptr) {}

	Vector(size_t count, T defVal = T()) : _size(count), _capacity(count) {
		_data = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++) {
			_data[i] = defVal;
		}
	}

	Vector(const std::initializer_list<T> &init) {
		_capacity = init.size();
		_size = init.size();
		_data = _alloc.allocate(_capacity);
		size_t index = 0;
		for (auto& elem : init) {
			_data[index++] = elem;
		}
	}

	Vector(const iterator begin, const iterator end) {
		if (begin > end) throw std::out_of_range("Vector iterator range transposed");
		_capacity = end - begin;
		_size = end - begin;
		_data = _alloc.allocate(_capacity);
		size_t index = 0;
		for (auto it = begin; it < end; it++) {
			_data[index++] = *it;
		}
	}

	Vector(const Vector &other) {
		_capacity = other._capacity;
		_size = other._size;
		_data = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++) {
			_data[i] = other._data[i];
		}
	}

	Vector(Vector&& other) {
		_capacity = other._capacity;
		_size = other._size;
		_data = other._data;
		other._capacity = 0;
		other._size = 0;
		other._data = nullptr;
	}

	//destructor
	~Vector() {
		for (size_t i = 0; i < _size; i++) {
			_data[i].~T();
		}
		_alloc.deallocate(_data, _capacity);
	}

	//operators
	Vector& operator = (const Vector& other) {
		if (this != &other) {
			_alloc.deallocate(_data, _capacity);
			_capacity = other._capacity;
			_size = other._size;
			_data = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++) {
				_data[i] = other._data[i];
			}
		}
		return *this;
	}

	Vector& operator = (Vector&& other) {
		if (this != &other) {
			_alloc.deallocate(_data, _capacity);
			_capacity = other._capacity;
			_size = other._size;
			_data = other._data;
			other._capacity = 0;
			other._size = 0;
			other._data = nullptr;
		}
		return *this;
	}

	reference operator [] (size_t Pos) { return _data[Pos]; }

	const_reference operator [] (size_t Pos) const { return _data[Pos];}

	reference at(size_t Pos) { return Pos >= 0 && Pos < _size ? _data[Pos] : throw std::out_of_range("invalid Vector<T> subscript"); }

	//methods
	iterator begin() { return iterator(_data); }

	iterator end() { return iterator(&_data[_size]); }

	std::reverse_iterator<iterator> rbegin() { return std::reverse_iterator<iterator>(end()); }

	std::reverse_iterator<iterator> rend() { return std::reverse_iterator<iterator>(begin()); }

	size_t size() const { return _size;}

	size_t capacity() const { return _capacity; }

	pointer data() { return _data;}

	constexpr bool empty() const { return _size == 0 ? true : false; }
	
	void assign(size_t count, T defVal = T()) {
		this->~Vector();
		_capacity = count;
		_size = count;
		_data = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++) {
			new (_data + i) T{};
			_data[i] = defVal;
		}
	}

	void swap(Vector& other) { std::swap(*this, other); }

	void reserve(size_t new_capacity) {
		if (new_capacity != _capacity)
		{
			A new_alloc;
			T* new_data = new_alloc.allocate(new_capacity);
			for (size_t i = 0; i < _size; i++)
			{
				new (new_data + i) T{};
				new_data[i] = _data[i];
			}
			this->~Vector();
			_alloc = new_alloc;
			_data = new_data;
			_capacity = new_capacity;
		}
	}

	void shrink_to_fit() { 
		reserve(_size);
	}

	void push_back(const T& val) {
		if (_capacity == _size) {
			reserve(_capacity < 2 ? 2 : _capacity + _capacity / 2);
		}
		new (_data + _size) T{};
		_data[_size++] = val;
	}

	void pop_back() { 
		_data[_size - 1].~T();
		_size--; 
	}

	void clear() { 
		for (size_t i = 0; i < _size; i++) {
			_data[i].~T();
		}
		_size = 0; 
	}

	void resize(size_t new_size) {
		if (new_size > _size) {
			if (new_size > _capacity) {
				reserve(new_size);
				for (size_t i = _size; i < _capacity; i++) {
					new (_data + i) T{};
				}
				_size = _capacity;
			}
			else {
				for (size_t i = _size; i < new_size; i++) {
					new (_data + i) T{};
				}
				_size = new_size;
			}
		}
		else {
			for (size_t i = _size - 1; i >= new_size; i--) {
				_data[i].~T();
				if (i == 0) break;
			}
			_size = new_size;
		}
	}

	template <class ValT>
	decltype(auto) emplace_back(ValT&& val) {  
		if (_capacity == _size) {
			reserve(_capacity < 2 ? 2 : _capacity + _capacity / 2);
		}
		new (_data + _size) T{};
		_data[_size++] = T(val);
	}

	iterator erase(iterator begin, iterator end) {
		if (begin > end) throw std::out_of_range("Vector erase iterator outside range");
		for (auto it1 = begin, it2 = end; it2 < this->end(); it1++, it2++) {
			*it1 = *it2;
		}
		for (size_t i = _size - 1; i >= _size - (end - begin); i--) {
			_data[i].~T();
			if (i == 0) break;
		}
		_size -= end - begin;
		return begin;
	}

	iterator insert(iterator pos, const T& val) {
		if (pos > end()) throw std::out_of_range("cannot seek iterator after end");
		size_t index = pos - _data;
		if (_size == _capacity) {
			reserve(_capacity < 2 ? 2 : _capacity + _capacity / 2);
		}
		new (_data + _size) T{};
		for (auto i = _size - 1; i >= index; i--) {
			_data[i + 1] = _data[i];
			if (i == 0) break;
		}
		_data[index] = val;
		++_size;
		return iterator(&_data[index]);
	}

	template <class ValT>
	iterator emplace(iterator pos, ValT&& val) {
		if (pos > end()) throw std::out_of_range("cannot seek iterator after end");
		size_t index = pos - _data;
		if (_size == _capacity) {
			reserve(_capacity < 2 ? 2 : _capacity + _capacity / 2);
		}
		new (_data + _size) T{};
		for (auto i = _size - 1; i >= index; i--) {
			_data[i + 1] = std::move(_data[i]);
			if (i == 0) break;
		}
		_data[index] = T(val);
		++_size;
		return iterator(&_data[index]);
	}

private:

	//fields
	size_t _size;
	size_t _capacity;
	T* _data;
	A _alloc;
};