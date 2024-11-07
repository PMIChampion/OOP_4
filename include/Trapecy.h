// Trapecy.h
#ifndef TRAPECY_H
#define TRAPECY_H

#include "Figure.h"
#include "Point.h"
#include <cmath>
#include <iostream>
#include <memory>

template <Arithmetic T>
class Trapecy : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1;
    std::unique_ptr<Point<T>> p2;
    std::unique_ptr<Point<T>> p3;
    std::unique_ptr<Point<T>> p4;

public:
    // Конструкторы
    Trapecy(){}
    Trapecy(const Point<T>& pn1, const Point<T>& pn2, const Point<T>& pn3, const Point<T>& pn4) {
        p1 = std::make_unique<Point<T>>(pn1);
        p2 = std::make_unique<Point<T>>(pn2);
        p3 = std::make_unique<Point<T>>(pn3);
        p4 = std::make_unique<Point<T>>(pn4);
    }

    Trapecy(const Trapecy<T>& other) {
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
    }

    Trapecy(Trapecy<T>&& other) noexcept {
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
    }

    // Операторы присваивания
    Trapecy<T>& operator=(const Trapecy<T>& other) {
        if (this == &other) return *this;
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
        return *this;
    }

    Trapecy<T>& operator=(Trapecy<T>&& other) noexcept {
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

    

    operator double() const{
    double area = 0.0;
    area += p1->x * p2->y - p1->y * p2->x;
    area += p2->x * p3->y - p2->y * p3->x;
    area += p3->x * p4->y - p3->y * p4->x;
    area += p4->x * p1->y - p4->y * p1->x;
    return std::abs(area) / 2.0;
}

    bool operator==(const Trapecy<T>& other) const {
        return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4;
    }

    std::ostream& print(std::ostream& out) const override {
        out << "Trapecy Points:" << std::endl;
        out << "P1: " << *p1 << std::endl;
        out << "P2: " << *p2 << std::endl;
        out << "P3: " << *p3 << std::endl;
        out << "P4: " << *p4 << std::endl;
        return out;
    }

    std::istream& input(std::istream& in) override {
        std::cout << "Введите координаты трапеции:" << std::endl;
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

    friend std::ostream& operator<<(std::ostream& out, const Trapecy<T>& trapecy) {
        trapecy.print(out);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Trapecy<T>& trapecy) {
        trapecy.input(in);
        return in;
    }
};



#endif // TRAPECY_H
