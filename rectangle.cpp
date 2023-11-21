#include "rectangle.h"

static struct RectangleFactoryInit{
   RectangleFactoryInit(){
       shapeCreators[Rectangle::shapeName] = Rectangle::Create;
   }
} _RectangleCreator;


Rectangle * Rectangle::Create (){
    return new Rectangle();
}

void Rectangle::Draw(){
    // std::cout
    std::cout << shapeName << " (" << start.x << ";" << start.y  << ") (" << end.x << ";" << start.y << ") (" << end.x << ";" << end.y << ") (" << start.x << ";" << end.y <<")\n";
};

bool Rectangle::IsBelong(Point coord){
    return coord.x >= start.x && coord.x <= end.x && coord.y >= start.y && coord.y <= end.y;
}; // Сдвинуть фигуру

void Rectangle::Save(std::ostream& os)
{
   os << shapeName << " " << start.x << " " << start.y  << " " << end.x << " " << end.y << "\n";
}
