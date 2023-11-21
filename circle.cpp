#include "circle.h"
#include <cmath>

static struct CircleFactoryInit{
   CircleFactoryInit(){
       shapeCreators[Circle::shapeName] = Circle::Create;  // автоматическое добавление функции создания класса линии
   }
} _circleCreator;

Circle * Circle::Create (){
    return new Circle();
}

Circle::Circle( Point _start, Point _end ){
    center = _start;
    radius = sqrt((_end.x -_start.x) * (_end.x -_start.x) + (_end.y -_start.y) * (_end.y -_start.y));
}

void Circle::Draw(){
    std::cout << shapeName << " (" << center.x << ";" << center.y  << ") R" << radius << "\n";
};

void Circle::Move(double x, double y){
    //
    center.x += x;
    center.y += y;
};

bool Circle::IsBelong(Point coord){
    double distance = sqrt((coord.x -center.x) * (coord.x -center.x) + (coord.y -center.y) * (coord.y -center.y));
    return (distance <= radius);
};

void Circle::Zoom(double scale){
    //...
}

void Circle::Load(std::istream& is)
{
   //...
   is >> center.x >> center.y  >> radius;
}

void Circle::Save (std::ostream& os)
{
   //...
   os << shapeName << " " << center.x << " " << center.y  << " " << radius << "\n";
}

void Circle::SetCenterPos(Point _center){
    center = _center;
};

void Circle::SetRadius(double _radius){
    radius = _radius;
};
