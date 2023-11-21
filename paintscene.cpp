#include "paintscene.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

PaintScene::PaintScene()
{
    Repaint();
}

bool PaintScene::Select(Point coord){
    selected.reset();
    for (int i = 0; i < shapes.size(); ++i) {
        if( shapes[i] != nullptr){
            if( shapes[i]->IsBelong(coord)){
                selected = i;
                return true;
            }
        }
    }
    return false;
}

bool PaintScene::AddShape(FigureTypes type, std::vector<Point> coords ){
    Shape * item = nullptr;

    switch (type) {
    case  FigureTypes::LINE:
        if(coords.size() == 2){
            item = new Line(coords[0],coords[1]);
        }
        break;
    case  FigureTypes::RECTAGLE:
        if(coords.size() == 2){
            item = new Rectangle(coords[0],coords[1]);
        }
        break;
    case  FigureTypes::CIRCLE:
        if(coords.size() == 2){
            item = new Circle(coords[0],coords[1]);
        }
        break;
    case  FigureTypes::TRIANGLE:
        if(coords.size() == 3){
            item = new Triangle(coords[0],coords[1], coords[2]);
        }
        break;
    default:
        break;
    }

    if(item != nullptr){
        shapes.emplace_back(item);
        selected = shapes.size()-1;
        Repaint();
        return true;
    } else{
        return false;
    }
}

void PaintScene::DelShape(){
    if( selected ){
        shapes.erase(shapes.begin() + selected.value());
        selected.reset();
        Repaint();
    }
}

void PaintScene::MoveShape(double x, double y){
    if( selected ){
        shapes[selected.value()]->Move(x,y);
        Repaint();
    }
};

void PaintScene::Zoom( double scale){
    for (int i = 0; i < shapes.size(); ++i) {
        shapes[i]->Zoom(scale);
    }
    Repaint();
};

void PaintScene::Import( Storage &importer){
    int size = importer.GetShapeCount();
    while(size--){
        shapes.emplace_back(Shape::Unserialize(importer.GetNextShape()));
    }
    Repaint();
};

void PaintScene::Export( Storage &exporter){
    exporter.SetShapeCount(shapes.size());
    for( const auto &shape : shapes){
        std::stringstream ss;
        shape->Save(ss);
        exporter.SaveNextShape(ss);
    }
};

void PaintScene::Repaint(){
    // ClearScene();
    std::cout << "Repaint scene: total shapes " << shapes.size() << "\n";
    for (int i = 0; i < shapes.size(); ++i) {
        if( shapes[i] != nullptr){
            shapes[i]->Draw();
        }
    }
};
