#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <sstream>

using type_handle = void *;

// Базовый класс Хранилище
// для него заданы методы, реализация которых
// отложена для выведенных классов
class Storage{
public:

    virtual int GetShapeCount()=0;                                // Считать количество фигур
    virtual void SetShapeCount( int)=0;                           // Задать количество фигур

    virtual std::istream & GetNextShape()=0;                      // Получить следующую фигуру
    virtual void SaveNextShape( std::istream & )=0;               // Сохранить фигуру

protected:
    type_handle handle;
    virtual void Open(const std::string& filename)=0;             // Открыть файл для чтения/записи
    virtual void Close()=0;                                       // Закрыть
};

// Пример реализации класса для хранения списка фигур
class MyStorage: public Storage{
public:
    MyStorage( const std::string &filename ){
        Open( filename);
    };

    ~MyStorage( ){
        Close();
    };

    int GetShapeCount(){
        int size;
        // ...
        return size;
    };
    void SetShapeCount( int size){
        std::cout << "shapes: " << size  << "\n";
    };

    std::istream & GetNextShape(){
        // ...
        return ss;
    };

    void SaveNextShape( std::istream & from){
        //..
        std::cout << from.rdbuf();
    };

protected:
    std::stringstream ss;

    void Open(const std::string& filename){
        //..
        std::cout << "=== start save to " << filename << " ===\n";
    };
    void Close(){
        //..
        std::cout << "=== end save ===\n";
    };
};

#endif // STORAGE_H
