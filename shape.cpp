#include "shape.h"

// фабричная функция
Shape * Shape::Unserialize( std::istream& is ){
    std::string shapeType;

    is >> shapeType;

    if( shapeCreators.count(shapeType) != 0){
        Shape * p = shapeCreators[shapeType]();       // создаем
        p->Load(is);
        return p;
    } else{
        return shapeCreators["null"]();
    }
}

Shape * Shape::Create (){
    return nullptr;
};

