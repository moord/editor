#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

// Примитив треугольник
class Triangle : public Shape
{
public:
    constexpr static char shapeName[]{"TRIANGLE"};                     // идентификатор фигуры линия

    Triangle(){};
    Triangle( Point _first, Point _second, Point _third): coords{_first, _second,_third}{};

    static Triangle * Create ();

    void Draw();

    void Move(double x, double y);
    bool IsBelong(Point coord);
    void Zoom(double scale);

    void Load(std::istream& is);
    void Save (std::ostream& os);

    void SetFirstPos(Point);
    void SetSecondPos(Point);
    void SetThirdPos(Point);

protected:
    Point coords[3]; // Атрибут — координаты вершин треугольника
};

#endif // TRIANGLE_H
