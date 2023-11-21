#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Примитив круг
class Circle : public Shape
{
public:
    constexpr static char shapeName[]{"CIRCLE"};                     // идентификатор фигуры линия

    Circle(){};
    Circle( Point _start, Point _end );

    static Circle * Create ();

    void Draw();

    void Move(double x, double y);
    bool IsBelong(Point coord);
    void Zoom(double scale);

    void Load(std::istream& is);
    void Save (std::ostream& os);

    void SetCenterPos(Point _center);
    void SetRadius(double _radius);

protected:
    Point center;   // Атрибуты — центра крауга
    double radius;  // и радиуса
};
#endif // CIRCLE_H
