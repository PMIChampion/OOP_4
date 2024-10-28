#ifndef POINT_H
#define POINT_H

#include <concepts>
#include <iostream>
#include "Concepts.h"

template <Arithmetic T>
class Point {
public:
    T x;
    T y;

    Point() : x{0}, y{0} {}
    Point(T x_val = 0, T y_val = 0) : x(x_val), y(y_val) {}
    Point(const Point<T>& other) : x(other.x), y(other.y) {}
    Point(Point<T>&& other) noexcept : x(std::move(other.x)), y(std::move(other.y)) {}

    Point<T>& operator=(const Point<T>& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Point<T>& operator=(Point<T>&& other) noexcept {
        if (this != &other) {
            x = std::move(other.x);
            y = std::move(other.y);
        }
        return *this;
    }

    bool operator==(const Point<T>& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point<T>& other) const {
        return !(*this == other);
    }
    Point<T> operator+(const Point<T>& other) const {
    return Point<T>(x + other.x, y + other.y);
    }
    Point<T> operator-(const Point<T>& other) const {
        return Point<T>(x - other.x, y - other.y);
    }

    Point<T> operator*(double scalar) const {
        return Point<T>(x * scalar, y * scalar);
    }
    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }
    friend std::ostream& operator<<(std::ostream& out, const Point<T>& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Point<T>& p) {
        in >> p.x >> p.y;
        return in;
    }
};

#endif // POINT_H
