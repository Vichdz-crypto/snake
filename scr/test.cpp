#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    auto can = Canvas(200,200);
    can.DrawPointCircle(100,50,30);
    can.DrawPointCircle(85,50,5);
    can.DrawPointCircle(115,50,5);
    can.DrawPointLine(95,72,107,72);
    can.DrawPointLine(95,80,105,80);
    can.DrawPointLine(95,90,95,80);
    can.DrawPointLine(105,90,105,80);
    can.DrawPointCircleFilled(85,50,1);
    can.DrawPointCircleFilled(115,50,1);
    can.DrawPointLine(75,95,95,80);
    
  //  can.DrawPointLine(0,0,300,50);
    /*auto ColorSupport = vbox({
                            Terminal::ColorSupport() >= Terminal::Color::Palette16
                                ? text(" 16 color palette support : Yes")
                                : text(" 16 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::Palette256
                                ? text("256 color palette support : Yes")
                                : text("256 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::TrueColor
                                ? text("       True color support : Yes")
                                : text("       True color support : No"),
                        });*/
    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
//       Element personaje = spinner(21, frame);
        Element lienzo = bgcolor(Color::Violet, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}