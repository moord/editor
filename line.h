#ifndef LINE_H
#define LINE_H

#include "shape.h"

// Примитив линия
class Line : public Shape
{
public:
    constexpr static char shapeName[]{"LINE"};                     // идентификатор фигуры линия

    Line(){};
    Line( Point _start, Point _end ): start(_start), end(_end){};

    static Line * Create ();

    void Draw();

    void Move(double x, double y);
    bool IsBelong(Point coord);
    void Zoom(double scale);

    void Load(std::istream& is);
    void Save (std::ostream& os);

    void SetStartPos(Point _start);
    void SetEndPos(Point _end);

protected:
    Point start, end; // Атрибут — начала и конца
};


#endif // LINE_H
