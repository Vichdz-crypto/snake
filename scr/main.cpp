#include <SerieNavidad.hpp>
#include <Lienzo.hpp>
#include <Vector.hpp>
#include<unistd.h> // Para comunicarte con el sistema operativo comunicacion con windows WINH
int main(int argc, char const *argv[])
{
    /*SerieNavidad serie(10);
    serie.Imprimir();
    serie.Encender();
    serie.Imprimir();
    serie.Apagar();
    serie.Apagar();
    serie.Alternar(true);
    serie.Imprimir();
    serie.Alternar(false);
    serie.Imprimir();*/

    Vector p(0,5);
    Vector t(100,100);
    Lienzo lienzo(p,t);
    SerieNavidad serie1(30);
    SerieNavidad serie2(10);
    
    bool estado=true;
    while(true){

        //serie que alterna
        serie1.Alternar(estado);
        lienzo.Dibujar(serie1);
        //serie.Imprimir();
        estado =estado ? false: true;

        //incremento
        serie2.Apagar();
        serie2.Encender(5);
        lienzo.Dibujar(serie2);
        sleep(1);
        lienzo.Limpiar();
    }
    return 0;
}
