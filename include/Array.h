#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <class T>
class Array {
public:
    Array();

    explicit Array(size_t size);

    Array(const std::initializer_list<T>& t);

    Array(const Array& other);

    Array(Array&& other) noexcept;

    ~Array() = default;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other) noexcept;

    bool operator==(const Array<T>& other) const;

    T* begin() { return _array.get(); }
    const T* begin() const { return _array.get(); }
    T* end() { return _array.get() + _size; }
    const T* end() const { return _array.get() + _size; }

    size_t size() const;

    void delete_elem(size_t index);

    void push_back(const T& elem);

    double totalArea() const;

    inline double sum() const;

private:
    size_t _size;
    size_t _capacity;
    std::unique_ptr<T[]> _array;

    void resize(size_t new_capacity);
};

template <class T>
inline Array<T>::Array() : _size(0), _capacity(10), _array(std::make_unique<T[]>(_capacity)) {}

template <class T>
inline Array<T>::Array(size_t size) : _size(size), _capacity(size * 2), _array(std::make_unique<T[]>(_capacity)) {}

template <class T>
inline Array<T>::Array(const std::initializer_list<T>& t) : _size(t.size()), _capacity(_size * 2), _array(std::make_unique<T[]>(_capacity)) {
    size_t i = 0;
    for (const auto& elem : t) {
        _array[i++] = elem;
    }
}

template <class T>
inline Array<T>::Array(const Array& other) : _size(other._size), _capacity(other._capacity), _array(std::make_unique<T[]>(_capacity)) {
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

template <class T>
inline Array<T>::Array(Array&& other) noexcept : _size(other._size), _capacity(other._capacity), _array(std::move(other._array)) {
    other._size = 0;
    other._capacity = 0;
}

template <class T>
inline Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        _size = other._size;
        _capacity = other._capacity;
        _array = std::make_unique<T[]>(_capacity);
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <class T>
inline Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        _size = other._size;
        _capacity = other._capacity;
        _array = std::move(other._array);
        other._size = 0;
        other._capacity = 0;
    }
    return *this;
}

template <class T>
inline T& Array<T>::operator[](size_t index) {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return _array[index];
}

template <class T>
inline const T& Array<T>::operator[](size_t index) const {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return _array[index];
}

template <class T>
inline bool Array<T>::operator==(const Array<T>& other) const {
    if (_size != other._size) return false;
    for (size_t i = 0; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
inline size_t Array<T>::size() const {
    return _size;
}

template <class T>
inline void Array<T>::delete_elem(size_t index) {
    if (index >= _size) throw std::out_of_range("Index out of range");
    for (size_t i = index; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_size;
}

template <class T>
inline void Array<T>::push_back(const T& elem) {
    if (_size == _capacity) {
        resize(_capacity * 2);
    }
    _array[_size++] = elem;
}

template <class T>
inline void Array<T>::resize(size_t new_capacity) {
    auto new_array = std::make_unique<T[]>(new_capacity);
    for (size_t i = 0; i < _size; ++i) {
        new_array[i] = _array[i];
    }
    _capacity = new_capacity;
    _array = std::move(new_array);
}

template <class T>
inline double Array<T>::totalArea() const {
    double sm{0.0};
    for (size_t i = 0; i < _size; ++i) {
        sm += static_cast<double>(_array[i]);
    }
    return sm;
}



#endif // ARRAY_H
