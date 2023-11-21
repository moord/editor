#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <functional>
#include <map>

// Класс координата
struct Point{
    double x, y;
    bool operator == (const Point & other){
        return (x == other.x && y == other.y);
    }
};

// Базовый класс Фигура
// для него заданы методы, реализация которых
// отложена для выведенных классов
class Shape
{
public:
    virtual ~Shape() { }

    virtual void Draw() = 0; // Перерисовать фигуру
    virtual void Move(double x, double y) = 0; // Сдвинуть фигуру
    virtual void Zoom(double scale) = 0; // Реализация операции масштабирования
    virtual bool IsBelong(Point coord) = 0; // Проверка принадлежности точки к фигуре

    virtual void Load( std::istream& s)  = 0; // Загрузить
    virtual void Save( std::ostream& s)  = 0; // Сохранить

    static Shape * Unserialize( std::istream& s );  // фабричная  функция для создания фигур различных типов
    static Shape * Create ();
};

using ShapeFactory = Shape *();

// контейнер содержит строковые идентификаторы фигур и соответствующие функции для их создания
// в каждый cpp файл с реализацией граф примитива наследника добавляется статитческий объект добавляющий 
// в контейнер идентификатор и функцию создания
static std::map<std::string,std::function<ShapeFactory>> shapeCreators{{"null", Shape::Create}};

#endif // SHAPE_H
