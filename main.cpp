#include <iostream>

#include "paintscene.h"
#include "storage.h"

std::shared_ptr<PaintScene> scene;

void UserNewScene(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    scene.reset(new PaintScene);
}

void UserImportFromMyStorage(const std::string filename ){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    try{
        scene.reset(new PaintScene);
        MyStorage storage(filename);
        scene->Import(storage);

    } catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }
}

void UserExportToMyStorage(const std::string filename ){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    try{
        MyStorage storage(filename);
        scene->Export(storage);
    } catch(const std::exception &e){
        std::cerr << e.what() << "\n";
    }
}

void UserAddLine(Point start, Point end){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if( !scene->AddShape(FigureTypes::LINE, {start,end})){
        std::cerr << "line add error\n";
    }
}

void UserAddRectagle(Point left_up, Point right_down){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if( !scene->AddShape(FigureTypes::RECTAGLE, {left_up,right_down})){
        std::cerr << "rectagle add error\n";
    }
}

void UserAddCircle(Point center, Point outer){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if( !scene->AddShape(FigureTypes::CIRCLE, {center,outer})){
        std::cerr << "circle add error\n";
    }
}

void UserAddTriangle(Point p1, Point p2, Point p3){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if( !scene->AddShape(FigureTypes::TRIANGLE, {p1,p2,p3})){
        std::cerr << "triangle add error\n";
    }
}

void UserDeleteShapeUnderCursor(Point cursor_coord){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if( scene->Select(cursor_coord)){
        scene->DelShape();
    }
}

void UserDeleteLastShape(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    scene->DelShape();
}


int main() {
    UserNewScene();

    UserAddRectagle({2,3},{8,7});
    UserAddCircle({50,50}, {60,50});
    UserAddLine({0,0},{10,0});

    UserDeleteShapeUnderCursor({5,5});

    UserExportToMyStorage("graph.graph");

    UserNewScene();

    UserAddTriangle({1,1},{1,10}, {10,1});

    UserDeleteLastShape();

    return 0;
}
