// Figure.h
#ifndef FIGURE_H
#define FIGURE_H

#include "Concepts.h"
#include "Point.h"
#include <memory>
#include <iostream>

template <Arithmetic T>
class Figure {
public:
    virtual std::ostream& print (std::ostream& os) const = 0;
    virtual std::istream& input (std::istream& is) = 0;
    virtual Point<T> Center_of_figure() const = 0;
    virtual ~Figure() = default;
friend std::ostream& operator<< (std::ostream& os, const Figure<T> &figure) {
        return figure.print(os);
    }

friend std::istream& operator>> (std::istream& is, Figure<T> &figure) {
    return figure.input(is);
}
};

#endif // FIGURE_H
