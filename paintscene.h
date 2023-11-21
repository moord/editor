#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include "shape.h"
#include "storage.h"

#include <optional>
#include <memory>
#include <vector>

enum FigureTypes {
    LINE,
    RECTAGLE,
    CIRCLE,
    TRIANGLE
};

// Класс хранилище для работы с векторыными примитивами
class PaintScene
{
public:
    PaintScene();

    bool Select(Point coord);                                      // выбрать фигуру по координатам

    bool AddShape(FigureTypes type, std::vector<Point> coords );   // добавить фигуру
    void DelShape();                                               // удалить раннее выбранную фигуру
    void MoveShape(double x, double y);                            // передвинуть ранее выбранную фигуру
    void Zoom( double scale);                                      // изменить масштаб

    void Import( Storage & );                                      // Импортировать коллекцию фигур из внешнего источника
    void Export( Storage & );                                      // Экспортировать коллекцию фигур во внешний источник

    void Repaint();
private:
    std::vector<std::shared_ptr<Shape> > shapes;                   // список фигур
    std::optional<int> selected;                                   // выбранная фигура (индекс в списке shapes)

};
#endif // PAINTSCENE_H
