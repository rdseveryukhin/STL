#include <cassert>
#include<algorithm>
#include <stdexcept>

template<class T, size_t N>
class Array {

public:
    //types
    using value_type = T;
    using iterator = std::_Array_iterator<T, N>;
    using const_iterator = std::_Array_const_iterator<T, N>;


    //field:
    value_type elems[N == 0 ? 1 : N];

    // default constructor
    Array() = default;

    //constructor for elements initialization 
    template<typename... Args>
    Array(Args... args) {
        static_assert(sizeof...(args) <= sizeof(elems)/sizeof(elems[0]), "Wrong number of arguments");
        init(0, args...);
    }

    //operator []    
    constexpr const T& operator [] (size_t Pos) const { return elems[Pos]; }

    T& at(size_t Pos) { return Pos >= 0 && Pos < N ? elems[Pos] : throw std::out_of_range("invalid array<T, N> subscript"); }

    //methods
    const T* data() const { return N == 0 ? nullptr : &elems[0]; }

    constexpr size_t size() const { return N; }

    constexpr bool empty() const { return N == 0 ? true : false; }

    void fill(const T& value) { std::fill(begin(), end(), value); }

    void swap(Array& other) { std::swap(elems, other.elems); }

    iterator begin() { return iterator(elems, 0); }

    iterator end() { return iterator(elems, N); }

    const_iterator cbegin() const { return const_iterator(elems, 0); }

    const_iterator cend() const { return const_iterator(elems, N); }

    std::reverse_iterator<iterator> rbegin() { return std::reverse_iterator<iterator>(end()); }

    std::reverse_iterator<iterator> rend() { return std::reverse_iterator<iterator>(begin()); }

    std::reverse_iterator<const_iterator> crbegin() const { return std::reverse_iterator<const_iterator>(cend()); }

    std::reverse_iterator<const_iterator> crend() const { return std::reverse_iterator<const_iterator>(cbegin()); }


private:
    //initialization elements with recursion
    template<typename U, typename... Args>
    void init(size_t i, U arg, Args... args) {
        elems[i] = arg;
        init(++i, args...);
    }

    //recursion base
    void init(size_t i) {
        if (i <= (sizeof(elems) / sizeof(elems[0]) - 1)) {
            elems[i] = T();
            init(++i);
        }
    }
};