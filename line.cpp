#include "line.h"

static struct LineFactoryInit{
   LineFactoryInit(){
       shapeCreators[Line::shapeName] = Line::Create;  // автоматическое добавление функции создания класса линии
   }
} _lineCreator;

Line * Line::Create (){
    return new Line();
}

void Line::Draw(){
    std::cout << shapeName << " (" << start.x << ";" << start.y  << ") (" << end.x << ";" << end.y << ")\n";
};

void Line::Move(double x, double y){
    //
    start.x += x;
    start.y += y;

    end.x += x;
    end.y += y;
};

bool Line::IsBelong(Point coord){
    return coord == start || coord == end;
};

void Line::Zoom(double scale){
    //...
}

void Line::Load(std::istream& is)
{
   //...
   is >> start.x >> start.y  >> end.x >> end.y;
}

void Line::Save (std::ostream& os)
{
   //...
   os << shapeName << " " << start.x << " " << start.y  << " " << end.x << " " << end.y << "\n";
}

void Line::SetStartPos(Point _start){
    start = _start;
};

void Line::SetEndPos(Point _end){
    end = _end;
};
