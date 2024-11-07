// Pentagon.h
#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include "Point.h"
#include "Array.h"
#include <cmath>
#include <iostream>

template <Arithmetic T>
class Pentagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1{nullptr};
    std::unique_ptr<Point<T>> p2{nullptr};
    std::unique_ptr<Point<T>> p3{nullptr};
    std::unique_ptr<Point<T>> p4{nullptr};
    std::unique_ptr<Point<T>> p5{nullptr};
public:
    
    Pentagon(){}
    Pentagon(const Point<T>& pn1, const Point<T>& pn2, const Point<T>& pn3, const Point<T>& pn4, const Point<T>& pn5){
        p1 = std::make_unique<Point<T>>(pn1);
        p2 = std::make_unique<Point<T>>(pn2);
        p3 = std::make_unique<Point<T>>(pn3);
        p4 = std::make_unique<Point<T>>(pn4);
        p5 = std::make_unique<Point<T>>(pn5);
    }
    Pentagon(const Pentagon<T>& other){
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
        p5 = std::make_unique<Point<T>>(*other.p5);
    };
    
    Pentagon(Pentagon<T>&& other){
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
        p5 = std::move(other.p5);
    };

    Pentagon<T>& operator=(const Pentagon<T>& other){
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
        *p5 = *other.p5;
        return *this;
    };
    Pentagon<T>& operator=(Pentagon<T>&& other){
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
        p5 = std::move(other.p5);
        return *this;
    };

    Point<T> Center_of_figure() const override {
        Point<T> mid = (*p1 + *p2 + *p3 + *p4 + *p5) * (1.0 / 5.0);
        return mid;
    }

    operator double() const {
    double area = 0.0;
    area += p1->x * p2->y - p1->y * p2->x;
    area += p2->x * p3->y - p2->y * p3->x;
    area += p3->x * p4->y - p3->y * p4->x;
    area += p4->x * p5->y - p4->y * p5->x;
    area += p5->x * p1->y - p5->y * p1->x;
    return std::abs(area) / 2.0;
}

    
    bool operator== (const Pentagon &other) const {
            return *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4 && *p5 == *other.p5;
    }  
    
    std::ostream& print(std::ostream& out) const override {
    out << "Pentagon Points:" << std::endl;
    out << "P1: " << *p1 << std::endl;
    out << "P2: " << *p2 << std::endl;
    out << "P3: " << *p3 << std::endl;
    out << "P4: " << *p4 << std::endl;
    out << "P5: " << *p5 << std::endl;
    return out;
}


    std::istream& input(std::istream& in) override {
        std::cout << "Введите координаты пятиугольника:" << std::endl;
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

        std::cout << "P5 (x y): ";
        in >> x >> y;
        p5 = std::make_unique<Point<T>>(x, y);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pentagon<T>& pentagon) {
        pentagon.print(out);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Pentagon<T>& pentagon) {
        pentagon.input(in);
        return in;
    }
};


#endif // PENTAGON_H
