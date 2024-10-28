// main.cpp
#include <iostream>
#include "Array.h"
#include "Point.h"
#include "Pentagon.h"
#include "Rhomb.h"
#include "Trapecy.h"

int main() {
    try {
        // Пример использования Array<int> и метода sum()
        Array<int> intArray;
        intArray.push_back(10);
        intArray.push_back(20);
        intArray.push_back(30);

        std::cout << "Элементы intArray: ";
        for (const auto& elem : intArray) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;


        // Создание пятиугольника и работа с ним
        Pentagon<double> pentagon(
            Point<double>(0, 0),
            Point<double>(2, 0),
            Point<double>(3, 2),
            Point<double>(1, 3),
            Point<double>(-1, 2)
        );

        std::cout << "Информация о пятиугольнике:" << std::endl;
        pentagon.print(std::cout);
        std::cout << "Центр пятиугольника: " << pentagon.Center_of_figure() << std::endl << std::endl;

        // Создание ромба и работа с ним
        Rhomb<double> rhombus(
            Point<double>(0, 0),
            Point<double>(2, 2),
            Point<double>(4, 0),
            Point<double>(2, -2)
        );

        std::cout << "Информация о ромбе:" << std::endl;
        rhombus.print(std::cout);
        std::cout << "Центр ромба: " << rhombus.Center_of_figure() << std::endl << std::endl;

        // Создание трапеции и работа с ней
        Trapecy<double> trapecy(
            Point<double>(0, 0),
            Point<double>(4, 0),
            Point<double>(3, 2),
            Point<double>(1, 2)
        );

        std::cout << "Информация о трапеции:" << std::endl;
        trapecy.print(std::cout);
        std::cout << "Центр трапеции: " << trapecy.Center_of_figure() << std::endl << std::endl;

        // Создание массива фигур и вычисление общей площади
        Array<Figure<double>*> figures;
        figures.push_back(&pentagon);
        figures.push_back(&rhombus);
        figures.push_back(&trapecy);


        // Ввод фигуры с клавиатуры
        Rhomb<double> rhombusInput;
        std::cout << "Введите координаты вершин ромба:" << std::endl;
        rhombusInput.input(std::cin);
        std::cout << "Информация о введённом ромбе:" << std::endl;
        rhombusInput.print(std::cout);
        std::cout << "Центр введённого ромба: " << rhombusInput.Center_of_figure() << std::endl << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}

