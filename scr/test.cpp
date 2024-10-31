#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main() {
    std::string reset_position;
    auto can = Canvas(200, 100);
    int x_offset =0;
    int velocidad =2;

    /* //Cuerpo del carro
    can.DrawPointLine(30, 40, 170, 40, Color::Blue); // Línea superior
    can.DrawPointLine(30, 60, 170, 60, Color::Blue); // Línea inferior
    for (int x = 30; x <= 170; x++) {
        can.DrawPointLine(x, 40, x, 60, Color::Blue); // relleno de carrito
    }

    // Techo del carro
    can.DrawPointLine(60, 20, 140, 20, Color::Blue); // Línea superior
    can.DrawPointLine(60, 40, 140, 40, Color::Blue); // Línea inferior
    for (int x = 60; x <= 140; x++) {
        can.DrawPointLine(x, 20, x, 40, Color::Blue); // Paredes del techo
    }

    // Ventanas del carro
    can.DrawPointLine(70, 25, 90, 25, Color::Cyan); // Línea superior ventana izquierda
    can.DrawPointLine(70, 35, 90, 35, Color::Cyan); // Línea inferior ventana izquierda
    for (int x = 70; x <= 90; x++) {
        can.DrawPointLine(x, 25, x, 35, Color::Cyan); // Ventana izquierda
    }

    can.DrawPointLine(110, 25, 130, 25, Color::Red); // Línea superior ventana derecha
    can.DrawPointLine(110, 35, 130, 35, Color::Red); // Línea inferior ventana derecha
    for (int x = 110; x <= 130; x++) {
        can.DrawPointLine(x, 25, x, 35, Color::Red); // Ventana derecha
    }

    // Rueda izquierda
    can.DrawPointCircle(50, 70, 10, Color::Black);
    can.DrawPointCircle(50, 70, 5, Color::GrayDark);

    // Rueda derecha
    can.DrawPointCircle(150, 70, 10, Color::Black);
    can.DrawPointCircle(150, 70, 5, Color::GrayDark);*/

    while (true) {
        // Simular limpieza rellenando el fondo
        for (int y = 0; y < 100; y++) {
            for (int x = 0; x < 200; x++) {
                can.DrawPoint(x, y, Color::Black); // Fondo negro para "limpiar"
            }
        }

        //Cuerpo del carrito
        can.DrawPointLine(30 + x_offset, 40, 170 + x_offset, 40, Color::Blue);
        can.DrawPointLine(30 + x_offset, 60, 170 + x_offset, 60, Color::Blue);
        for (int x = 30 + x_offset; x <= 170 + x_offset; x++)     
        {
            can.DrawPointLine(x, 40, x, 60, Color::Violet);
        }

        can.DrawPointLine(60 + x_offset, 20, 140 +x_offset, 20, Color::Violet);
        can.DrawPointLine(60 + x_offset, 40, 140+x_offset, 40, Color::Violet);
        for (int x = 60+ x_offset; x <=140 + x_offset; x++)
        {
            can.DrawPointLine(x, 20, x, 40, Color::Violet);
        }

        can.DrawPointLine(70+ x_offset, 25, 90 + x_offset, 25, Color::BlueViolet);
        can.DrawPointLine(70+ x_offset, 35, 90 + x_offset, 35, Color::BlueViolet);
        for (int x = 70 + x_offset; x <=90 +x_offset; x++)
        {
            can.DrawPointLine(x, 25, x, 35, Color::BlueViolet);
        }
        can.DrawPointLine(110+ x_offset, 25, 130 + x_offset, 25, Color::DeepPink4Bis);
        can.DrawPointLine(110+ x_offset, 35, 130 + x_offset, 35, Color::DeepPink4Bis);
        for (int x = 110 + x_offset; x <=130+ x_offset; x++)
        {
            can.DrawPointLine(x, 25, x, 35, Color::DeepPink4Bis);
        }

        can.DrawPointCircle(50 +x_offset, 70, 10, Color::Aquamarine1Bis);
        can.DrawPointCircle(50 + x_offset, 70, 5, Color::Black);

        can.DrawPointCircle(150 +x_offset, 70, 10, Color::Aquamarine1Bis);
        can.DrawPointCircle(150 + x_offset, 70, 5, Color::Black);
        
        
        //Dibujar en terminal
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::YellowLight, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);

        x_offset += velocidad;
        if (x_offset > 200)
        {
            x_offset =-170; // regresar al inicio
        }
        
        std::this_thread::sleep_for(0.1s);
    }
    return 0;
}
