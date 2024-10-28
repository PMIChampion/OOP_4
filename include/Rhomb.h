#ifndef RHOMB_H
#define RHOMB_H

#include "Figure.h"
#include "Point.h"
#include <cmath>
#include <iostream>
#include <memory>

template <Arithmetic T>
class Rhomb : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1;
    std::unique_ptr<Point<T>> p2;
    std::unique_ptr<Point<T>> p3;
    std::unique_ptr<Point<T>> p4;

public:
    // Конструкторы
    Rhomb(){}
    Rhomb(const Point<T>& pn1, const Point<T>& pn2, const Point<T>& pn3, const Point<T>& pn4) {
        p1 = std::make_unique<Point<T>>(pn1);
        p2 = std::make_unique<Point<T>>(pn2);
        p3 = std::make_unique<Point<T>>(pn3);
        p4 = std::make_unique<Point<T>>(pn4);
    }

    Rhomb(const Rhomb<T>& other) {
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
    }

    Rhomb(Rhomb<T>&& other) noexcept {
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
    }

    // Операторы присваивания
    Rhomb<T>& operator=(const Rhomb<T>& other) {
        if (this == &other) return *this;
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
        return *this;
    }

    Rhomb<T>& operator=(Rhomb<T>&& other) noexcept {
        if (this == &other) return *this;
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
        return *this;
    }

    // Методы
    Point<T> Center_of_figure() const override {
        Point<T> mid = (*p1 + *p2 + *p3 + *p4) * (1.0 / 4.0);
        return mid;
    }

    operator double() const {
        Point<T> diag1 = *p3 - *p1; // Диагональ p1p3
        Point<T> diag2 = *p4 - *p2; // Диагональ p2p4

        double d1 = diag1.magnitude();
        double d2 = diag2.magnitude();


        double area = (d1 * d2) / 2.0;
        return area;
    }

    bool operator==(const Rhomb<T>& other) const {
        return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4;
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Rhomb Points:" << std::endl;
        out << "P1: " << *p1 << std::endl;
        out << "P2: " << *p2 << std::endl;
        out << "P3: " << *p3 << std::endl;
        out << "P4: " << *p4 << std::endl;
        return out;
    }

    std::istream& input(std::istream& in) override {
        std::cout << "Введите координаты ромба:" << std::endl;
        T x, y;

        std::cout << "P1 (x y): ";
        in >> x >> y;
        p1 = std::make_unique<Point<T>>(x, y);

        std::cout << "P2 (x y): ";
        in >> x >> y;
        p2 = std::make_unique<Point<T>>(x, y);

        std::cout << "P3 (x y): ";
        in >> x >> y;
        p3 = std::make_unique<Point<T>>(x, y);

        std::cout << "P4 (x y): ";
        in >> x >> y;
        p4 = std::make_unique<Point<T>>(x, y);
        return in;

    }

    friend std::ostream& operator<<(std::ostream& out, const Rhomb<T>& Rhomb) {
        Rhomb.print(out);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Rhomb<T>& Rhomb) {
        Rhomb.input(in);
        return in;
    }
};

#endif // RHOMB_H

