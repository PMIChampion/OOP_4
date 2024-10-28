#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Rhomb.h"
#include "Trapecy.h"
#include "Array.h"
#include "Point.h"

// Тесты для класса Pentagon
TEST(PentagonTest, AreaCalculation) {
    Pentagon<double> pentagon(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(3, 2),
        Point<double>(1, 3),
        Point<double>(-1, 2)
    );
    EXPECT_NEAR(static_cast<double>(pentagon), 6.0, 0.1); // Проверка площади
}

TEST(PentagonTest, CenterCalculation) {
    Pentagon<double> pentagon(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(3, 2),
        Point<double>(1, 3),
        Point<double>(-1, 2)
    );
    Point<double> center = pentagon.Center_of_figure();
    EXPECT_NEAR(center.x, 1.0, 0.1);
    EXPECT_NEAR(center.y, 1.4, 0.1);
}

TEST(RhombTest, AreaCalculation) {
    Rhomb<double> rhombus(
        Point<double>(0, 0),
        Point<double>(2, 2),
        Point<double>(4, 0),
        Point<double>(2, -2)
    );
    EXPECT_NEAR(static_cast<double>(rhombus), 8.0, 0.1); // Проверка площади
}

TEST(RhombTest, CenterCalculation) {
    Rhomb<double> rhombus(
        Point<double>(0, 0),
        Point<double>(2, 2),
        Point<double>(4, 0),
        Point<double>(2, -2)
    );
    Point<double> center = rhombus.Center_of_figure();
    EXPECT_NEAR(center.x, 2.0, 0.1);
    EXPECT_NEAR(center.y, 0.0, 0.1);
}

// Тесты для класса Trapecy
TEST(TrapecyTest, AreaCalculation) {
    Trapecy<double> trapecy(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(3, 2),
        Point<double>(1, 2)
    );
    EXPECT_NEAR(static_cast<double>(trapecy), 8.0, 0.1); 
}

TEST(TrapecyTest, CenterCalculation) {
    Trapecy<double> trapecy(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(3, 2),
        Point<double>(1, 2)
    );
    Point<double> center = trapecy.Center_of_figure();
    EXPECT_NEAR(center.x, 2.0, 0.1);
    EXPECT_NEAR(center.y, 1.0, 0.1);
}

// Тесты для класса Array
TEST(ArrayTest, IntegerArraySum) {
    Array<int> intArray;
    intArray.push_back(10);
    intArray.push_back(20);
    intArray.push_back(30);
}

TEST(ArrayTest, FigureArrayTotalArea) {
    Array<Figure<double>*> figures;
    Pentagon<double> pentagon(
        Point<double>(0, 0),
        Point<double>(2, 0),
        Point<double>(3, 2),
        Point<double>(1, 3),
        Point<double>(-1, 2)
    );
    Rhomb<double> rhombus(
        Point<double>(0, 0),
        Point<double>(2, 2),
        Point<double>(4, 0),
        Point<double>(2, -2)
    );
    Trapecy<double> trapecy(
        Point<double>(0, 0),
        Point<double>(4, 0),
        Point<double>(3, 2),
        Point<double>(1, 2)
    );

    figures.push_back(&pentagon);
    figures.push_back(&rhombus);
    figures.push_back(&trapecy);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
