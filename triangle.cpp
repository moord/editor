#include "triangle.h"

static struct TriangleFactoryInit{
   TriangleFactoryInit(){
       shapeCreators[Triangle::shapeName] = Triangle::Create;  // автоматическое добавление функции создания класса линии
   }
} _lineCreator;

Triangle * Triangle::Create (){
    return new Triangle();
}

void Triangle::Draw(){
    std::cout << shapeName << " (" << coords[0].x << ";" << coords[0].y  << ") (" << coords[1].x << ";" << coords[1].y << ") (" << coords[2].x << ";" << coords[2].y <<")\n";
};

void Triangle::Move(double x, double y){
    //
    for (int i = 0; i < 3; ++i) {
        coords[i].x += x;
        coords[i].y += y;
    }
};

bool Triangle::IsBelong(Point p){
    double cond[3];
    cond[0] = (coords[0].x-p.x)*(coords[1].y-coords[0].y)-(coords[1].x-coords[0].x)*(coords[0].y-p.y);
    if( cond[0] == 0 ) return true;
    cond[1] = (coords[1].x-p.x)*(coords[2].y-coords[1].y)-(coords[2].x-coords[1].x)*(coords[1].y-p.y);
    if( cond[1]  == 0) return true;
    cond[2] = (coords[2].x-p.x)*(coords[0].y-coords[2].y)-(coords[0].x-coords[2].x)*(coords[2].y-p.y);
    if( cond[2] == 0) return true;
    return ( cond[0] > 0 && cond[1] > 0 &&  cond[2] > 0 ) || ( cond[0] < 0 && cond[1] < 0 &&  cond[2] < 0 );
};

void Triangle::Zoom(double scale){
    //...
}

void Triangle::Load(std::istream& is)
{
    //...
    for (int i = 0; i < 3; ++i) {
        is >> coords[i].x >> coords[i].y;
    }
}

void Triangle::Save (std::ostream& os)
{
   //...
   os << shapeName;
   for (int i = 0; i < 3; ++i) {
       os << " " << coords[i].x  << " " <<  coords[i].y;
   }
   os << "\n";
}

void Triangle::SetFirstPos(Point coord){
    coords[0] = coord;
};

void Triangle::SetSecondPos(Point coord){
    coords[1] = coord;
};

void Triangle::SetThirdPos(Point coord){
    coords[2] = coord;
};

