#pragma once
class Vector
{
private:
    int x;
    int y;
    /* data */
public:
Vector(){     // metodos con el mismo nombre y diferente firma sobre carga de funciones
    this->x =0;
    this->y =0;
}
    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }
    ~Vector() {}
    int ObtenerX(){
        return this->x;
    }
    int ObtenerY(){
        return this->y;
    }
};